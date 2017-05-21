/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * editor-menu-bar.c
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

#include "editor-menu-bar.h"

struct _EditorMenuBarPrivate {
	 GtkWidget * OpenItem;
	 GtkWidget * ExitItem;
	 GtkWidget * AboutItem;
	 
	 GtkWidget * CppFunc1;
	 GtkWidget * CppFunc2;
	 GtkWidget * CppFunc3;
	 GtkWidget * CppFunc4;

	 GtkWidget * AsmFunc1;
	 GtkWidget * AsmFunc2;
	 GtkWidget * AsmFunc3;
	 GtkWidget * AsmFunc4;

	 GtkWidget * LittleTrick;
	 
};

G_DEFINE_TYPE (EditorMenuBar, editor_menubar, GTK_TYPE_MENU_BAR);

GtkWidget *
editor_menubar_get_exititem (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->ExitItem;
}

GtkWidget *
editor_menubar_get_aboutitem (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->AboutItem;
}

GtkWidget *
editor_menubar_get_openitem (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->OpenItem;
}

GtkWidget *
editor_menubar_get_cppf1 (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->CppFunc1;
}

GtkWidget *
editor_menubar_get_cppf2 (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->CppFunc2;
}

GtkWidget *
editor_menubar_get_cppf3 (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->CppFunc3;
}

GtkWidget *
editor_menubar_get_cppf4 (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->CppFunc4;
}

GtkWidget *
editor_menubar_get_asm1 (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->AsmFunc1;
}


GtkWidget *
editor_menubar_get_asm2 (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->AsmFunc2;
}

GtkWidget *
editor_menubar_get_asm3 (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->AsmFunc3;
}

GtkWidget *
editor_menubar_get_asm4 (EditorMenuBar * self) {
	return EDITOR_MENU_BAR_GET_PRIVATE (self)->AsmFunc4;
}


static void
editor_menubar_init (EditorMenuBar * self) {
	self->priv = EDITOR_MENU_BAR_GET_PRIVATE (self);
	
	GtkWidget * Menu;
	GtkWidget * MenuItem;
	Menu = gtk_menu_new ();
	MenuItem = gtk_menu_item_new_with_mnemonic ("_File");
	
	self->priv->OpenItem = gtk_menu_item_new_with_mnemonic ("_Open");
	self->priv->ExitItem = gtk_menu_item_new_with_mnemonic ("_Exit");
	self->priv->AboutItem = gtk_menu_item_new_with_mnemonic ("_About");

	GtkWidget * separator = gtk_separator_menu_item_new ();

	gtk_menu_item_set_submenu (GTK_MENU_ITEM (MenuItem), Menu);

	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->OpenItem);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->AboutItem);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), separator);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->ExitItem);

	gtk_menu_shell_append (GTK_MENU_SHELL (self), MenuItem);
	
	Menu = gtk_menu_new ();
	MenuItem = gtk_menu_item_new_with_mnemonic ("_C++");
	
	self->priv->CppFunc1 = gtk_menu_item_new_with_mnemonic ("func_1_");
	self->priv->CppFunc2 = gtk_menu_item_new_with_mnemonic ("func_2_");
	self->priv->CppFunc3 = gtk_menu_item_new_with_mnemonic ("func_3_");
	self->priv->CppFunc4 = gtk_menu_item_new_with_mnemonic ("func_4_");


	gtk_menu_item_set_submenu (GTK_MENU_ITEM (MenuItem), Menu);

	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->CppFunc1);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->CppFunc2);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->CppFunc3);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->CppFunc4);

	gtk_menu_shell_append (GTK_MENU_SHELL (self), MenuItem);

	Menu = gtk_menu_new ();
	MenuItem = gtk_menu_item_new_with_mnemonic ("_Asm");
	
	self->priv->AsmFunc1 = gtk_menu_item_new_with_mnemonic ("func_1_");
	self->priv->AsmFunc2 = gtk_menu_item_new_with_mnemonic ("func_2_");
	self->priv->AsmFunc3 = gtk_menu_item_new_with_mnemonic ("func_3_");
	self->priv->AsmFunc4 = gtk_menu_item_new_with_mnemonic ("func_4_");


	gtk_menu_item_set_submenu (GTK_MENU_ITEM (MenuItem), Menu);

	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->AsmFunc1);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->AsmFunc2);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->AsmFunc3);
	gtk_menu_shell_append (GTK_MENU_SHELL (Menu), self->priv->AsmFunc4);

	gtk_menu_shell_append (GTK_MENU_SHELL (self), MenuItem);

	Menu = gtk_menu_new ();
	self->priv->LittleTrick = gtk_menu_item_new_with_mnemonic ("LittleTrick");

	gtk_menu_shell_append (GTK_MENU_SHELL (self), self->priv->LittleTrick);
	
	
}

static void
editor_menubar_finalize (GObject *object) {
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (editor_menubar_parent_class)->finalize (object);
}

static void
editor_menubar_class_init (EditorMenuBarClass *klass) {
	GObjectClass* object_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (EditorMenuBarPrivate));

	object_class->finalize = editor_menubar_finalize;
}

GtkWidget *
editor_menubar_new (void) {
	 return GTK_WIDGET(g_object_new (EDITOR_TYPE_MENU_BAR, NULL));
}

