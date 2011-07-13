/*****************************************************************************/
/* displayWin.cc for blockBuilder                                            */
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
#include "displayWin.hh"
#include <QPixmap>
#include <QLabel>
#include <QCloseEvent>

DisplayWin::DisplayWin(QWidget * parent) : QMainWindow(parent)
{
	 _imgLbl = new QLabel(this);
	 setCentralWidget(_imgLbl);
}

void DisplayWin::loadImage(const QString & imgPath)
{	 
	 QPixmap pix;

	 pix.load(imgPath);
	 _imgLbl->setPixmap(pix);	 
}

void DisplayWin::closeEvent(QCloseEvent * e)
{
	 hide();
	 e->ignore();
}
