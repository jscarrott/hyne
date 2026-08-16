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

// Only for static compilation
//Q_IMPORT_PLUGIN(qjpcodecs) // jp encoding

// Keeps dialogs inside the screen on handhelds, where most of them are
// larger than the 640x480 panel they are shown on
class CompactDialogFilter : public QObject
{
public:
	explicit CompactDialogFilter(QObject *parent = nullptr) : QObject(parent) {}
protected:
	bool eventFilter(QObject *watched, QEvent *event) override
	{
		if (event->type() == QEvent::Show) {
			QDialog *dialog = qobject_cast<QDialog *>(watched);
			if (dialog != nullptr && dialog->isWindow()) {
				Config::fitToScreen(dialog);
			}
		}

		return QObject::eventFilter(watched, event);
	}
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setWindowIcon(QIcon(":/images/Hyne.png"));

	Config::set();

	if (Config::compactMode()) {
		QFont font = app.font();
		font.setPointSize(8);
		app.setFont(font);
		app.installEventFilter(new CompactDialogFilter(&app));
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

	if (argc > 1) {
		window.openFile(argv[1]);
	}

	return app.exec();
}
