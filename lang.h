/**
 *  Copyright (C) 2015 fjiang <fujiang.zhu@i-soft.com.cn>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 */

#ifndef LANG_H
#define LANG_H
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

#include <klocalizedstring.h>
#include <gtk/gtk.h>
#define GNOME_DESKTOP_USE_UNSTABLE_API
//#include <libgnome-desktop/gnome-languages.h>
//#include <libgnome-desktop/gnome-xkb-info.h>
#include <fontconfig/fontconfig.h>

#ifdef __cplusplus
extern "C" {
#endif
    GHashTable * cc_common_language_get_initial_languages ();
    gboolean cc_common_language_has_font (const gchar *locale);

#ifdef __cplusplus
}
#endif

class ConfigPageLang : public QWidget
{
    Q_OBJECT
public:
    ConfigPageLang(QWidget *parent = 0);
private:
    QWidget *widLang =  NULL;
    QComboBox *m_langCombo;
    QComboBox *m_keyboardCombo;
    QLabel *tip_label;
    QTimer    *m_cleanErrInfoTimer;
    QPushButton *nextButton;
    QPushButton *skipButton;
    char m_local_id[512];
    char m_kbd_layout[128];
    void insertLang();
    void insertKbd();
    int  addOneItem(const char *locale_id);
    void setCurrentKbd(const char * local_id);
    void add_keybords
                (GList        *list,
                  const gchar  *type,
                  const gchar  *default_id,
                  //GnomeXkbInfo *xkb_info,
                  GHashTable   *inputs);

public Q_SLOTS:
    void btnClicked(int index);

private Q_SLOTS:
    void skipIt();
    void retIt();
    void nextIt();
    void setLocal(int index);
    void setKbd(int index);
    void cleanupTimerFun();

Q_SIGNALS:
    void explains();
    void sigPageChged(int index);
};
#endif
