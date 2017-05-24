#include "definitions.h"

// rowstride means how mutch bytes there is between the 
// beginning of a line and the beginning of the next one.
void c_fnc1 (unsigned char * pixels, int ht, int rowstride);
void c_fnc2 (unsigned char * pixels, int ht, int rowstride);
void c_fnc3 (unsigned char * pixels, int ht, int rowstride);
void c_fnc4 (unsigned char * pixels, int ht, int rowstride);
void c_fnc5 (unsigned char * pixels, int ht, int rowstride);

void
c_fnc1 (unsigned char * pixels, int ht, int rowstride) {

	for (int i = 0; i < ht; i++) {
		for (int j = 0; j < rowstride; j = j + COLOR_CHANNELS) {
			word_t media = 0;

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
c_fnc2 (unsigned char * pixels, int ht, int rowstride) {
	unsigned char color = 0;
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
c_fnc3 (unsigned char * pixels, int ht, int rowstride) { 

	/* ... */

} 

void
c_fnc4 (unsigned char * pixels, int ht, int rowstride) {

	/* ... */

}

void
c_fnc5 (unsigned char * pixels, int ht, int rowstride) {
	
	/* ... */

}
