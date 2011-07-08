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
#include <QColorDialog>
#include <QVBoxLayout>
#include <QFrame>

BlockBuilderWin::BlockBuilderWin()
{	 	 
	 _startingPicker = new QColorDialog(this);
	 _endingPicker = new QColorDialog(this);

	 QVBoxLayout * layout = new QVBoxLayout(this);
	 layout->addWidget(_startingPicker);
	 layout->addWidget(_endingPicker);
	 QFrame * frm = new QFrame(this);

	 setCentralWidget(frm);
	 frm->setLayout(layout);	 
}

BlockBuilderWin::~BlockBuilderWin()
{	 
}
