////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// zmoelnig@iem.kug.ac.at
//
// Implementation file
//
//    Copyright (c) 1997-2000 Mark Danks.
//    Copyright (c) Günther Geiger.
//    Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::für::umläute. IEM
//    For information on usage and redistribution, and for a DISCLAIMER OF ALL
//    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
//
/////////////////////////////////////////////////////////

#include "cone.h"

CPPEXTERN_NEW_WITH_TWO_ARGS(cone, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT)

/////////////////////////////////////////////////////////
//
// cone
//
/////////////////////////////////////////////////////////
// Constructor
//
/////////////////////////////////////////////////////////
cone :: cone(t_floatarg size, t_floatarg slices)
  : cylinder(size, slices)
{ }

/////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
cone :: ~cone()
{ }

/////////////////////////////////////////////////////////
// render
//
/////////////////////////////////////////////////////////
void cone :: setupParameters(void)
{
  baseRadius=m_size;
  topRadius=0.0;
  height=m_size*2;
  slices=m_numSlices;
  stacks=m_numSlices;
}

/////////////////////////////////////////////////////////
// static member functions
//
/////////////////////////////////////////////////////////
void cone :: obj_setupCallback(t_class *)
{ }
