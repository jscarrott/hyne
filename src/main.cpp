/****************************************************************************
 ** Hyne Final Fantasy VIII Save Editor
 ** Copyright (C) 2009-2013 Arzel Jérôme <myst6re@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include <QApplication>
#include "Window.h"
#include "StartWidget.h"
#include "SavecardView.h"

// Only for static compilation
//Q_IMPORT_PLUGIN(qjpcodecs) // jp encoding

// Adapts the interface to a handheld: dialogs are kept inside the screen,
// which most of them are larger than, and the d-pad drives the whole
// interface, with up and down walking through the controls and left and
// right changing the value of the focused one.
class HandheldFilter : public QObject
{
public:
	explicit HandheldFilter(QObject *parent = nullptr) : QObject(parent) {}
protected:
	bool eventFilter(QObject *watched, QEvent *event) override
	{
		if (event->type() == QEvent::Show) {
			QDialog *dialog = qobject_cast<QDialog *>(watched);
			if (dialog != nullptr && dialog->isWindow()) {
				Config::fitToScreen(dialog);
			}
		} else if (event->type() == QEvent::KeyPress) {
			if (handleKey(static_cast<QKeyEvent *>(event))) {
				return true;
			}
		}

		return QObject::eventFilter(watched, event);
	}
private:
	// A spin box and an editable combo box put the focus on the line edit
	// they contain, the value is stepped on the widget owning it
	static QWidget *stepper(QWidget *widget)
	{
		for (QWidget *w = widget; w != nullptr; w = w->parentWidget()) {
			if (qobject_cast<QAbstractSpinBox *>(w) != nullptr
					|| qobject_cast<QComboBox *>(w) != nullptr) {
				return w;
			}
			if (w->isWindow()) {
				break;
			}
		}

		return nullptr;
	}

	// Sends a key the application filter must not translate again
	void sendKey(QWidget *widget, Qt::Key key, Qt::KeyboardModifiers modifiers)
	{
		QKeyEvent event(QEvent::KeyPress, key, modifiers);

		_synthetic = true;
		QApplication::sendEvent(widget, &event);
		_synthetic = false;
	}

	bool handleKey(QKeyEvent *event)
	{
		QWidget *focus = QApplication::focusWidget();

		if (_synthetic || focus == nullptr || event->modifiers() != Qt::NoModifier) {
			return false;
		}

		// Lists, trees and the widgets painting their own cursor use the
		// arrows themselves
		if (qobject_cast<QAbstractItemView *>(focus) != nullptr
				|| qobject_cast<StartWidget *>(focus) != nullptr
				|| qobject_cast<SavecardView *>(focus) != nullptr) {
			return false;
		}

		switch (event->key()) {
		case Qt::Key_Up:
		case Qt::Key_Down: {
			// Walk the focus chain, the scroll areas follow it on their own
			const bool next = event->key() == Qt::Key_Down;
			sendKey(focus, next ? Qt::Key_Tab : Qt::Key_Backtab,
					next ? Qt::NoModifier : Qt::ShiftModifier);
			return true;
		}
		case Qt::Key_Left:
		case Qt::Key_Right: {
			// Spin boxes and combo boxes step their value with up and down,
			// which the d-pad needs for navigation. Both hold their focus in
			// an inner line edit, so the value is stepped on the ancestor.
			QWidget *control = stepper(focus);
			if (control == nullptr) {
				return false;
			}
			sendKey(control, event->key() == Qt::Key_Right ? Qt::Key_Up : Qt::Key_Down,
					Qt::NoModifier);
			return true;
		}
		default:
			return false;
		}
	}

	bool _synthetic = false;
};

// Focus is the only thing telling where the d-pad will act, the default
// dotted rectangle is hard to see on a small screen
static const char *compactStyleSheet =
		"QLineEdit:focus, QAbstractSpinBox:focus, QComboBox:focus,"
		"QCheckBox:focus, QRadioButton:focus, QPushButton:focus,"
		"QTreeWidget:focus, QListWidget:focus, QTreeView:focus, QTableView:focus {"
		"    border: 2px solid palette(highlight);"
		"}";

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setWindowIcon(QIcon(":/images/Hyne.png"));

	Config::set();

	if (Config::compactMode()) {
		QFont font = app.font();
		font.setPointSize(8);
		app.setFont(font);
		app.setStyleSheet(QLatin1String(compactStyleSheet));
		app.installEventFilter(new HandheldFilter(&app));
	}

	QTranslator translator_qt, translator;
	QString lang = Config::value(Config::Lang),
			translationPath = Config::translationDir();
	QLocale locale = lang.isEmpty() ? QLocale::system() : QLocale(lang);

	if (translator_qt.load(locale, "qt", "_", translationPath)
	        || translator_qt.load(locale, "qt", "_", QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
		app.installTranslator(&translator_qt);
	}

	if (translator.load(locale, "hyne", "_", translationPath) || translator.load(locale, "hyne", "_")) {
		app.installTranslator(&translator);
	} else if (locale.language() != QLocale::English) {
		QLocale locale = Window::chooseLangDialog();
		QString lang = locale.bcp47Name();
		if (translator.load(locale, "hyne", "_", translationPath) || translator.load(locale, "hyne", "_")) {
			app.installTranslator(&translator);
			Config::setValue(Config::Lang, lang);
		} else {
			Config::setValue(Config::Lang, "en");
		}
	} else {
		Config::setValue(Config::Lang, "en");
	}
	Config::translator = &translator;

	Config::loadRecentFiles();

	Window window;
	window.show();
	// No window manager on a handheld, nothing else will activate it
	window.activateWindow();
	window.raise();

	if (argc > 1) {
		window.openFile(argv[1]);
	}

	return app.exec();
}
