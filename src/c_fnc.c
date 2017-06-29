/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * c_fnc.c
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

#include "c_fnc.h"

void
c_fnc1 (byte * pixels, int ht, int rowstride) {

	for (int i = 0; i < ht; i++) {
		for (int j = 0; j < rowstride; j = j + COLOR_CHANNELS) {
			word_t media = 0; // relying on compiler's ability to improve this declaration

			media += RED_LEVEL;
			media += GREEN_LEVEL;
			media += BLUE_LEVEL;
			media = media/3;

			RED_LEVEL = media;
			GREEN_LEVEL = media;
			BLUE_LEVEL = media;

		}
	}
}

void
c_fnc2 (byte * pixels, int ht, int rowstride) {
	byte color = 0;
	for (int i = 0; i < ht; i++) {
		for (int j = 0; j < rowstride; j = j + COLOR_CHANNELS) {
			color = pixels [i*rowstride + j+0];

			pixels [i*rowstride + j+0] = pixels [i*rowstride + j+1];
			pixels [i*rowstride + j+1] = pixels [i*rowstride + j+2];
			pixels [i*rowstride + j+2] = color;

		}
	}
}

void
c_fnc3 (byte * pixels, int ht, int rowstride) { 

	/* ... */
} 

void
c_fnc4 (byte * pixels, int ht, int rowstride) {

	/* ... */

}

void
c_fnc5 (byte * pixels, int ht, int rowstride) {
	
	/* ... */

}

