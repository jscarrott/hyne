/****************************************************************************
 ** Hyne Final Fantasy VIII Save Editor
 ** Copyright (C) 2013 Arzel Jérôme <myst6re@gmail.com>
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
#include "MetadataDialog.h"
#include "UserDirectory.h"

MetadataDialog::MetadataDialog(QWidget *parent) :
	QDialog(parent, Qt::Dialog | Qt::WindowCloseButtonHint)
{
	build();
}

MetadataDialog::MetadataDialog(const QMap<FF8Installation::Type, FF8Installation> &ff8Installations, QWidget *parent) :
	QDialog(parent, Qt::Dialog | Qt::WindowCloseButtonHint)
{
	build();
	fill(ff8Installations);
}

void MetadataDialog::build()
{
	HelpWidget *help = new HelpWidget(32, tr("To be placed in the cloud, "
											 "save files must be signed. "
											 "These signatures are written in a file "
											 "called metadata.xml, normally located "
											 "in the same folder as your save files.\n"
											 "To find your user number, "
											 "look at the name of the folder where your save files are. "
											 "If you do not find this folder, try leaving it blank.\n"
											 "By default Hyne attempts to automatically sign saves, "
											 "but in case of error, "
											 "you can try to do it manually here."));

	_path = new QLineEdit(this);
	_pathButton = new QPushButton(tr("Browse..."), this);

	QHBoxLayout *pathLayout = new QHBoxLayout;
	pathLayout->addWidget(_path);
	pathLayout->addWidget(_pathButton);
	pathLayout->setContentsMargins(QMargins());

	_userID = new QLineEdit(this);

	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
													   Qt::Horizontal, this);

	connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));

	_formWidget = new QWidget(this);

	QFormLayout *formLayout = new QFormLayout(_formWidget);
	formLayout->addRow(tr("metadata.xml"), pathLayout);
	formLayout->addRow(tr("User number"), _userID);
	formLayout->setContentsMargins(QMargins());

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(help);
	layout->addWidget(_formWidget);
	layout->addStretch();
	layout->addWidget(buttonBox);

	connect(_pathButton, SIGNAL(clicked()), SLOT(setMetadataPath()));
}

void MetadataDialog::fill(const QMap<FF8Installation::Type, FF8Installation> &ff8Installations)
{
	if (ff8Installations.contains(FF8Installation::Steam)) {
		FF8Installation installation = ff8Installations.value(FF8Installation::Steam);
		if (installation.hasMetadata()) {
			QString savePath = installation.savePath(1);
			_path->setText(QDir::toNativeSeparators(savePath + "/metadata.xml"));
			UserDirectory userDir(savePath);
			_userID->setText(userDir.userID());
		}
	}
}

void MetadataDialog::accept()
{
	UserDirectory userDir(metadataPath(), userID());
	if (!userDir.updateSignatures()) {
		QMessageBox::warning(this, tr("Error"), tr("Unable to update signatures.") +
													userDir.errorString());
	} else {
		QDialog::accept();
	}
}

void MetadataDialog::setMetadataPath(const QString &path)
{
	QString metadataPath;

	if (path.isNull()) {
		QStringList filter = QStringList()
				<< tr("XML files (*.xml)")
				<< tr("All files (*)");
		metadataPath = QFileDialog::getOpenFileName(this, tr("Search metadata.xml"), _path->text(), filter.join(";;"));
		if (metadataPath.isNull()) {
			return;
		}
	} else {
		metadataPath = path;
	}

	_path->setText(QDir::toNativeSeparators(metadataPath));
	if (_userID->text().isEmpty()) {
		UserDirectory userDir(metadataPath.left(metadataPath.lastIndexOf('/')));
		_userID->setText(userDir.userID());
	}
}
