/*
 * BoundingBox.h
 *
 *  Created on: 10 May 2016
 *      Author: jb0nline
 */

#ifndef SRC_BOUNDINGBOX_H_
#define SRC_BOUNDINGBOX_H_


class BoundingBox {
public:
	BoundingBox(int,int,int,int,int,int);
	virtual ~BoundingBox();

private:
	int centerPoint[3];
	int sizeX;
	int sizeY;
	int sizeZ;
};

#endif /* SRC_BOUNDINGBOX_H_ */
