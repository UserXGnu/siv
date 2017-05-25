/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * editor-window.h
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

#ifndef _EDITOR_WINDOW_H_
#define _EDITOR_WINDOW_H_

#include <gtk/gtk.h>

#include "definitions.h"

G_BEGIN_DECLS

#define EDITOR_TYPE_WINDOW             (editor_window_get_type ())
#define EDITOR_WINDOW(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), EDITOR_TYPE_WINDOW, EditorWindow))
#define EDITOR_WINDOW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), EDITOR_TYPE_WINDOW, EditorWindowClass))
#define EDITOR_IS_WINDOW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EDITOR_TYPE_WINDOW))
#define EDITOR_IS_WINDOW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), EDITOR_TYPE_WINDOW))
#define EDITOR_WINDOW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), EDITOR_TYPE_WINDOW, EditorWindowClass))
#define EDITOR_WINDOW_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), EDITOR_TYPE_WINDOW, EditorWindowPrivate))

#define DEFAULT_HEIGHT 	640
#define DEFAULT_WIDTH 	480

typedef struct _EditorWindowClass EditorWindowClass;
typedef struct _EditorWindow EditorWindow;
typedef struct _EditorWindowPrivate EditorWindowPrivate;


struct _EditorWindowClass {
	GtkWindowClass parent_class;
};

struct _EditorWindow {
	GtkWindow parent_instance;

	EditorWindowPrivate *priv;
};

GType editor_window_get_type (void) G_GNUC_CONST;
GtkWidget * editor_window_new (void);

GtkWidget * editor_window_get_image (EditorWindow * self);
GtkWidget * editor_window_get_menubar (EditorWindow * self);
GtkWidget * editor_window_get_box (EditorWindow * self);

void editor_window_set_image ( EditorWindow * self, GtkWidget * image);

G_END_DECLS

#endif /* _EDITOR_WINDOW_H_ */

