/*
  Fiducial tracking library.
  Copyright (C) 2004 Ross Bencina <rossb@audiomulch.com>
  Maintainer (C) 2005-2008 Martin Kaltenbrunner <mkalten@iua.upf.edu>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef INCLUDED_DEFAULT_TREE_H
#define INCLUDED_DEFAULT_TREE_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

const int default_tree_length = 216;
const char* default_tree[default_tree_length] = {
"w0122222212212121111",
"w0122212221222121111",
"w0122212221221221111",
"w0122212221212121111",
"w0122222212221211111",
"w0122221221221221111",
"w0122212212212211111",
"w0122221222122121111",
"w0122222222212111111",
"w0122221221212121111",
"w0122222122221211111",
"w0122221222122211111",
"w0122222222222121111",
"w0122221212121211111",
"w0122222121212121111",
"w0122222121212111111",
"w0122212212212121111",
"w0122222212222211111",
"w0122222212212211111",
"w0122221222121211111",
"w0122222221221221111",
"w0122222122222121111",
"w0122222222212211111",
"w0122212212121211111",
"w0122222212222121111",
"w0122122122121211111",
"w0122222212121211111",
"w0122222222122211111",
"w0122221221221211111",
"w0122222222222211111",
"w0122222122212111111",
"w0122212221212111111",
"w0122222122122111111",
"w0122212121212121111",
"w0122222221212111111",
"w0122222221221211111",
"w0122222212222111111",
"w0122222221222211111",
"w0122212212212111111",
"w0122222212221221111",
"w0122221222122111111",
"w0122222222122121111",
"w0122221222212111111",
"w0122222222122111111",
"w0122222222222221111",
"w0122222122212121111",
"w0122222122122121111",
"w0122222222121211111",
"w0122212221221211111",
"w0121212121212121111",
"w0122222222212221111",
"w0122222222221211111",
"w0122222222121111111",
"w0122222221222221111",
"w0122222222222111111",
"w0122222212212111111",
"w0122222212222221111",
"w0122222221212121111",
"w0122221222212211111",
"w0122121212121211111",
"w0122222221222121111",
"w0122222221222111111",
"w0122222122221221111",
"w0122122122122111111",
"w0122221222212121111",
"w0122222122212221111",
"w0122222122212211111",
"w0122222222221221111",
"w0122221221221111111",
"w0122212121212111111",
"w0122221222212221111",
"w0122212221221111111",
"w0122222222122221111",
"w0122221212121111111",
"w0122122121212121111",
"w0121212121212111111",
"w0122212221222111111",
"w0122222222221111111",
"w0122221221212111111",
"w0122222222212121111",
"w0122222212221111111",
"w0122221222211111111",
"w0122122122122121111",
"w0122221222121111111",
"w0122222122121211111",
"w0122222122211111111",
"w0122222221221111111",
"w0122222122222111111",
"w0122122121212111111",
"w0122222212211111111",

"w0122222222211111111",
"w0122222222111111111",
"w0122222221211111111",
"w0122222122221111111",
"w0122212212121111111",
"w0122222122121111111",
"w0122222122111111111",
"w0122222121211111111",
"w0122222212121111111",
"w0122222221111111111",
"w0122222212111111111",
"w0122221222111111111",
"w0122212221211111111",
"w0122221221211111111",
"w0122122122121111111",
"w0122212212211111111",
"w0122121212121111111",
"w0122212121211111111",

"b0122222212212121111",
"b0122212221222121111",
"b0122212221221221111",
"b0122212221212121111",
"b0122222212221211111",
"b0122221221221221111",
"b0122212212212211111",
"b0122221222122121111",
"b0122222222212111111",
"b0122221221212121111",
"b0122222122221211111",
"b0122221222122211111",
"b0122222222222121111",
"b0122221212121211111",
"b0122222121212121111",
"b0122222121212111111",
"b0122212212212121111",
"b0122222212222211111",
"b0122222212212211111",
"b0122221222121211111",
"b0122222221221221111",
"b0122222122222121111",
"b0122222222212211111",
"b0122212212121211111",
"b0122222212222121111",
"b0122122122121211111",
"b0122222212121211111",
"b0122222222122211111",
"b0122221221221211111",
"b0122222222222211111",
"b0122222122212111111",
"b0122212221212111111",
"b0122222122122111111",
"b0122212121212121111",
"b0122222221212111111",
"b0122222221221211111",
"b0122222212222111111",
"b0122222221222211111",
"b0122212212212111111",
"b0122222212221221111",
"b0122221222122111111",
"b0122222222122121111",
"b0122221222212111111",
"b0122222222122111111",
"b0122222222222221111",
"b0122222122212121111",
"b0122222122122121111",
"b0122222222121211111",
"b0122212221221211111",
"b0121212121212121111",
"b0122222222212221111",
"b0122222222221211111",
"b0122222222121111111",
"b0122222221222221111",
"b0122222222222111111",
"b0122222212212111111",
"b0122222212222221111",
"b0122222221212121111",
"b0122221222212211111",
"b0122121212121211111",
"b0122222221222121111",
"b0122222221222111111",
"b0122222122221221111",
"b0122122122122111111",
"b0122221222212121111",
"b0122222122212221111",
"b0122222122212211111",
"b0122222222221221111",
"b0122221221221111111",
"b0122212121212111111",
"b0122221222212221111",
"b0122212221221111111",
"b0122222222122221111",
"b0122221212121111111",
"b0122122121212121111",
"b0121212121212111111",
"b0122212221222111111",
"b0122222222221111111",
"b0122221221212111111",
"b0122222222212121111",
"b0122222212221111111",
"b0122221222211111111",
"b0122122122122121111",
"b0122221222121111111",
"b0122222122121211111",
"b0122222122211111111",
"b0122222221221111111",
"b0122222122222111111",
"b0122122121212111111",
"b0122222212211111111",
"b0122222222211111111",
"b0122222222111111111",
"b0122222221211111111",
"b0122222122221111111",
"b0122212212121111111",
"b0122222122121111111",
"b0122222122111111111",
"b0122222121211111111",
"b0122222212121111111",
"b0122222221111111111",
"b0122222212111111111",
"b0122221222111111111",
"b0122212221211111111",
"b0122221221211111111",
"b0122122122121111111",
"b0122212212211111111",
"b0122121212121111111",
"b0122212121211111111"};
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* INCLUDED_DEFAULT_TREE_H */
