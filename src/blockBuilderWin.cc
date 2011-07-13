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
#include "blockBuilder.hh"
#include "property.hh"
#include "constants.hh"
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRegExpValidator>
#include <QRegExp>
#include <QPushButton>
#include <QComboBox>
#include <QImage>

BlockBuilderWin::BlockBuilderWin()
{	 	 
	 QFrame * frm = new QFrame(this);
	 QVBoxLayout * vlayout = new QVBoxLayout(frm);
	 
	 /* Width */
	 _widthEdit = new QLineEdit();
	 _widthEdit->setText("1024");
	 _widthEdit->setValidator(new QRegExpValidator(RE_INT, _widthEdit));
	 Property * widthProperty = new Property("Width", _widthEdit);

	 /* Height */
	 _heightEdit = new QLineEdit();
	 _heightEdit->setText("768");
	 _heightEdit->setValidator(new QRegExpValidator(RE_INT, _heightEdit));
	 Property * heightProperty = new Property("Height", _heightEdit);

	 /* Block Size */
	 _blockSizeCmb = new QComboBox();
	 _blockSizeCmb->setInsertPolicy(QComboBox::NoInsert);	 
	 connect(_widthEdit, SIGNAL(editingFinished()), 
					 this, SLOT(calcBlockSizeOptions()));
	 connect(_heightEdit, SIGNAL(editingFinished()), 
					 this, SLOT(calcBlockSizeOptions()));
	 calcBlockSizeOptions();
	 Property * blockSizeProperty = new Property("Block Size", _blockSizeCmb);

	 /* Starting Color */
	 _startColor = new ColorSelector(NULL, QColor("#ffffff"));
	 QLabel * startLbl = new QLabel("Start Color");
	 Property * startColorProperty = new Property("Start Color", _startColor);

	 /* Ending Color */
	 _endColor = new ColorSelector(NULL, QColor("#ffffff"));
	 QLabel * endLbl = new QLabel("End Color");
	 Property * endColorProperty = new Property("End Color", _endColor);
	 
	 /* Horizontal Variance */
	 _hVariance = new QLineEdit();
	 _hVariance->setText("5");
	 _hVariance->setValidator(new QRegExpValidator(RE_FLOAT, _hVariance));
	 Property * hVarianceProperty = new Property("Horizontal Variance", _hVariance);

	 /* Vertical Variance */
	 _vVariance = new QLineEdit();
	 _vVariance->setText("5");
	 _vVariance->setValidator(new QRegExpValidator(RE_FLOAT, _vVariance));
	 Property * vVarianceProperty = new Property("Veritical Variance", _vVariance);

	 /* setup the build button */
	 _buildBtn = new QPushButton();
	 _buildBtn->setText("Build Image");
	 connect(_buildBtn, SIGNAL(clicked()), this, SLOT(buildImage()));

   /* Add all of the hlayouts to the vlayout */
	 vlayout->addLayout(widthProperty);
	 vlayout->addLayout(heightProperty);
	 vlayout->addLayout(blockSizeProperty);
	 vlayout->addLayout(startColorProperty);
	 vlayout->addLayout(endColorProperty);
	 vlayout->addLayout(hVarianceProperty);
	 vlayout->addLayout(vVarianceProperty);
	 vlayout->addWidget(_buildBtn);
	 
	 frm->setLayout(vlayout);
	 setCentralWidget(frm);
}

BlockBuilderWin::~BlockBuilderWin()
{	 
}

void BlockBuilderWin::buildImage()
{
	 BlockBuilder blockBuilder(_widthEdit->text().toInt(), 
														 _heightEdit->text().toInt(),
														 _blockSizeCmb->currentText().toInt(),
														 _startColor->color(), _endColor->color(),
														 _hVariance->text().toInt(), 
														 _vVariance->text().toInt());

	 QImage img = blockBuilder.buildImage();

	 img.save("tmp.bmp");
}

void BlockBuilderWin::calcBlockSizeOptions()
{
	 /* Find all common denominators for width and height */
	 int width = _widthEdit->text().toInt();
	 int height = _heightEdit->text().toInt();

	 _blockSizeCmb->clear();
	 for(int x = 2; x <= (height/2); ++x)
			if(height % x == 0 && width % x == 0)
				 _blockSizeCmb->addItem(QString("%1").arg(x));
}
