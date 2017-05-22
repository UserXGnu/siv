/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * editor-controller.c
 * Copyright (C) 2017 Victor Flores a.k.a UserX <user_x@riseup.net>
 *
 * png_visualizer is free software: you can redistribute it and/or modify it
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

#include "editor-controller.h"
#include "editor-window.h"
#include "editor-menu-bar.h"

#include <stdlib.h>
#include <string.h>

extern void asm_fnc1 (guchar * pixels, int ht, int rowstride);
extern void asm_fnc2 (guchar * pixles, int ht, int rowstride);
extern void asm_fnc3 (guchar * pixles, int ht, int rowstride);
extern void asm_fnc4 (guchar * pixles, int ht, int rowstride);

struct _EditorControllerPrivate {
	GtkWidget * Window;
};

G_DEFINE_TYPE (EditorController, editor_controller, G_TYPE_OBJECT);


	/************************************************************************************
	 * 									MISC callbacks DEV								*
	 ************************************************************************************/
void 
editor_controller_open_callback (GtkWidget * self, gpointer data) {
	GtkWidget * dialog;
	gint resp;
	gchar * filename;
	GtkWidget * img;

	dialog = gtk_file_chooser_dialog_new ("PNG Editor - Open Dialog",
	                                      GTK_WINDOW (data),
	                                      GTK_FILE_CHOOSER_ACTION_OPEN,
	                                      "Cancel", GTK_RESPONSE_CANCEL,
	                                      "Open", GTK_RESPONSE_ACCEPT,
	                                      NULL);

	resp = gtk_dialog_run (GTK_DIALOG (dialog));

	if (resp != GTK_RESPONSE_ACCEPT) {
		gtk_widget_destroy (dialog);
		return;
	}

	filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));

#ifdef DEBUG
	g_print ("FILENAME: %s\n", filename);
#endif

	GdkPixbuf * pb = gdk_pixbuf_new_from_file_at_scale (filename, 640, -1, TRUE, NULL);
	img = gtk_image_new_from_pixbuf (pb);
	if (filename) {
		editor_window_set_image (EDITOR_WINDOW (data), img);
		gtk_widget_hide (GTK_WIDGET (data));
		gtk_widget_show_all (GTK_WIDGET (data));
		g_free (filename);
	}
	gtk_widget_destroy (dialog);
	
}

void 
editor_controller_about_dialog_callback (GtkWidget * widget, gpointer data) {
	GError * err = NULL;
	GdkPixbuf * pixbuf;
	
	GtkWidget * dialog = gtk_about_dialog_new ();
	const gchar * authors[] = {"Victor Flores (UserX)", NULL};

#ifdef PROGRAM_NAME 
	gtk_about_dialog_set_program_name (GTK_ABOUT_DIALOG (dialog),
										"SIV - Simple Image Viewer");
#endif 

#ifdef SIV_VERSION
	gtk_about_dialog_set_version (GTK_ABOUT_DIALOG (dialog),
	                              SIV_VERSION);
#endif
	gtk_about_dialog_set_website (GTK_ABOUT_DIALOG(dialog), "https://github.com/userxgnu/siv");
	gtk_about_dialog_set_authors (GTK_ABOUT_DIALOG (dialog), authors);

#ifdef COPYRIGHT
	gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG (dialog), COPYRIGHT);
#endif

#ifdef LICENSE
	gtk_about_dialog_set_license (GTK_ABOUT_DIALOG (dialog), LICENSE);
#endif 
	
	pixbuf = gdk_pixbuf_new_from_file_at_scale ("resources/gnu_headshadow.png", 
												480, 640,
												TRUE, &err);
	if (pixbuf == NULL) {
			g_print("[SIMPLE-IMAGE-VIEWER] Warning: %s\n", err->message);
		pixbuf = gdk_pixbuf_new_from_file ("/usr/share/siv_image/gnu_headshadow.png", &err);
		if (pixbuf == NULL) {
			g_print("[SIMPLE-IMAGE-VIEWER] Warning: %s\n", err->message);
		}
	}
	gtk_about_dialog_set_logo (GTK_ABOUT_DIALOG (dialog), pixbuf);
	g_object_unref (pixbuf);
	pixbuf = NULL;

	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy(dialog);	
}

	/************************************************************************************
	 * 									C CALLBACKS DEV									*
	 ************************************************************************************/
void
editor_controller_cppfunc1_callback (GtkWidget * self, gpointer data) {
	GtkWidget * window;
	//GtkWidget * menubar;
	GtkWidget * image;
	GdkPixbuf * pb;
	gint ht;
	gint rowstride;
	gint bpp;
	guchar * pixel;
	window = data;

	image = editor_window_get_image (EDITOR_WINDOW (window));
	if (image == NULL) 
		return;
	
	pb = gtk_image_get_pixbuf (GTK_IMAGE (image));
	rowstride = gdk_pixbuf_get_rowstride (pb);
	bpp = gdk_pixbuf_get_n_channels (pb);
	ht = gdk_pixbuf_get_height (pb);
	pixel = gdk_pixbuf_get_pixels (pb);


	for (gint i = 0; i < ht; i++) {
		for (gint j = 0; j < rowstride; j = j + bpp) {
			pixel [i*rowstride + j+0] = 0;

		}
	}
	
	gtk_image_set_from_pixbuf (GTK_IMAGE (image), pb);
	

	gtk_widget_hide (editor_window_get_box (EDITOR_WINDOW (window) ) );
	gtk_widget_show_all (editor_window_get_box (EDITOR_WINDOW (window) ) );
	
}

void
editor_controller_cppfunc2_callback (GtkWidget * self, gpointer data) {
	GtkWidget * window;
	GtkWidget * image;
	GdkPixbuf * pb;
	gint ht;
	gint rowstride;
	gint bpp;
	guchar * pixel;

	window = data;
	image = editor_window_get_image (EDITOR_WINDOW (window));
	if (image == NULL) 
		return;
	
	pb = gtk_image_get_pixbuf (GTK_IMAGE (image));
	
	bpp = gdk_pixbuf_get_n_channels (pb);
	ht = gdk_pixbuf_get_height (pb);
	pixel = gdk_pixbuf_get_pixels (pb);
	rowstride = gdk_pixbuf_get_rowstride (pb);
	gint color;
	for (gint i = 0; i < ht; i++) {
		for (gint j = 0; j < rowstride; j = j + bpp) {
			color = pixel [i*rowstride + j+0];

			pixel [i*rowstride + j+0] = pixel [i*rowstride + j+1];
			pixel [i*rowstride + j+1] = pixel [i*rowstride + j+2];
			pixel [i*rowstride + j+2] = color;

		}
	}
	
	gtk_image_set_from_pixbuf (GTK_IMAGE (image), pb);
	

	gtk_widget_hide (editor_window_get_box (EDITOR_WINDOW (window) ) );
	gtk_widget_show_all (editor_window_get_box (EDITOR_WINDOW (window) ) );
	
}

#define LEVEL 	50
void
editor_controller_cppfunc3_callback (GtkWidget * self, gpointer data) {
	GtkWidget * window;
	GtkWidget * image;
	GdkPixbuf * pb;
	gint ht;
	gint wt;
	gint rowstride;
	gint bpp;
	guchar * pixel;

	window = data;
	image = editor_window_get_image (EDITOR_WINDOW (window));
	if (image == NULL) 
		return;
	
	pb = gtk_image_get_pixbuf (GTK_IMAGE (image));
	
	//bpp = gdk_pixbuf_get_bits_per_sample (pb);
	bpp = gdk_pixbuf_get_n_channels (pb);
	ht = gdk_pixbuf_get_height (pb);
	pixel = gdk_pixbuf_get_pixels (pb);
	rowstride = gdk_pixbuf_get_rowstride (pb);
	gint level;
	for (gint i = 0; i < ht; i++) {
		for (gint j = 0; j < rowstride; j = j + bpp) {
			level = RED_LEVEL + LEVEL;
			RED_LEVEL = (level > 255) ? 0 : level;

		}
	}
	
	gtk_image_set_from_pixbuf (GTK_IMAGE (image), pb);
	

	gtk_widget_hide (editor_window_get_box (EDITOR_WINDOW (window) ) );
	gtk_widget_show_all (editor_window_get_box (EDITOR_WINDOW (window) ) );
	
}


	/************************************************************************************
	 * 									ASM CALLBACKS DEV								*
	 ************************************************************************************/
void
editor_controller_asmfunc1_callback (GtkWidget * self, gpointer data) {
	GtkWidget * window;
	GtkWidget * image;
	GdkPixbuf * pb;
	gint ht;
	gint wt;
	gint rowstride;
	gint bpp;
	gint chans;
	guchar * pixel;

	window = data;
	image = editor_window_get_image (EDITOR_WINDOW (window));
	if (image == NULL) 
		return;
	
	pb = gtk_image_get_pixbuf (GTK_IMAGE (image));
	
	ht = gdk_pixbuf_get_height (pb);
	wt = gdk_pixbuf_get_width (pb);
	pixel = gdk_pixbuf_get_pixels (pb);
	rowstride = gdk_pixbuf_get_rowstride (pb);
	
	asm_fnc1 (pixel, ht, rowstride);

	gtk_image_set_from_pixbuf (GTK_IMAGE (image), pb);
	

	gtk_widget_hide (editor_window_get_box (EDITOR_WINDOW (window) ) );
	gtk_widget_show_all (editor_window_get_box (EDITOR_WINDOW (window) ) );
	
}

void
editor_controller_asmfunc2_callback (GtkWidget * self, gpointer data) {
	GtkWidget * window;
	GtkWidget * image;
	GdkPixbuf * pb;
	gint ht;
	gint wt;
	gint rowstride;
	gint bpp;
	gint chans;
	guchar * pixel;

	window = data;
	image = editor_window_get_image (EDITOR_WINDOW (window));
	if (image == NULL) 
		return;
	
	pb = gtk_image_get_pixbuf (GTK_IMAGE (image));
	
	ht = gdk_pixbuf_get_height (pb);
	pixel = gdk_pixbuf_get_pixels (pb);
	rowstride = gdk_pixbuf_get_rowstride (pb);
	
	asm_fnc2 (pixel, ht, rowstride);

	gtk_image_set_from_pixbuf (GTK_IMAGE (image), pb);
	

	gtk_widget_hide (editor_window_get_box (EDITOR_WINDOW (window) ) );
	gtk_widget_show_all (editor_window_get_box (EDITOR_WINDOW (window) ) );
	
}

void
editor_controller_asmfunc3_callback (GtkWidget * self, gpointer data) {
	GtkWidget * window;
	GtkWidget * image;
	GdkPixbuf * pb;
	gint ht;
	gint wt;
	gint rowstride;
	gint bpp;
	gint chans;
	guchar * pixel;

	window = data;
	image = editor_window_get_image (EDITOR_WINDOW (window));
	if (image == NULL) 
		return;
	
	pb = gtk_image_get_pixbuf (GTK_IMAGE (image));
	
	ht = gdk_pixbuf_get_height (pb);
	pixel = gdk_pixbuf_get_pixels (pb);
	rowstride = gdk_pixbuf_get_rowstride (pb);
	
	asm_fnc3 (pixel, ht, rowstride);

	gtk_image_set_from_pixbuf (GTK_IMAGE (image), pb);
	

	gtk_widget_hide (editor_window_get_box (EDITOR_WINDOW (window) ) );
	gtk_widget_show_all (editor_window_get_box (EDITOR_WINDOW (window) ) );
	
}


void
editor_controller_asmfunc4_callback (GtkWidget * self, gpointer data) {
	GtkWidget * window;
	GtkWidget * image;
	GdkPixbuf * pb;
	gint ht;
	gint wt;
	gint rowstride;
	gint bpp;
	gint chans;
	guchar * pixel;

	window = data;
	image = editor_window_get_image (EDITOR_WINDOW (window));
	if (image == NULL) 
		return;
	
	pb = gtk_image_get_pixbuf (GTK_IMAGE (image));
	
	ht = gdk_pixbuf_get_height (pb);
	pixel = gdk_pixbuf_get_pixels (pb);
	rowstride = gdk_pixbuf_get_rowstride (pb);
	
	asm_fnc4 (pixel, ht, rowstride);

	gtk_image_set_from_pixbuf (GTK_IMAGE (image), pb);
	

	gtk_widget_hide (editor_window_get_box (EDITOR_WINDOW (window) ) );
	gtk_widget_show_all (editor_window_get_box (EDITOR_WINDOW (window) ) );
	
}


/*
 * **@brief:
 * This function connects all the callbacks to its respective signal event
 */
void
editor_controller_connect_signals (EditorController * self) {
	EditorControllerPrivate * priv = EDITOR_CONTROLLER_GET_PRIVATE (self);
	GtkWidget * window;
	GtkWidget * MenuBar;

	window = priv->Window;
	MenuBar = editor_window_get_menubar (EDITOR_WINDOW (window));

		
	/************************************************************************************
	 * 									MISC CALLBACKS 									*
	 ************************************************************************************/

	g_signal_connect (editor_menubar_get_openitem (EDITOR_MENU_BAR (MenuBar)), 
	                  "activate", 
	                  G_CALLBACK ( editor_controller_open_callback ),
					  window);
	
	g_signal_connect (editor_menubar_get_aboutitem (EDITOR_MENU_BAR (MenuBar)),
					  "activate",
					  G_CALLBACK (editor_controller_about_dialog_callback), NULL);
	/* Exit when the window is closed */
	g_signal_connect (editor_menubar_get_exititem (EDITOR_MENU_BAR (MenuBar)), 
	                  "activate",
	                  G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	
	/************************************************************************************
	 * 									C CALLBACKS 									*
	 ************************************************************************************/

	g_signal_connect (editor_menubar_get_cppf1 (EDITOR_MENU_BAR (MenuBar)),
	                  "activate",
	                  G_CALLBACK ( editor_controller_cppfunc1_callback ),
	                  window);
	
	g_signal_connect (editor_menubar_get_cppf2 (EDITOR_MENU_BAR (MenuBar)),
	                  "activate",
	                  G_CALLBACK ( editor_controller_cppfunc2_callback ),
	                  window);                                           
	
	g_signal_connect (editor_menubar_get_cppf3 (EDITOR_MENU_BAR (MenuBar)),
	                  "activate",
	                  G_CALLBACK ( editor_controller_cppfunc3_callback ),
	                  window);
	
/*	g_signal_connect (editor_menubar_get_cppf4 (EDITOR_MENU_BAR (MenuBar)),
	                  "activate",
	                  G_CALLBACK (editor_controller_cppfunc4_callback ),
	                  window);    */
	
	/************************************************************************************
	 * 									Asm callbacks 									*
	 ************************************************************************************/

	g_signal_connect (editor_menubar_get_asm1 (EDITOR_MENU_BAR (MenuBar)),
	                  "activate",
	                  G_CALLBACK (editor_controller_asmfunc1_callback ),
	                  window);    
	g_signal_connect (editor_menubar_get_asm2 (EDITOR_MENU_BAR (MenuBar)),
	                  "activate",
	                  G_CALLBACK (editor_controller_asmfunc2_callback ),
	                  window);    
	g_signal_connect (editor_menubar_get_asm3 (EDITOR_MENU_BAR (MenuBar)),
	                  "activate",
	                  G_CALLBACK (editor_controller_asmfunc3_callback ),
	                  window);    
	g_signal_connect (editor_menubar_get_asm4 (EDITOR_MENU_BAR (MenuBar)),
	                  "activate",
	                  G_CALLBACK (editor_controller_asmfunc4_callback ),
	                  window);   
	
}

GtkWidget *
editor_controller_get_window (EditorController * self) {
	return EDITOR_CONTROLLER_GET_PRIVATE (self)->Window;
}


static void
editor_controller_init (EditorController * self) {
	self->priv = EDITOR_CONTROLLER_GET_PRIVATE (self);
	EditorControllerPrivate * priv = self->priv;

	priv->Window = editor_window_new ();

	editor_controller_connect_signals (self);

}

static void
editor_controller_finalize (GObject * object) {

	G_OBJECT_CLASS (editor_controller_parent_class)->finalize (object);
}

static void
editor_controller_class_init (EditorControllerClass * klass) {
	GObjectClass* object_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (EditorControllerPrivate));

	object_class->finalize = editor_controller_finalize;
}

GObject *
editor_controller_new (void) {
	return g_object_new (EDITOR_TYPE_CONTROLLER, NULL);
}

