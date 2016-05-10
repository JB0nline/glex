/*
 * BoundingBox.cpp
 *
 *  Created on: 10 May 2016
 *      Author: jb0nline
 */

#include "BoundingBox.h"

BoundingBox::BoundingBox(int xposition, int yposition, int zposition, int xsize, int ysize, int zsize) {
	sizeX = xsize;
	sizeY = ysize;
	sizeZ = zsize;
	centerPoint = {xposition,yposition,zposition};



}

BoundingBox::~BoundingBox() {
}

