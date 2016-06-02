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


#ifndef TIMEZONE_H
#define TIMEZONE_H
#include <QObject>
#include <QWidget>
#include <QTimeZone>
#include <QLabel>

#include <gtk/gtk.h>
#define GNOME_DESKTOP_USE_UNSTABLE_API
//#include <libgnome-desktop/gnome-languages.h>
//#include <libgnome-desktop/gnome-xkb-info.h>
#include <fontconfig/fontconfig.h>


#ifdef __cplusplus
extern "C" {
#endif
    #include "tz_config.h"

#ifdef __cplusplus
}
#endif



class ZoneLabel : public QLabel
{
    Q_OBJECT
public:
    ZoneLabel(QWidget * parent = 0, Qt::WindowFlags f = 0);
    void setDefaultZone(int x,int y);
private:
    void drawLabel();
    void set_location (TzLocation    *location);
    QImage  *m_orig_background;
    QImage  *m_orig_background_dim;
    QImage  *m_orig_color_map;

    QImage  m_background;
    QImage  m_color_map;

    QPixmap *m_visible_map_pixels;
    gint m_visible_map_rowstride;

    gdouble m_selected_offset;

    int m_prefered_width;

    TzDB *m_tzdb;
    TzLocation *m_location;
    int  m_width;
    int  m_height;

protected:
    void mousePressEvent(QMouseEvent *);

Q_SIGNALS:
    void sigZoneLabelChged();
};



class ConfigPageTimezone : public QWidget
{
    Q_OBJECT
public:
    ConfigPageTimezone(QWidget *parent = 0);

private:
    QList<QTimeZone> m_zones;
    ZoneLabel m_timezoneLabel;
    QLabel    *m_cityNameLabel;
    QLabel    *m_continetLabel;

public Q_SLOTS:
    void btnClicked(int index);

private Q_SLOTS:
    void skipIt();
    void retIt();
    void nextIt();
    void showZoneLabel();

Q_SIGNALS:
    void explains();
    void sigPageChged(int index);
};



#endif
