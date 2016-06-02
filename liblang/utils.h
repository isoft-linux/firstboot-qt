#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <locale.h>
#include <string.h>
#include <gtk/gtk.h>
#define GNOME_DESKTOP_USE_UNSTABLE_API
//#include <libgnome-desktop/gnome-languages.h>
#include <fontconfig/fontconfig.h>
//#include <gtk/gtk.h>


extern GHashTable *
cc_common_language_get_initial_languages ();
extern gboolean
cc_common_language_has_font (const gchar *locale);

#endif

