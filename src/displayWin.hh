/*****************************************************************************/
/* displayWin.hh for blockBuilder                                            */
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
#ifndef DISPLAYWIN_HH_
#define DISPLAYWIN_HH_
#include <QMainWindow>
#include <QString>

class QLabel;

class DisplayWin : public QMainWindow
{
	 Q_OBJECT
	 public:
	 DisplayWin(QWidget * parent);

public slots:
	 void loadImage(const QString & imgPath);

protected slots:
	 void closeEvent(QCloseEvent * e);

	 private:
	 QLabel * _imgLbl;
};

#endif//DISPLAYWIN_HH_
