/*
 *  nautilus-srm - a nautilus extension to wipe file(s) with srm
 * 
 *  Copyright (C) 2009-2010 Colomban Wendling <ban@herbesfolles.org>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public
 *  License as published by the Free Software Foundation; either
 *  version 3 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

/* Contains compatibility things for old GTK and Nautilus */

#ifndef NAUTILUS_SRM_COMPAT_H
#define NAUTILUS_SRM_COMPAT_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <glib.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS


/* GTK stuff */

#if ! GTK_CHECK_VERSION(2, 14, 0)
# define gtk_dialog_get_action_area(dialog)   ((dialog)->action_area)
# define gtk_dialog_get_content_area(dialog)  ((dialog)->vbox)
#endif /* ! GTK_CHECK_VERSION(2, 14, 0) */

#if ! GTK_CHECK_VERSION (2, 18, 0)
# define gtk_widget_get_sensitive(w) (GTK_WIDGET_SENSITIVE (w))
#endif /* ! GTK_CHECK_VERSION (2, 18, 0) */


/* Nautilus stuff */

#if ! (defined (HAVE_NAUTILUS_FILE_INFO_GET_LOCATION) && \
       HAVE_NAUTILUS_FILE_INFO_GET_LOCATION)
# undef HAVE_NAUTILUS_FILE_INFO_GET_LOCATION
# define HAVE_NAUTILUS_FILE_INFO_GET_LOCATION 1

#include <gio/gio.h>
#include <libnautilus-extension/nautilus-file-info.h>

static GFile *
nautilus_file_info_get_location (NautilusFileInfo *nfi)
{
  GFile *file;
  gchar *uri;
  
  uri = nautilus_file_info_get_uri (nfi);
  file = g_file_new_for_uri (uri);
  g_free (uri);
  
  return file;
}
#endif /* HAVE_NAUTILUS_FILE_INFO_GET_LOCATION */


G_END_DECLS

#endif /* guard */
