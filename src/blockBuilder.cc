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

BlockBuilder::BlockBuilder(int width, int height, const QColor & startColor, 
													 const QColor & endColor, int hVariance, 
													 int vVariance) :
	 _width(width), _height(height), _startColor(startColor), 
	 _endColor(endColor), _hVariance(hVariance), _vVariance(vVariance)
{
}

BlockBuilder::~BlockBuilder()
{}

QImage BlockBuilder::buildImage()
{
	 int blockSize = 8;
	 int numBlocks = (_height/blockSize) * (_width/blockSize);
	 int numRows = _height/blockSize;

	 blocks.resize((_height/blockSize) * (_width/blockSize));

	 float rStep = (_endColor.redF() - _startColor.redF()) / (float)numRows;
	 float gStep = (_endColor.greenF() - _startColor.greenF()) / (float)numRows;
	 float bStep = (_endColor.blueF() - _startColor.blueF()) / (float)numRows;
	 
	 QColor rowBase = _startColor;
	 int rowSize = _width / blockSize;
	 QImage retval(_width, _height, QImage::Format_RGB32);
	 for(int x = 0; x < numBlocks; ++x) {
			if(x % rowSize == 0)
				 rowBase = updateBaseColor(rowBase, rStep, gStep, bStep, _vVariance);
			
			int pX = x % rowSize * blockSize;
			int pY = x / rowSize * blockSize;
			for(int i = 0; i < blockSize; ++i)
				 for(int j = 0; j < blockSize; ++j)
						retval.setPixel(pX+i, pY+j, rowBase.rgb());
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
