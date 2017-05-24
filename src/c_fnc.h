#ifndef _C_FNC_H_
#define _C_FNC_H_

#ifndef COLOR_CHANNELS 
#define COLOR_CHANNELS 3
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
