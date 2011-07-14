/*****************************************************************************/
/* blockBuilder.cc for blockBuilder                                          */
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
#include "blockBuilder.hh"
#include <math.h>
#include <QtGlobal>
#include <QTime>

BlockBuilder::BlockBuilder(int width, int height, int blockSize, 
													 const QColor & startColor, const QColor & endColor, 
													 int hVariance, int vVariance) :
	 _width(width), _height(height), _blockSize(blockSize), 
	 _startColor(startColor), _endColor(endColor), _hVariance(hVariance), 
	 _vVariance(vVariance)
{
}

BlockBuilder::~BlockBuilder()
{}

QImage BlockBuilder::buildImage()
{
	 qsrand(QTime(0,0,0,0).msecsTo(QTime::currentTime()));
	 int numBlocks = (_height/_blockSize) * (_width/_blockSize);
	 int numRows = _height/_blockSize;

	 blocks.resize((_height/_blockSize) * (_width/_blockSize));

	 float rStep = (_endColor.redF() - _startColor.redF()) / (float)numRows;
	 float gStep = (_endColor.greenF() - _startColor.greenF()) / (float)numRows;
	 float bStep = (_endColor.blueF() - _startColor.blueF()) / (float)numRows;
	 
	 QColor rowBase = _startColor;
	 int rowSize = _width / _blockSize;
	 QImage retval(_width, _height, QImage::Format_RGB32);
	 for(int x = 0; x < numBlocks; ++x) {
			if(x % rowSize == 0)
				 rowBase = updateBaseColor(rowBase, rStep, gStep, bStep, _vVariance);
			
			int pX = x % rowSize * _blockSize;
			int pY = x / rowSize * _blockSize;
			QColor col = varyColor(rowBase, _hVariance);
			for(int i = 0; i < _blockSize; ++i)
				 for(int j = 0; j < _blockSize; ++j)
						retval.setPixel(pX+i, pY+j, col.rgb());
	 }

	 return retval;
}

QColor BlockBuilder::updateBaseColor(const QColor & baseColor, float rStep, 
																		 float gStep, float bStep, int variance)
{
	 QColor retval = baseColor;
	 retval.setRedF(retval.redF() + rStep);
	 retval.setGreenF(retval.greenF() + gStep);
	 retval.setBlueF(retval.blueF() + bStep);
	 return retval;
}

QColor BlockBuilder::varyColor(const QColor & base, int variance)
{
	 QColor retval = base;
	 int var;

	 var = qrand() % variance;
	 var = var / (var > (variance / 2) ? -2 : 2);

	 retval.setRedF(retval.redF() + ((float)var/(float)100));
	 retval.setGreenF(retval.greenF() + ((float)var/(float)100));
	 retval.setBlueF(retval.blueF() + ((float)var/(float)100));
	 
	 return retval;
}
