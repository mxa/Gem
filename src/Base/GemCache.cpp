////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// zmoelnig@iem.kug.ac.at
//
// Implementation file
//
//    Copyright (c) 1997-1999 Mark Danks.
//    Copyright (c) Günther Geiger.
//    Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::für::umläute
//
//    For information on usage and redistribution, and for a DISCLAIMER OF ALL
//    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
//
/////////////////////////////////////////////////////////

#include "GemCache.h"
#include "Controls/gemhead.h"

/////////////////////////////////////////////////////////
//
// GemCache
//
/////////////////////////////////////////////////////////
// Constructor
//
/////////////////////////////////////////////////////////
GemCache :: GemCache(gemhead *parent)
  : dirty(true), resendImage(false), vertexDirty(false),
    m_parent(parent), m_magic(GEMCACHE_MAGIC)
{
}
void GemCache :: reset(gemhead *parent)
{
  dirty      =true;
  resendImage=false;
  vertexDirty=false; 
  m_parent   =parent; 
  m_magic    =GEMCACHE_MAGIC;
}
/////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
GemCache :: ~GemCache()
{
  m_magic=0xFFFFFFF;
  m_parent=NULL;
}
