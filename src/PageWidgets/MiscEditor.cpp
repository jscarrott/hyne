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

#include "MiscEditor.h"

MiscEditor::MiscEditor(QWidget *parent)
	: PageWidget(parent)
{
}

void MiscEditor::updateMode(bool mode)
{
	unknownE->setVisible(mode);
	lastFieldLabel->setVisible(mode);
	lastFieldE->setVisible(mode);
	currentFrameLabel->setVisible(mode);
	currentFrameE->setVisible(mode);
}

void MiscEditor::updateTime()
{
	timeE->setTime(data->misc2.game_time, saveData->freqValue());
	countdownE->setTime(data->misc2.countdown, saveData->freqValue());
}

void MiscEditor::buildWidget()
{
	QVBoxLayout *layout = new QVBoxLayout(this);

	tabWidget = new QTabWidget(this);
	tabWidget->addTab(buildPage1(), tr("Miscellaneous"));
	tabWidget->addTab(buildPage2(), tr("Tutorial"));

	layout->addWidget(tabWidget);
	layout->setContentsMargins(QMargins());
}

QWidget *MiscEditor::buildPage1()
{
	QWidget *ret = new QWidget(this);

	QGroupBox *statsE = new QGroupBox(tr("Statistics"), ret);
	
	argentE = new SpinBox32(statsE);

	timeE = new TimeWidget(statsE);
	countdownE = new TimeWidget(statsE);

	QHBoxLayout *argent_tempsL = new QHBoxLayout;
	argent_tempsL->addWidget(new QLabel(tr("Time:"), statsE));
	argent_tempsL->addWidget(timeE);
	argent_tempsL->addStretch();
	argent_tempsL->addWidget(new QLabel(tr("Countdown:"), statsE));
	argent_tempsL->addWidget(countdownE);
	
	stepsE = new SpinBox32(statsE);
	
	seedLvlE = new QSpinBox(statsE);
	seedLvlE->setRange(0, 31);
	connect(seedLvlE, SIGNAL(valueChanged(int)), SLOT(nivS(int)));
	seedExpE = new SpinBox16(statsE);
	connect(seedExpE, SIGNAL(valueChanged(int)), SLOT(expS(int)));

	testSeedE = new SpinBox8(statsE);
	lagunaGilsE = new SpinBox32(statsE);
	lastFieldE = new SpinBox16(statsE);
	currentFrameE = new SpinBox32(statsE);

	QGridLayout *statsL = new QGridLayout(statsE);
	statsL->addLayout(argent_tempsL, 0, 0, 1, 6);
	statsL->addWidget(new QLabel(tr("Gil:"),statsE), 1, 0);
	statsL->addWidget(argentE, 1, 1);
	statsL->addWidget(new QLabel(tr("Gil Laguna:"),statsE), 1, 2);
	statsL->addWidget(lagunaGilsE, 1, 3);
	statsL->addWidget(new QLabel(tr("Number of steps:"),statsE), 1, 4);
	statsL->addWidget(stepsE, 1, 5);
	statsL->addWidget(new QLabel(tr("Seed level:"),statsE), 2, 0);
	statsL->addWidget(seedLvlE, 2, 1);
	statsL->addWidget(new QLabel(tr("Seed EXP:"),statsE), 2, 2);
	statsL->addWidget(seedExpE, 2, 3);
	statsL->addWidget(new QLabel(tr("SeeD test level:"),statsE), 2, 4);
	statsL->addWidget(testSeedE, 2, 5);
	statsL->addWidget(lastFieldLabel = new QLabel(tr("Last visited field:"),statsE), 3, 0);
	statsL->addWidget(lastFieldE, 3, 1);
	statsL->addWidget(currentFrameLabel = new QLabel(tr("Current Movie Frame:"),statsE), 3, 2);
	statsL->addWidget(currentFrameE, 3, 3);

	unknownE = new QGroupBox(tr("Unknown"), ret);
	unknown1E = new SpinBox16(unknownE);
	unknown2E = new SpinBox16(unknownE);
	unknown4E = new SpinBox32(unknownE);
	unknown5E = new SpinBox16(unknownE);
	unknown6E = new SpinBox32(unknownE);
	unknown7E = new SpinBox32(unknownE);
	unknown8E = new SpinBox32(unknownE);
	unknown9E = new SpinBox32(unknownE);

	QGridLayout *unknownL = new QGridLayout(unknownE);
	unknownL->addWidget(new QLabel(tr("Unknown 1:"),unknownE), 0, 0);
	unknownL->addWidget(unknown1E, 0, 1);
	unknownL->addWidget(new QLabel(tr("Unknown 2:"),unknownE), 0, 2);
	unknownL->addWidget(unknown2E, 0, 3);
	unknownL->addWidget(new QLabel(tr("Unknown 3:"),unknownE), 0, 4);
	unknownL->addWidget(unknown4E, 0, 5);
	unknownL->addWidget(new QLabel(tr("Unknown 4:"),unknownE), 1, 0);
	unknownL->addWidget(unknown5E, 1, 1);
	unknownL->addWidget(new QLabel(tr("Unknown 5:"),unknownE), 1, 2);
	unknownL->addWidget(unknown6E, 1, 3);
	unknownL->addWidget(new QLabel(tr("Unknown 6:"),unknownE), 1, 4);
	unknownL->addWidget(unknown7E, 1, 5);
	unknownL->addWidget(new QLabel(tr("Unknown 7:"),unknownE), 2, 0);
	unknownL->addWidget(unknown8E, 2, 1);
	unknownL->addWidget(new QLabel(tr("Unknown 8:"),unknownE), 2, 2);
	unknownL->addWidget(unknown9E, 2, 3);
	
	QVBoxLayout *layout = new QVBoxLayout(ret);
	layout->addWidget(statsE);
	layout->addWidget(unknownE);
	layout->addStretch();

	return ret;
}

QWidget *MiscEditor::buildPage2()
{
	QWidget *ret = new QWidget(this);

	QFont font;
	font.setPointSize(10);

	tutoE_list = new QTreeWidget(ret);
	tutoE_list->setFont(font);
	tutoE_list->setHeaderLabel(tr("Category"));
	tutoE_list->setIndentation(0);
	tutoE_list->setUniformRowHeights(true);

	QStringList tutoStrings;
	tutoStrings
			<< tr("Location Name/Fire Cavern") << tr("Location Name/Dollet") << tr("Location Name/Timber")
			<< tr("Location Name/Timber TV Station") << tr("Location Name/Galbadia") << tr("Location Name/Tomb of the Unknown King")
			<< tr("Location Name/Winhill") << tr("Location Name/D-District Prison") << tr("Location Name/Missile Base")
			<< tr("Location Name/Horizon Bridge") << tr("Location Name/Fishermans Horizon") << tr("Location Name/Trabia")
			<< tr("Location Name/Esthar (1)") << tr("Location Name/Esthar (2)") << tr("Location Name/Esthar (3)")
			<< tr("Location Name/Seaside Station") << tr("Location Name/Great Salt Lake") << tr("Location Name/Moon")
			<< tr("Location Name/Deep Sea Research Center") << tr("Location Name/Deep Sea Deposit") << tr("Term/Time Compression")
			<< tr("Term/The truth about the Garden") << tr("Term/Radio Interference (1)") << tr("Term/Radio Interference (2)")
			<< tr("Term/Lunar Cry") << tr("Term/Centra Civilization") << tr("Term/Odine Items")
			<< tr("Term/Sorceress") << tr("Term/Sorceress Power & Embodiment") << tr("Term/Crystal Pillar")
			<< tr("Term/Lunatic Pandora") << tr("Term/Tears' Point") << tr("Term/Adel's Tomb")
			<< tr("Term/Spaceship Ragnarok") << tr("Term/MD Level") << tr("Term/Centra Shelter")
			<< tr("Term/Timber Maniacs") << tr("Term/Eyes On Me") << tr("Person/Dr. Odine")
			<< tr("Person/The Great Hyne") << tr("Person/White SeeD") << tr("Person/Moomba")
			<< tr("Person/Shumi Tribe") << tr("Person/Chocobo") << tr("Person/Mayor Dobe")
			<< tr("Zell") << tr("Quistis") << tr("Seifer")
			<< tr("Selphie") << tr("Rinoa") << tr("Irvine")
			<< tr("Edea") << tr("Laguna") << tr("Kiros")
			<< tr("Ward") << tr("Rinoa 2 (Angelo wing)") << tr("Unused")
			<< tr("Unused") << tr("Term/Succession of Sorceress Power") << tr("Battle Report")
			<< tr("Character Report") << tr("GF Report") << tr("Online Help/GF Junction")
			<< tr("Online Help/Magic Junction") << tr("Online Help/Junction to Elements") << tr("Online Help/Junction of Status")
			<< tr("Online Help/GF Tutorial") << tr("Online Help/Squall's Status Screen") << tr("Online Help/Zell's Status Screen")
			<< tr("Online Help/Rinoa's Status Screen") << tr("Online Help/Switch") << tr("Unused")
			<< tr("MiniMog") << tr("GF Report/Quezacotl") << tr("GF Report/Shiva")
			<< tr("GF Report/Ifrit") << tr("GF Report/Siren") << tr("GF Report/Brothers")
			<< tr("GF Report/Diablos") << tr("GF Report/Carbuncle") << tr("GF Report/Leviathan")
			<< tr("GF Report/Pandemona") << tr("GF Report/Cerberus") << tr("GF Report/Alexander")
			<< tr("GF Report/Doomtrain") << tr("GF Report/Bahamut") << tr("GF Report/Cactuar")
			<< tr("GF Report/Tonberry") << tr("GF Report/Eden") << tr("T Mag-RF")
			<< tr("T Mag-RF 2") << tr("I Mag-RF") << tr("I Mag-RF 2")
			<< tr("F Mag-RF") << tr("F Mag-RF 2") << tr("L Mag-RF")
			<< tr("L Mag-RF 2") << tr("Time Mag-RF") << tr("Time Mag-RF 2")
			<< tr("ST Mag-RF") << tr("ST Mag-RF 2") << tr("Supt Mag-RF")
			<< tr("Supt Mag-RF 2") << tr("Forbid Mag-RF") << tr("Forbid Mag-RF 2")
			<< tr("Recov Med-RF") << tr("Recov Med-RF 2") << tr("ST Med-RF")
			<< tr("ST Med-RF 2") << tr("Ammo-RF") << tr("Ammo-RF 2")
			<< tr("Tool-RF") << tr("Tool-RF 2") << tr("Forbid Med-RF")
			<< tr("Forbid Med-RF 2") << tr("GFRecov Med-RF") << tr("GFRecov Med-RF 2")
			<< tr("GFAbl Med-RF") << tr("GFAbl Med-RF 2") << tr("Mid Mag-RF")
			<< tr("Mid Mag-RF 2") << tr("Med LV Up") << tr("Med LV Up 2")
			<< tr("Ribbon") << tr("High Mag-RF") << tr("High Mag-RF 2")
			<< tr("Unused") << tr("Proof of Omega");

	for (const QString &tutoString : std::as_const(tutoStrings)) {
		QTreeWidgetItem *item = new QTreeWidgetItem(QStringList(tutoString));
		item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
		tutoE_list->addTopLevelItem(item);
	}

	QCheckBox *tutoCheckAll = new QCheckBox(tr("Select all"), ret);
	connect(tutoCheckAll, SIGNAL(toggled(bool)), SLOT(selectAll(bool)));

	font.setPixelSize(10);
	tutoCheckAll->setFont(font);

	QGridLayout *layout = new QGridLayout(ret);
	layout->addWidget(tutoE_list, 0, 0);
	layout->addWidget(tutoCheckAll, 1, 0, Qt::AlignLeft);

	return ret;
}

void MiscEditor::fillPage()
{
	argentE->setValue(data->misc1.gils);
	lagunaGilsE->setValue(data->misc1.dream_gils);
	seedExpE->setValue(data->misc3.seedExp);
	
	stepsE->setValue(data->misc3.steps);

	testSeedE->setValue(data->misc2.testLevel);
	lastFieldE->setValue(data->misc3.last_field_id);
	currentFrameE->setValue(data->misc3.current_frame);

	unknown1E->setValue(data->misc1.u1);
	unknown2E->setValue(data->misc1.u2);
	unknown4E->setValue(data->misc2.u1);
	unknown5E->setValue(data->misc2.u2);
	unknown6E->setValue(data->misc2.u5);
	unknown7E->setValue(data->misc3.u7);
	unknown8E->setValue(data->misc3.music_related);
	unknown9E->setValue(data->misc3.u8);

	int i, j;
	for (i = 0; i < 16; ++i) {
		for (j = 0; j < 8; ++j) {
			tutoE_list->topLevelItem(i*8+j)
					->setCheckState(0, ((data->misc2.tutorial_infos[i]>>j) & 1) ? Qt::Checked : Qt::Unchecked);
		}
	}
}

void MiscEditor::savePage()
{
	data->misc1.gils = argentE->value();
	data->misc3.gils = argentE->value();
	data->misc1.dream_gils = lagunaGilsE->value();
	data->misc3.dream_gils = lagunaGilsE->value();
	data->misc2.game_time = timeE->time(saveData->freqValue());
	data->misc2.countdown = countdownE->time(saveData->freqValue());

	data->misc3.seedExp = seedExpE->value();
	
	data->misc3.steps = stepsE->value();

	data->misc2.testLevel = testSeedE->value();
	data->misc3.last_field_id = lastFieldE->value();
	data->misc3.current_frame = currentFrameE->value();

	data->misc1.u1 = unknown1E->value();
	data->misc1.u2 = unknown2E->value();
	data->misc2.u1 = unknown4E->value();
	data->misc2.u2 = unknown5E->value();
	data->misc2.u5 = unknown6E->value();
	data->misc3.u7 = unknown7E->value();
	data->misc3.music_related = unknown8E->value();
	data->misc3.u8 = unknown9E->value();

	for (quint8 i = 0; i < 16; ++i) {
		quint8 curTutoInfo = 0;
		for (quint8 j = 0; j < 8; ++j) {
			curTutoInfo |= (tutoE_list->topLevelItem(i*8+j)->checkState(0) == Qt::Checked) << j;
		}
		data->misc2.tutorial_infos[i] = curTutoInfo;
	}
}

void MiscEditor::expS(int value)
{
	quint16 niv = value/100;
	if (seedLvlE->value() != niv)
	{
		seedLvlE->setValue(niv);
	}
}

void MiscEditor::nivS(int value)
{
	quint16 exp = value*100;
	if (exp > seedExpE->value() || exp + 100 <= seedExpE->value())
	{
		seedExpE->setValue(exp);
	}
}

void MiscEditor::selectAll(bool selected)
{
	PageWidget::selectAll(tutoE_list, selected);
}
