/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * editor-menu-bar.h
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

#ifndef _EDITOR_MENU_BAR_H_
#define _EDITOR_MENU_BAR_H_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define EDITOR_TYPE_MENU_BAR             (editor_menubar_get_type ())
#define EDITOR_MENU_BAR(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), EDITOR_TYPE_MENU_BAR, EditorMenuBar))
#define EDITOR_MENU_BAR_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), EDITOR_TYPE_MENU_BAR, EditorMenuBarClass))
#define EDITOR_IS_MENU_BAR(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EDITOR_TYPE_MENU_BAR))
#define EDITOR_IS_MENU_BAR_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), EDITOR_TYPE_MENU_BAR))
#define EDITOR_MENU_BAR_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), EDITOR_TYPE_MENU_BAR, EditorMenuBarClass))
#define EDITOR_MENU_BAR_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), EDITOR_TYPE_MENU_BAR, EditorMenuBarPrivate))

typedef struct _EditorMenuBarClass EditorMenuBarClass;
typedef struct _EditorMenuBar EditorMenuBar;
typedef struct _EditorMenuBarPrivate EditorMenuBarPrivate;


struct _EditorMenuBarClass {
	GtkMenuBarClass parent_class;
};

struct _EditorMenuBar {
	GtkMenuBar parent_instance;

	EditorMenuBarPrivate * priv;
};

GType editor_menubar_get_type (void) G_GNUC_CONST;
GtkWidget * editor_menubar_new (void);

GtkWidget * editor_menubar_get_openitem (EditorMenuBar * self);
GtkWidget * editor_menubar_get_exititem (EditorMenuBar * self);
GtkWidget * editor_menubar_get_aboutitem (EditorMenuBar * self);

GtkWidget * editor_menubar_get_cf1 (EditorMenuBar * self);
GtkWidget * editor_menubar_get_cf2 (EditorMenuBar * self);
GtkWidget * editor_menubar_get_cf3 (EditorMenuBar * self);
GtkWidget * editor_menubar_get_cf4 (EditorMenuBar * self);
GtkWidget * editor_menubar_get_cf5 (EditorMenuBar * self);

GtkWidget * editor_menubar_get_asm1 (EditorMenuBar * self);
GtkWidget * editor_menubar_get_asm2 (EditorMenuBar * self);
GtkWidget * editor_menubar_get_asm3 (EditorMenuBar * self);
GtkWidget * editor_menubar_get_asm4 (EditorMenuBar * self);
GtkWidget * editor_menubar_get_asm5 (EditorMenuBar * self);

G_END_DECLS

#endif /* _EDITOR_MENU_BAR_H_ */

