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

#ifndef INCLUDE_GEM_GLCOLORMATERIAL_H_
#define INCLUDE_GEM_GLCOLORMATERIAL_H_

#include "GemGLBase.h"

/*
 CLASS
	GEMglColorMaterial
 KEYWORDS
	openGL	0
 DESCRIPTION
	wrapper for the openGL-function
	"glColorMaterial( GLenum face, GLenum mode)"
 */

class GEM_EXTERN GEMglColorMaterial : public GemGLBase
{
	CPPEXTERN_HEADER(GEMglColorMaterial, GemGLBase)

	public:
	  // Constructor
	  GEMglColorMaterial (int, t_atom*); // CON

	protected:
	  // Destructor
	  virtual ~GEMglColorMaterial ();
	  // Do the rendering
	  virtual void	render (GemState *state);

	// variables
	  GLenum	face;		// VAR
	  virtual void	faceMess(t_atom);	// FUN

	  GLenum	mode;		// VAR
	  virtual void	modeMess(t_atom);	// FUN


	private:

	// we need some inlets
	  t_inlet *m_inlet[2];

	// static member functions
	  static void	 faceMessCallback (void*,t_symbol*,int,t_atom*);
	  static void	 modeMessCallback (void*,t_symbol*,int,t_atom*);
};
#endif // for header file
