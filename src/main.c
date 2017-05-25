/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2017 Victor Flores a.k.a (UserX) <user_x@riseup.net>
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "editor-controller.h"

int
main (int argc, char ** argv) {
 	GObject * EditorCtrl;

	gtk_init (&argc, &argv);
	EditorCtrl = editor_controller_new();
	
	GtkWidget * window = editor_controller_get_window (EDITOR_CONTROLLER (EditorCtrl));

	gtk_widget_show_all (window);

	gtk_main ();

	return 0;
}

