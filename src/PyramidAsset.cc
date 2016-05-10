#include "PyramidAsset.h"

PyramidAsset::PyramidAsset(float x, float y, float z) : model_matrix(glm::mat4(1.0)){
  // model coordinates, origin at centre.
  GLfloat vertex_buffer [] {
         -0.5f+x, 1.5f+y,  0.5f+z //back left
      ,  -0.5f+x, 1.5f+y, -0.5f+z // front left
      ,   0.5f+x, 1.5f+y, -0.5f+z // front right
      ,   0.5f+x, 1.5f+y,  0.5f+z // back right
      ,   0.0f+x,  0.5f+y,  0.0f+z //apex
	  
  };

  GLfloat vertex_buffer_length = sizeof(vertex_buffer);

  GLfloat colour_buffer[]= {

     0.3,0.4,0.2
    ,0.3,0.4,0.2
    ,0.3,0.4,0.2
    ,0.3,0.4,0.2
    ,0.3,0.4,0.2
    ,0.3,0.4,0.2
    ,0.3,0.4,0.2
    ,0.3,0.4,0.2
    ,0.3,0.4,0.2
    

  };

  colour_buffer_length = sizeof(colour_buffer);
  
  GLuint element_buffer []  {
    0,1,2, //bottom left
    0,2,3, //bottom right
    0,1,4, //left wall
    1,2,4,//front wall
     2,3,4,//right wall
     0,3,4 //back wall
  };
  
  element_buffer_length = sizeof(element_buffer);

  // Transfer buffers to the GPU
  //

  // create buffer
  glGenBuffers(1, &vertex_buffer_token);

  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length,vertex_buffer, GL_STATIC_DRAW);

  glGenBuffers(1, &colour_buffer_token);
  glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, colour_buffer_length, colour_buffer, GL_STATIC_DRAW);

  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,  element_buffer_length, element_buffer, GL_STATIC_DRAW);

  rotateX(0.0f);
}

PyramidAsset::~PyramidAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
// define symbol to be nothing
#define checkGLError()
#endif

void PyramidAsset::checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}

void PyramidAsset::Draw(GLuint program_token) {
  if(!glIsProgram(program_token)) {
    std::cerr << "Drawing Pyramid with invalid program" << std::endl;
    return;
  }

  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

    std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }
    exit(-1);
  }

  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  checkGLError();

  GLuint model_uniform = glGetUniformLocation(program_token,"model");
  checkGLError();

  glUseProgram(program_token);
  checkGLError();

  glUniformMatrix4fv(model_uniform,1,false,glm::value_ptr(model_matrix));

  //Causes the pyramid to rotate
  GLuint animator = glGetUniformLocation(program_token, "animator");
  angle += 0.003f;
  animate = glm::rotate(glm::mat4(1.0f),angle,glm::vec3(0,0.5,0));
  glUniformMatrix4fv(animator,1,GL_FALSE,&animate[0][0]);


  // use the previously transferred buffer as the vertex array.  This way
  // we transfer the buffer once -- at construction -- not on every frame.
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        position_attrib,               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  // glEnableVertexAttribArray(position_attrib);
   glEnableVertexAttribArray(1);
  checkGLError();

  glBindBuffer(GL_ARRAY_BUFFER,colour_buffer_token);
  glVertexAttribPointer(
			1,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
			);
  checkGLError();

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_INT,
                 (GLvoid*) 0
                 );

  checkGLError();

  glDisableVertexAttribArray(position_attrib);
}

void PyramidAsset::rotateX(float angle){

  glm::vec3 unit_x_axis(1.0,0.0,0.0);
	  model_matrix = glm::rotate(this->model_matrix,angle,unit_x_axis);
}
