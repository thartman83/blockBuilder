/*****************************************************************************/
/* colorSelector.cc for blockBuilder                                         */
/* Copyright (c) 2011 Thomas Hartman (rokstar83@gmail.com)                   */
/*                                                                           */
/* This program is free software; you can redistribute it and/or             */
/* modify it under the terms of the GNU General Public License               */
/* as published by the Free Software Foundation; either version 2            */
/* of the License, or the License, or (at your option) any later             */
/* version.                                                                  */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/* GNU General Public License for more details.                              */
/*****************************************************************************/
#include "colorSelector.hh"
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QRegExpValidator>
#include <QColor>
#include <QColorDialog>
#include <QHBoxLayout>

ColorSelector::ColorSelector(QWidget * parent, const QColor & col) : 
	 QFrame(parent)
{
	 _lineEdit = new QLineEdit();

	 QString colorRegexp = "#[0-9a-fA-F]{6}";
	 QRegExpValidator * validator = new QRegExpValidator(QRegExp(colorRegexp),
																											 _lineEdit);
	 _lineEdit->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding,
																				QSizePolicy::MinimumExpanding));
	 _lineEdit->setValidator(validator);
	 _lineEdit->setAlignment(Qt::AlignRight);
	 _lineEdit->setText(col.name());

	 _selector = new QPushButton();
	 _selector->setText("...");
	 _selector->setMaximumHeight(30);
	 _selector->setMaximumWidth(30);

	 connect(_selector, SIGNAL(clicked(bool)),
					 this, SLOT(getColorByDialog()));

	 QHBoxLayout * hlayout = new QHBoxLayout(this);
	 hlayout->addWidget(_lineEdit);
	 hlayout->addWidget(_selector);

	 setLayout(hlayout);
}

ColorSelector::~ColorSelector()
{
}

void ColorSelector::getColorByDialog()
{
	 QColor col = QColorDialog::getColor(QColor(_lineEdit->text()));
	 _lineEdit->setText(col.name());
}
