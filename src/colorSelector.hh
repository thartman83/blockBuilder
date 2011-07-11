/*****************************************************************************/
/* colorSelector.hh for blockBuilder                                         */
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
#ifndef _COLORSELECTOR_HH_
#define _COLORSELECTOR_HH_
#include <QFrame>

class QLineEdit;
class QPushButton;

class ColorSelector : public QFrame
{
	 Q_OBJECT
	 public:
	 ColorSelector(QWidget * parent = NULL, const QColor & col=QColor("#ffffff"));
	 ~ColorSelector();

	 QColor color();

public slots:
	 void getColorByDialog();

signals:
	 void colorChanged(const QColor & color);

private:
	 QLineEdit * _lineEdit;
	 QPushButton * _selector;
};

#endif//_COLORSELECTOR_HH_
