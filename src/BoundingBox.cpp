/*
 * BoundingBox.cpp
 *
 *  Created on: 10 May 2016
 *      Author: jb0nline
 */

#include "BoundingBox.h"

BoundingBox::BoundingBox() {
	// TODO Auto-generated constructor stub

}

BoundingBox::~BoundingBox() {
	// TODO Auto-generated destructor stub
}
void createBBox(int x, int y, int z){
// model coordinates, origin at centre.
GLfloat vertex_buffer [] {
  -0.5f+x, -0.5f+y, -0.5f+z
  , -0.5f+x,  0.5f+y, -0.5f+z
  ,  0.5f+x, -0.5f+y, -0.5f+z
  ,  0.5f+x,  0.5f+y, -0.5f+z

	, -0.5f+x, -0.5f+y,  0.5f+z
	, -0.5f+x,  0.5f+y,  0.5f+z
	,  0.5f+x,  0.5f+y,  0.5f+z
	,  0.5f+x, -0.5f+y,  0.5f+z
};

 GLfloat vertex_buffer_length = sizeof(vertex_buffer);

GLfloat colour_buffer[]= {

   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0,
   0.0,0.0,1.0


};

  colour_buffer_length = sizeof(colour_buffer);

GLuint element_buffer []  {
  0, 1, 2
  , 1, 3, 2

	, 0, 1, 4
	, 1, 4, 5

	, 2, 3, 7
	, 3, 6, 7

	, 4, 5, 7
	, 5, 6, 7

	, 1, 5, 3
	, 5, 3, 6

	, 0, 2, 4
	, 2, 4, 7
};


element_buffer_length = sizeof(element_buffer);

// Transfer buffers to the GPU
//

// create buffer
glGenBuffers(1, &vertex_buffer_token);

// immediately bind the buffer and transfer the data
glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length, vertex_buffer, GL_STATIC_DRAW);

glGenBuffers(1, &colour_buffer_token);
glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
glBufferData(GL_ARRAY_BUFFER, colour_buffer_length, colour_buffer, GL_STATIC_DRAW);

glGenBuffers(1, &element_buffer_token);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_buffer_length, element_buffer, GL_STATIC_DRAW);
}
