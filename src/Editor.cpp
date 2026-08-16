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

#include "Editor.h"
#include "PageWidgets/GfEditor.h"
#include "PageWidgets/PersoEditor.h"
#include "PageWidgets/ItemEditor.h"
#include "PageWidgets/TTriadEditor.h"
#include "PageWidgets/CWEditor.h"
#include "PageWidgets/MiscEditor.h"
#include "PageWidgets/ConfigEditor.h"
#include "PageWidgets/AllEditor.h"
#include "PageWidgets/DrawPointEditor.h"
#include "PageWidgets/BattleEditor.h"
#include "PageWidgets/ShopEditor.h"
#include "PageWidgets/WorldmapEditor.h"
#include "PageWidgets/FieldEditor.h"
#include "PageWidgets/PartyEditor.h"
#include "PageWidgets/PreviewEditor.h"

Editor::Editor(QWidget *parent) :
	QWidget(parent)
{
	const bool compact = Config::compactMode();

	QFont font;
	font.setPointSize(compact ? Config::compactFontSize() - 1 : 9);

	liste = new QListWidget(this);
	liste->setFont(font);
	liste->setUniformItemSizes(true);
	// The page names have to stay readable when the font is turned up
	liste->setFixedWidth(compact ? qMax(72, Config::compactFontSize() * 9) : 96);
	liste->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	QPushButton *apply = new QPushButton(tr("&OK"), this);
	apply->setDefault(true);

	// Set default icon if needed
	QStyle *style = this->style();
	if (style->styleHint(QStyle::SH_DialogButtonBox_ButtonsHaveIcons))
		apply->setIcon(style->standardIcon(QStyle::SP_DialogOkButton, 0, this));
	if (style != QApplication::style()) // Propagate style
		apply->setStyle(style);


	QPushButton *cancel = new QPushButton(tr("&Cancel"), this);
	
	// Set default icon if needed
	if (style->styleHint(QStyle::SH_DialogButtonBox_ButtonsHaveIcons))
		cancel->setIcon(style->standardIcon(QStyle::SP_DialogCancelButton, 0, this));
	if (style != QApplication::style()) // Propagate style
		cancel->setStyle(style);

	stackedLayout = new QStackedLayout;

	QGridLayout *gridLayout = new QGridLayout(this);
	if (compact) {
		// One button row under the page list, the pages need every pixel
		QHBoxLayout *buttonsLayout = new QHBoxLayout;
		buttonsLayout->setContentsMargins(0, 0, 0, 0);
		buttonsLayout->addWidget(apply);
		buttonsLayout->addWidget(cancel);
		gridLayout->addWidget(liste, 0, 0);
		gridLayout->addLayout(buttonsLayout, 1, 0);
		gridLayout->addLayout(stackedLayout, 0, 1, 2, 1);
		gridLayout->setContentsMargins(QMargins(2, 2, 2, 2));
		gridLayout->setSpacing(2);
	} else {
		gridLayout->addWidget(liste, 0, 0);
		gridLayout->addWidget(apply, 1, 0);
		gridLayout->addWidget(cancel, 2, 0);
		gridLayout->addLayout(stackedLayout, 0, 1, 3, 1);
		gridLayout->setContentsMargins(QMargins(gridLayout->verticalSpacing(),gridLayout->verticalSpacing(),gridLayout->verticalSpacing(),gridLayout->verticalSpacing()));
	}

	addPage(new GfEditor(this));
	addPage(new PersoEditor(this));
	addPage(new ItemEditor(this));
	addPage(new ShopEditor(this));
	addPage(new TTriadEditor(this));
	addPage(new DrawPointEditor(this));
	addPage(new BattleEditor(this));
	addPage(new FieldEditor(this));
	addPage(new WorldmapEditor(this));
	addPage(new CWEditor(this));
	addPage(new PartyEditor(this));
	addPage(new MiscEditor(this));
	addPage(new ConfigEditor(this));
	addPage(new PreviewEditor(this));
	addPage(new AllEditor(this));

	for (PageWidget *page : std::as_const(pages))
		liste->addItem(page->name());

	liste->item(liste->count()-1)->setHidden(!Config::mode());
	
	connect(liste, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
	        SLOT(setCurrentSection(QListWidgetItem*,QListWidgetItem*)));
	connect(apply, SIGNAL(released()), SLOT(save()));
	connect(cancel, SIGNAL(released()), SIGNAL(rejected()));
}

void Editor::addPage(PageWidget *page)
{
	pages.append(page);

	if (Config::compactMode()) {
		// Pages are designed for a 768x502 window, let them scroll instead
		QScrollArea *scrollArea = new QScrollArea(this);
		scrollArea->setFrameShape(QFrame::NoFrame);
		scrollArea->setWidgetResizable(true);
		scrollArea->setWidget(page);
		stackedLayout->addWidget(scrollArea);
	} else {
		stackedLayout->addWidget(page);
	}
}

void Editor::setInitialFocus()
{
	liste->setFocus();
}

void Editor::showPreviousPage()
{
	int row = liste->currentRow();

	do {
		row = row > 0 ? row - 1 : liste->count() - 1;
	} while (liste->item(row)->isHidden() && row != liste->currentRow());

	liste->setCurrentRow(row);
}

void Editor::showNextPage()
{
	int row = liste->currentRow();

	do {
		row = row < liste->count() - 1 ? row + 1 : 0;
	} while (liste->item(row)->isHidden() && row != liste->currentRow());

	liste->setCurrentRow(row);
}

void Editor::setCurrentSection(QListWidgetItem *current, QListWidgetItem *previous)
{
	PageWidget *pageWidget;

	if (current == nullptr) {
		liste->setCurrentRow(0);
		return;
	}

	if (previous != nullptr) {
		pageWidget = pages.at(liste->row(previous));
		if (pageWidget->isLoaded()) {
			pageWidget->savePage();
		}
	}

	int id = liste->currentRow();

	pageWidget = pages.at(id);
	if (!pageWidget->isLoaded()) {
		pageWidget->load(&saveDataCopy, pc);
	}
	// AllEditor exception
	if (id == liste->count()-1) {
		pageWidget->fillPage();
	}
	stackedLayout->setCurrentIndex(id);
}

void Editor::load(SaveData *saveData, bool pc)
{
	this->pc = pc;
	this->saveData = saveData;
	this->saveDataCopy = *saveData;

	for (PageWidget *pageWidget : std::as_const(pages)) {
		pageWidget->unload();
	}

	setCurrentSection(liste->currentItem());
}

void Editor::save()
{
	bool saveOneAtLeast = false;
	for (PageWidget *pageWidget : std::as_const(pages)) {
		if (pageWidget->isLoaded()) {
			pageWidget->savePage();
			saveOneAtLeast = true;
		}
	}

	if (saveOneAtLeast) {
		*saveData = saveDataCopy;
		saveData->updateDescData();
		saveData->setModified(true);
	}

	emit accepted();
}

void Editor::updateMode(bool mode)
{
	int lastRow = liste->count()-1;
	liste->item(lastRow)->setHidden(!mode);
	if (liste->currentRow()==lastRow && !mode) {
		liste->setCurrentRow(0);
	}

	for (PageWidget *pageWidget : std::as_const(pages)) {
		if (pageWidget->isBuilded()) {
			pageWidget->updateMode(mode);
			pageWidget->updateModeAfter(mode);
		}
	}
}

void Editor::updateTime()
{
	for (PageWidget *pageWidget : std::as_const(pages)) {
		if (pageWidget->isLoaded()) {
			pageWidget->updateTime();
		}
	}
}
