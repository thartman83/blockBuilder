/*****************************************************************************/
/* blockBuilderWin.cc for blockBuilder                                       */
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
#include "blockBuilderWin.hh"
#include "colorSelector.hh"
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRegExpValidator>
#include <QRegExp>

BlockBuilderWin::BlockBuilderWin()
{	 	 
	 QFrame * frm = new QFrame(this);
	 QVBoxLayout * vlayout = new QVBoxLayout(frm);

	 /* Starting Color */
	 _startColor = new ColorSelector(NULL, QColor("#ffffff"));
	 QLabel * startLbl = new QLabel("Start Color");

	 QHBoxLayout * startHLayout = new QHBoxLayout(frm);
	 startHLayout->addWidget(startLbl);
	 startHLayout->addWidget(_startColor);

	 /* Ending Color */
	 _endColor = new ColorSelector(NULL, QColor("#ffffff"));
	 QLabel * endLbl = new QLabel("End Color");
	 
	 QHBoxLayout * endHLayout = new QHBoxLayout(frm);
	 endHLayout->addWidget(endLbl);
	 endHLayout->addWidget(_endColor);

	 /* Horizontal Variance */
	 _hVariance = new QLineEdit();
	 _hVariance->setText("5");
	 _hVariance->setValidator(new QRegExpValidator(QRegExp("[0-9]+"), _hVariance));

	 QHBoxLayout * hVarLayout = new QHBoxLayout(frm);
	 hVarLayout->addWidget(new QLabel("Horizontal Variance"));
	 hVarLayout->addWidget(_hVariance);

	 /* Vertical Variance */
	 _vVariance = new QLineEdit();
	 _vVariance->setText("5");
	 _vVariance->setValidator(new QRegExpValidator(QRegExp("[0-9]+)"), _hVariance));

	 QHBoxLayout * vVarLayout = new QHBoxLayout(frm);
	 vVarLayout->addWidget(new QLabel("Vertical Variance"));
	 vVarLayout->addWidget(_vVariance);

   /* Add all of the hlayouts to the vlayout */
	 vlayout->addLayout(startHLayout);
	 vlayout->addLayout(endHLayout);
	 vlayout->addLayout(hVarLayout);
	 vlayout->addLayout(vVarLayout);
	 
	 frm->setLayout(vlayout);
	 setCentralWidget(frm);
}

BlockBuilderWin::~BlockBuilderWin()
{	 
}

