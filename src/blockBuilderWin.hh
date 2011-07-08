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

class QColorDialog;

class BlockBuilderWin : public QMainWindow
{
	 Q_OBJECT
	 public:
	 BlockBuilderWin();
	 ~BlockBuilderWin();
	 
private:
	 QColorDialog * _startingPicker;
	 QColorDialog * _endingPicker;
};

#endif//BLOCKBUILDERWIN_HH_