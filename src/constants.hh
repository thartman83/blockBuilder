/*****************************************************************************/
/* constants.hh for blockBuilder                                             */
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
#ifndef CONSTANTS_HH_
#define CONSTANTS_HH_
#include <QString>
#include <QRegExp>

const QRegExp RE_FLOAT("\\.[0-9]+");
const QRegExp RE_INT("[0-9]+");
const float HVARIANCE = .05;
const float VVARIANCE = .05;
const QColor START_COLOR = QColor("#000000");
const QColor END_COLOR = QColor("#ffffff");

#endif//CONSTANTS_HH_
