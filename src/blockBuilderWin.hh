/*****************************************************************************/
/* blockBuilderWin.hh for blockBuilder                                       */
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
#ifndef BLOCKBUILDERWIN_HH_
#define BLOCKBUILDERWIN_HH_
#include <QMainWindow>

class ColorSelector;
class QLineEdit;
class QPushButton;
class QComboBox;

class BlockBuilderWin : public QMainWindow
{
	 Q_OBJECT
	 public:
	 BlockBuilderWin();
	 ~BlockBuilderWin();										 										 

public slots:
	 void buildImage();
	 void calcBlockSizeOptions();
	 
private:
	 ColorSelector * _startColor;
	 ColorSelector * _endColor;
	 QLineEdit * _hVariance;
	 QLineEdit * _vVariance;
	 QPushButton * _buildBtn;
	 QLineEdit * _heightEdit;
	 QLineEdit * _widthEdit;
	 QComboBox * _blockSizeCmb;
};

#endif//BLOCKBUILDERWIN_HH_
