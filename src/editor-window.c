/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * editor-window.c
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

#include "editor-window.h"
#include "editor-menu-bar.h"

struct _EditorWindowPrivate {
	 GtkWidget * box;
	 GtkWidget * MenuBar;
	 GtkWidget * Image;
	 
};

G_DEFINE_TYPE (EditorWindow, editor_window, GTK_TYPE_WINDOW);

GtkWidget *
editor_window_get_image (EditorWindow * self) {
	return EDITOR_WINDOW_GET_PRIVATE (self)->Image;
}

GtkWidget *
editor_window_get_menubar (EditorWindow * self) {
	return EDITOR_WINDOW_GET_PRIVATE (self)->MenuBar;
}

 GtkWidget *
editor_window_get_box (EditorWindow * self) {
	return EDITOR_WINDOW_GET_PRIVATE (self)->box;
}


void
editor_window_set_image ( EditorWindow * self, GtkWidget * image) {
	EditorWindowPrivate * priv = EDITOR_WINDOW_GET_PRIVATE (self);
 
	if (priv->Image) 
		gtk_widget_destroy (priv->Image);
	
	priv->Image = image;
	//gtk_widget_set_opacity (GTK_WIDGET (priv->Image), 1);
	gtk_box_pack_start (GTK_BOX (priv->box), priv->Image, TRUE, TRUE, 0);
}

static void
editor_window_init (EditorWindow * self) {
	
	self->priv = EDITOR_WINDOW_GET_PRIVATE (self);
	EditorWindowPrivate * priv = self->priv;
	
	gtk_window_set_title (GTK_WINDOW (self), PROGRAM_NAME);
	gtk_window_set_default_size (GTK_WINDOW (self), 640, 480);
	gtk_window_set_resizable (GTK_WINDOW (self), FALSE);
	gtk_widget_set_size_request (GTK_WIDGET (self), 640, 480);
	gtk_window_set_position (GTK_WINDOW (self), GTK_WIN_POS_CENTER_ALWAYS);
	
	priv->MenuBar = editor_menubar_new ();
	
	priv->box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	priv->MenuBar = editor_menubar_new ();
	
	gtk_box_pack_start (GTK_BOX (priv->box), priv->MenuBar, FALSE, TRUE, 0);
	
	gtk_container_add (GTK_CONTAINER (self), priv->box);
	GError * err = NULL;
	GdkPixbuf * pixbuf = gdk_pixbuf_new_from_file (EDITOR_OPENING_IMAGE, &err);
	if (pixbuf == NULL) {
			g_print("[SIMPLE-IMAGE-VIEWER] Warning: %s\n", err->message);
		pixbuf = gdk_pixbuf_new_from_file (EDITOR_ALT_OPENING_IMAGE, &err);
		if (pixbuf == NULL) {
			g_print("[SIMPLE-IMAGE-VIEWER] Warning: %s\n", err->message);
		}
	}
	if (pixbuf != NULL) {
		priv->Image = gtk_image_new_from_pixbuf (pixbuf);
		gtk_widget_set_opacity (GTK_WIDGET (priv->Image), 0.3);
		g_object_unref (pixbuf);
		pixbuf = NULL;
	} else {
		priv->Image = NULL;
	}
}

static void
editor_window_finalize (GObject *object)
{
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (editor_window_parent_class)->finalize (object);
}

static void
editor_window_class_init (EditorWindowClass *klass)
{
	GObjectClass* object_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (EditorWindowPrivate));

	object_class->finalize = editor_window_finalize;
}

GtkWidget *
editor_window_new (void) {
	return GTK_WIDGET(g_object_new (EDITOR_TYPE_WINDOW, NULL));
}
