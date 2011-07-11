/*****************************************************************************/
/* blockBuilder.hh for blockBuilder                                          */
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
#ifndef BLOCKBUILDER_HH_
#define BLOCKBUILDER_HH_
#include <QColor>
#include <QVector>

class BlockBuilder
{
	 public:
	 BlockBuilder(const QColor & startColor, const QColor & endColor,
								int hVariance, int vVariance);
	 ~BlockBuilder();

	 void buildImage();

private:
	 QColor _startColor;
	 QColor _endColor;
	 int _hVariance;
	 int _vVariance;
};

#endif//BLOCKBUILDER_HH_
