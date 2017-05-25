/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * c_fnc.h
 * Copyright (C) 2017 Victor Flores a.k.a UserX <user_x@riseup.net>
 *
 * This is a free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * png_visualizer is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _C_FNC_H_
#define _C_FNC_H_

#ifndef COLOR_CHANNELS 
#define COLOR_CHANNELS 4
#endif

#define RED_LEVEL 				(pixels[i*rowstride + j])
#define GREEN_LEVEL 			(pixels[i*rowstride + j+1])
#define BLUE_LEVEL 				(pixels[i*rowstride + j+2])
#define ALPHA_LEVEL 			(pixels[i*rowstride + j+3])

// rowstride means how mutch bytes there is between the 
// beginning of a line and the beginning of the next one.
void c_fnc1 (unsigned char * pixels, int ht, int rowstride);
void c_fnc2 (unsigned char * pixels, int ht, int rowstride);
void c_fnc3 (unsigned char * pixels, int ht, int rowstride);
void c_fnc4 (unsigned char * pixels, int ht, int rowstride);
void c_fnc5 (unsigned char * pixels, int ht, int rowstride);

#endif /* _C_FNC_H_ */
