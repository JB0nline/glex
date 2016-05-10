/*
 * BoundingBox.h
 *
 *  Created on: 10 May 2016
 *      Author: jb0nline
 */

#ifndef SRC_BOUNDINGBOX_H_
#define SRC_BOUNDINGBOX_H_

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class BoundingBox {
public:
	BoundingBox();
	virtual ~BoundingBox();

private:
 GLuint element_buffer_length;
 GLuint colour_buffer_length;
 GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;
 glm::mat4 model_matrix;
};

#endif /* SRC_BOUNDINGBOX_H_ */
