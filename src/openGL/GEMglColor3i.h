 /* ------------------------------------------------------------------
  * GEM - Graphics Environment for Multimedia
  *
  *  Copyright (c) 2002 IOhannes m zmoelnig. forum::für::umläute. IEM
  *	zmoelnig@iem.kug.ac.at
  *  For information on usage and redistribution, and for a DISCLAIMER
  *  OF ALL WARRANTIES, see the file, "GEM.LICENSE.TERMS"
  *
  *  this file has been generated...
  * ------------------------------------------------------------------
  */

#ifndef INCLUDE_GEM_GLCOLOR3I_H_
#define INCLUDE_GEM_GLCOLOR3I_H_

#include "GemGLBase.h"

/*
 CLASS
	GEMglColor3i
 KEYWORDS
	openGL	0
 DESCRIPTION
	wrapper for the openGL-function
	"glColor3i( GLint red, GLint green, GLint blue)"
 */

class GEM_EXTERN GEMglColor3i : public GemGLBase
{
	CPPEXTERN_HEADER(GEMglColor3i, GemGLBase)

	public:
	  // Constructor
	  GEMglColor3i (t_float, t_float, t_float);	// CON

	protected:
	  // Destructor
	  virtual ~GEMglColor3i ();
	  // Do the rendering
	  virtual void	render (GemState *state);

	// variables
	  GLint	red;		// VAR
	  virtual void	redMess(t_float);	// FUN

	  GLint	green;		// VAR
	  virtual void	greenMess(t_float);	// FUN

	  GLint	blue;		// VAR
	  virtual void	blueMess(t_float);	// FUN


	private:

	// we need some inlets
	  t_inlet *m_inlet[3];

	// static member functions
	  static void	 redMessCallback (void*, t_floatarg);
	  static void	 greenMessCallback (void*, t_floatarg);
	  static void	 blueMessCallback (void*, t_floatarg);
};
#endif // for header file
