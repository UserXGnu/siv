/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * definitions.h
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


#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#ifndef LICENSE
#define LICENSE 	"Copyright (C) 2017 UserX <userx.gnu@gmail.com>\n\n"\
					"This is a free software: you can redistribute it and/or modify it\n"\
					"under the terms of the GNU General Public License as published by the\n"\
					"Free Software Foundation, either version 3 of the License, or\n"\
					"(at your option) any later version.\n\n"\
					"Editor X is distributed in the hope that it will be useful, but\n"\
					"WITHOUT ANY WARRANTY; without even the implied warranty of\n"\
					"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\n"\
					"See the GNU General Public License for more details.\n"\
					"You should have received a copy of the GNU General Public License along\n"\
					"with this program.  If not, see <http://www.gnu.org/licenses/>."
#endif 
	
#ifndef EDITOR_ABOUT_IMAGE
#define EDITOR_ABOUT_IMAGE "resources/gnu_headshadow.png"
#endif

#ifndef EDITOR_ALT_ABOUT_IMAGE
#define EDITOR_ALT_ABOUT_IMAGE "/usr/share/siv_image/gnu_headshadow.png"
#endif 

#ifndef EDITOR_OPENING_IMAGE 
#define EDITOR_OPENING_IMAGE "resources/gplv3-127x51.png"
#endif

#ifndef EDITOR_ALT_OPENING_IMAGE
#define EDITOR_ALT_OPENING_IMAGE "/usr/share/siv_image/gplv3-127x51.png"
#endif

#ifndef PROGRAM_NAME
#define PROGRAM_NAME 	"SIV - Simple Image Viewer"
#endif 

#ifndef SIV_VERSION 
#define SIV_VERSION 	"0.1"
#endif 

#ifndef COPYRIGHT
#define COPYRIGHT		"Copyright © 2017 Victor Flores (UserX)"
#endif

typedef unsigned short int word_t;
typedef unsigned char byte;

#endif /* _DEFINITIONS_H_ */
