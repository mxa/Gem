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

#ifndef INCLUDE_GEM_GLTEXGEND_H_
#define INCLUDE_GEM_GLTEXGEND_H_

#include "GemGLBase.h"

/*
 CLASS
	GEMglTexGend
 KEYWORDS
	openGL	0
 DESCRIPTION
	wrapper for the openGL-function
	"glTexGend( GLenum coord, GLenum pname, GLdouble param)"
 */

class GEM_EXTERN GEMglTexGend : public GemGLBase
{
	CPPEXTERN_HEADER(GEMglTexGend, GemGLBase)

	public:
	  // Constructor
	  GEMglTexGend (t_float, t_float, t_float);	// CON

	protected:
	  // Destructor
	  virtual ~GEMglTexGend ();
	  // Do the rendering
	  virtual void	render (GemState *state);

	// variables
	  GLenum	coord;		// VAR
	  virtual void	coordMess(t_float);	// FUN

	  GLenum	pname;		// VAR
	  virtual void	pnameMess(t_float);	// FUN

	  GLdouble	param;		// VAR
	  virtual void	paramMess(t_float);	// FUN


	private:

	// we need some inlets
	  t_inlet *m_inlet[3];

	// static member functions
	  static void	 coordMessCallback (void*, t_floatarg);
	  static void	 pnameMessCallback (void*, t_floatarg);
	  static void	 paramMessCallback (void*, t_floatarg);
};
#endif // for header file
