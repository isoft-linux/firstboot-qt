#include "utils.h"
#include <gtk/gtk.h>
#include <locale.h>
#include <string.h>
#define GNOME_DESKTOP_USE_UNSTABLE_API
#include <fontconfig/fontconfig.h>
#include <gtk/gtk.h>
gboolean
cc_common_language_has_font (const gchar *locale)
{
return TRUE;
/*
    const FcCharSet *charset;
    FcPattern       *pattern;
    FcObjectSet     *object_set;
    FcFontSet       *font_set;
    gchar           *language_code;
    gboolean         is_displayable;

    is_displayable = FALSE;
    pattern = NULL;
    object_set = NULL;
    font_set = NULL;

    if (!gnome_parse_locale (locale, &language_code, NULL, NULL, NULL))
            return FALSE;

    charset = FcLangGetCharSet ((FcChar8 *) language_code);
    if (!charset)
    {
        is_displayable = TRUE;
    }
    else
    {
        pattern = FcPatternBuild (NULL, FC_LANG, FcTypeString, language_code, NULL);

        if (pattern == NULL)
                goto done;

        object_set = FcObjectSetCreate ();

        if (object_set == NULL)
                goto done;

        font_set = FcFontList (NULL, pattern, object_set);

        if (font_set == NULL)
                goto done;

        is_displayable = (font_set->nfont > 0);
    }

done:
    if (font_set != NULL)
        FcFontSetDestroy (font_set);

    if (object_set != NULL)
        FcObjectSetDestroy (object_set);

    if (pattern != NULL)
        FcPatternDestroy (pattern);

    g_free (language_code);

    return is_displayable;
*/
}

static void
insert_language_internal (GHashTable *ht,
                          const char *lang)
{
return;
/*
    gboolean has_translations;
    char *label_own_lang;
    char *label_current_lang;
    char *label_untranslated;
    char *key;

    has_translations = gnome_language_has_translations (lang);
    if (!has_translations) {
            char *lang_code = g_strndup (lang, 2);
            has_translations = gnome_language_has_translations (lang_code);
            g_free (lang_code);

            if (!has_translations)
                    return;
    }

    g_debug ("We have translations for %s", lang);

    key = g_strdup (lang);

    label_own_lang = gnome_get_language_from_locale (key, key);
    label_current_lang = gnome_get_language_from_locale (key, NULL);
    label_untranslated = gnome_get_language_from_locale (key, "C");

    if (g_strcmp0 (label_own_lang, label_untranslated) == 0)
    {
        if (g_strcmp0 (label_current_lang, label_untranslated) == 0)
            g_hash_table_insert (ht, key, g_strdup (label_untranslated));
        else
            g_hash_table_insert (ht, key, g_strdup (label_current_lang));
    }
    else
    {
        g_hash_table_insert (ht, key, g_strdup (label_own_lang));
    }

    g_free (label_own_lang);
    g_free (label_current_lang);
    g_free (label_untranslated);
*/
}

static void
insert_language (GHashTable *ht,
                 const char *lang)
{
    char *utf8_variant = g_strconcat (lang, ".utf8", NULL);
    insert_language_internal (ht, lang);
    insert_language_internal (ht, utf8_variant);
    g_free (utf8_variant);
}



GHashTable *
cc_common_language_get_initial_languages ()
{
    GHashTable *ht;

    ht = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);

    insert_language (ht, "en_US");
//    insert_language (ht, "de_DE");
//    insert_language (ht, "fr_FR");
//    insert_language (ht, "es_ES");
    insert_language (ht, "zh_CN");
//    insert_language (ht, "ja_JP");
//    insert_language (ht, "ru_RU");
//    insert_language (ht, "ar_EG");

//    insert_user_languages (ht);

    return ht;
}

