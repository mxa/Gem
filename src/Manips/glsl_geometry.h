/*-----------------------------------------------------------------

GEM - Graphics Environment for Multimedia

Load an GLSL geometry shader

 *  Created by tigital on 10/04/2005.
 *  Copyright 2005 James Tittle.

Copyright (c) 1997-1999 Mark Danks. mark@danks.org
Copyright (c) Günther Geiger. geiger@epy.co.at
Copyright (c) 2001-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/

#ifndef _INCLUDE__GEM_MANIPS_GLSL_GEOMETRY_H_
#define _INCLUDE__GEM_MANIPS_GLSL_GEOMETRY_H_

#include "Manips/glsl_program.h"

#define GEM_shader_none  0
#define GEM_shader_GLSL  1
#define GEM_shader_CG    2

/*-----------------------------------------------------------------
  -------------------------------------------------------------------
  CLASS
  glsl_geometry

  Loads in a geometry shader

  KEYWORDS

  DESCRIPTION

  -----------------------------------------------------------------*/
class GEM_EXTERN glsl_geometry : public GemBase
{
  CPPEXTERN_HEADER(glsl_geometry, GemBase);

public:

  //////////
  // Constructor
  glsl_geometry(void);
  glsl_geometry(t_symbol *filename);

protected:

  //////////
  // Destructor
  virtual ~glsl_geometry();

  //////////
  // close the shader file
  virtual void closeMess(void);
  //////////
  // open a shader up
  virtual bool openMessGL2(void);
  virtual bool openMessARB(void);
  virtual void openMess(t_symbol *filename);
  virtual void loadShader(void);


  ////////
  // extension check
  virtual bool isRunnable(void);

  //////////
  // Do the rendering
  virtual void render(GemState *state);

  //////////
  // Clear the dirty flag on the pixBlock
  virtual void postrender(GemState *state);

  //////////
  virtual void startRendering();

  //////////
  // Print Info about Hardware limits
  virtual void printInfo();

  //////////
  //
  GLuint                m_shaderTarget;
  GLuint                m_shader;
  GLhandleARB   m_shaderARB;
  GLint                 m_compiled;
  int                     m_size;
  char*                 m_shaderString;
  t_symbol* m_shaderFilename;

  GLint                 m_shaderID;
  t_outlet              *m_outShaderID;
  gem::utils::gl::GLuintMap m_idmapper;
  float                 m_idmapped;
};

#endif  // for header file
