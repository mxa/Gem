/*-----------------------------------------------------------------
LOG
    GEM - Graphics Environment for Multimedia

    GemPixUtil.h
       - contains image functions for pix objects
       - part of GEM

    Copyright (c) 1997-1999 Mark Danks. mark@danks.org
    Copyright (c) G�nther Geiger. geiger@epy.co.at
    Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::f�r::uml�ute. IEM. zmoelnig@iem.kug.ac.at
    For information on usage and redistribution, and for a DISCLAIMER OF ALL
    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/

#ifndef INCLUDE_GEMPIXUTIL_H_
#define INCLUDE_GEMPIXUTIL_H_

// I hate Microsoft...I shouldn't have to do this!
#ifdef _WINDOWS
#include <windows.h>
#endif

#ifdef MACOSX
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <QuickTime/QuickTime.h>
#else
#include <GL/gl.h>
#ifndef NT
#include "config.h"
#endif // NT
#endif // MACOSX

// packed pixel defines for textures
#ifndef GL_EXT_packed_pixels
#define GL_UNSIGNED_BYTE_3_3_2_EXT          0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT       0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT       0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT         0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT      0x8036
#endif

#ifdef GL_YCBCR_422_APPLE
#define GL_YCBCR_422_GEM GL_YCBCR_422_APPLE
#else
#define GL_YCBCR_422_GEM 0x85B9
#endif

#include "Base/GemFuncUtil.h"

/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    imageStruct
    
    The basic image structure

-----------------------------------------------------------------*/
// we now have a class "imageStruct";
// since i need to compile some of the sources with an older version of Gem
// there is a  new define here:
#define IMAGE_CLASS

struct GEM_EXTERN imageStruct
{
  imageStruct() : xsize (0),ysize(0),csize(0),notowned(0),data(0),datasize(0),pdata(0),
#ifdef GL_UNSIGNED_SHORT_8_8_REV_APPLE
       // or should type be GL_UNSIGNED_INT_8_8_8_8_REV ? i don't know: jmz
       type(GL_UNSIGNED_SHORT_8_8_REV_APPLE), format(GL_YCBCR_422_GEM)
#else
       type(GL_UNSIGNED_BYTE), format(GL_RGBA)
#endif
{}

  ~imageStruct() { clear(); }
  void info();
  //////////
  // columns
  unsigned char* allocate(int size) {
    if (pdata) delete [] pdata;
#if 1
    pdata = new unsigned char[size+31];
    data = (unsigned char*) ((((unsigned int)pdata)+31)& (~31));
#else
    data = pdata =  new unsigned char [size];
#endif
    datasize=size;
    return data; 
  }
  unsigned char* allocate() {  return allocate(xsize*ysize*csize);  }

  // if we have allocated some space already, only re-allocate when needed.
  unsigned char* reallocate(int size) {
    if (size>datasize)
      return allocate(size);
    return data;
  }
  unsigned char* reallocate() {  return reallocate(xsize*ysize*csize);  }
 
  void clear() {
    if (!notowned && pdata) {
      delete [] pdata;
      data = pdata = 0;      
    }
    xsize = ysize = csize = 0;
    datasize=0;
  }
  
  GLint           xsize;

  //////////
  // rows
  GLint   	    ysize;

  //////////
  // color (LUMINANCE = 1, RGBA = 4)
  GLint   	    csize;

  //////////
  // the format - either GL_RGBA, GL_BGRA_EXT, or GL_LUMINANCE
  // or GL_YCBCR_422_GEM (which is on mac-computers GL_YCBCR_422_APPLE)
  GLenum          format;

  //////////
  // data type - always GL_UNSIGNED_BYTE (except for OS X)
  GLenum          type;
  
  //////////
  // is this owned by us (?)
  int notowned;
  //////////
  // the actual image data
  
  //////////
  // gets a pixel
  inline unsigned char GetPixel(int Y, int X, int C)
  { return(data[Y * xsize * csize + X * csize + C]); }
  
  //////////
  // sets a pixel
  inline void SetPixel(int Y, int X, int C, unsigned char VAL)
  { data[Y * xsize * csize + X * csize + C] = VAL; }
  
  void copy2Image(imageStruct *to);
  void refreshImage(imageStruct *to);
  void copy2ImageStruct(imageStruct *to); // copy the imageStruct (but not the actual data)
  
  
  unsigned char   *data;
  int             datasize;
  private:
  unsigned char   *pdata;
};

/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    pixBlock
    
    The pix block structure

-----------------------------------------------------------------*/
struct GEM_EXTERN pixBlock
{
    //////////
    // the block's image
    imageStruct     image;

    //////////
    // is this a newimage since last time?
    //	ie, has it been refreshed
    int     	    newimage;
};

///////////////////////////////////////////////////////////////////////////////
// imageStruct utility functions
//
///////////////////////////////////////////////////////////////////////////////
//////////
// copies all of the data over and mallocs memory
GEM_EXTERN extern void copy2Image(imageStruct *to, imageStruct *from);

//////////
// assumes that it only has to refresh the data
GEM_EXTERN extern void refreshImage(imageStruct *to, imageStruct *from);


///////////////////////////////////////////////////////////////////////////////
// Color component defines
//
// These should be used to reference the various color channels
///////////////////////////////////////////////////////////////////////////////
#ifdef MACOSX				//tigital
const int chRed		= 1;
const int chGreen	= 2;
const int chBlue	= 3;
const int chAlpha	= 0;
#else
const int chRed		= 0;
const int chGreen	= 1;
const int chBlue	= 2;
const int chAlpha	= 3;
#endif

const int chGray	= 0;

///////////////////////////////////////////////////////////////////////////////
// Pixel access functions
//
///////////////////////////////////////////////////////////////////////////////


//
// Accelerated Pixel Manipulations 
// This is sort on a vector operation on 8 chars at the same time .... could be
// implemented in MMX
// Alpha channel is not added !! (would be nr 3 and 7)

#define ADD8(a,b) \
 ((unsigned char*)(a))[0] = CLAMP_HIGH((int)((unsigned char*)(a))[0] + ((unsigned char*)(b))[0]);\
 ((unsigned char*)(a))[1] = CLAMP_HIGH((int)((unsigned char*)(a))[1] + ((unsigned char*)(b))[1]);\
 ((unsigned char*)(a))[2] = CLAMP_HIGH((int)((unsigned char*)(a))[2] + ((unsigned char*)(b))[2]);\
 ((unsigned char*)(a))[4] = CLAMP_HIGH((int)((unsigned char*)(a))[4] + ((unsigned char*)(b))[4]);\
 ((unsigned char*)(a))[5] = CLAMP_HIGH((int)((unsigned char*)(a))[5] + ((unsigned char*)(b))[5]);\
 ((unsigned char*)(a))[6] = CLAMP_HIGH((int)((unsigned char*)(a))[6] + ((unsigned char*)(b))[6]);\

#define SUB8(a,b) \
 ((unsigned char*)(a))[0] = CLAMP_LOW((int)((unsigned char*)(a))[0] - ((unsigned char*)(b))[0]);\
 ((unsigned char*)(a))[1] = CLAMP_LOW((int)((unsigned char*)(a))[1] - ((unsigned char*)(b))[1]);\
 ((unsigned char*)(a))[2] = CLAMP_LOW((int)((unsigned char*)(a))[2] - ((unsigned char*)(b))[2]);\
 ((unsigned char*)(a))[4] = CLAMP_LOW((int)((unsigned char*)(a))[4] - ((unsigned char*)(b))[4]);\
 ((unsigned char*)(a))[5] = CLAMP_LOW((int)((unsigned char*)(a))[5] - ((unsigned char*)(b))[5]);\
 ((unsigned char*)(a))[6] = CLAMP_LOW((int)((unsigned char*)(a))[6] - ((unsigned char*)(b))[6]);\


#endif
