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

#ifndef INCLUDE_GEM_GLTEXPARAMETERI_H_
#define INCLUDE_GEM_GLTEXPARAMETERI_H_

#include "GemGLBase.h"

/*
 CLASS
	GEMglTexParameteri
 KEYWORDS
	openGL	0
 DESCRIPTION
	wrapper for the openGL-function
	"glTexParameteri( GLenum target, GLenum pname, GLint param)"
 */

class GEM_EXTERN GEMglTexParameteri : public GemGLBase
{
	CPPEXTERN_HEADER(GEMglTexParameteri, GemGLBase)

	public:
	  // Constructor
	  GEMglTexParameteri (t_float, t_float, t_float);	// CON

	protected:
	  // Destructor
	  virtual ~GEMglTexParameteri ();
	  // Do the rendering
	  virtual void	render (GemState *state);

	// variables
	  GLenum	target;		// VAR
	  virtual void	targetMess(t_float);	// FUN

	  GLenum	pname;		// VAR
	  virtual void	pnameMess(t_float);	// FUN

	  GLint	param;		// VAR
	  virtual void	paramMess(t_float);	// FUN


	private:

	// we need some inlets
	  t_inlet *m_inlet[3];

	// static member functions
	  static void	 targetMessCallback (void*, t_floatarg);
	  static void	 pnameMessCallback (void*, t_floatarg);
	  static void	 paramMessCallback (void*, t_floatarg);
};
#endif // for header file
