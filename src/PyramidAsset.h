#ifndef PYRAMIDASSET_H
#define PYRAMIDASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class PyramidAsset : public GameAsset {
 public:
  PyramidAsset(float x, float y, float z);
  ~PyramidAsset();
  virtual void Draw(GLuint);
  void rotateX(float);
  glm::mat4 animate;
  GLfloat angle;

 private:
  GLuint element_buffer_length;
  GLuint colour_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;
  glm::mat4 model_matrix;
  void checkError(std::string file, int line);
};

#endif // PYRAMIDASSET_H
