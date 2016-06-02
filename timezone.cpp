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


#include <QtWidgets>
#include <QObject>
#include <klocalizedstring.h>
#include "timezone.h"

#define PIN_HOT_POINT_X 8
#define PIN_HOT_POINT_Y 14

#define DISPLAY_LABEL_LEN 128
static char g_location_str[DISPLAY_LABEL_LEN] ="";
static char g_timezone_str[DISPLAY_LABEL_LEN] ="";

ConfigPageTimezone::ConfigPageTimezone(QWidget *parent)
    : QWidget(parent)
{

    ZoneLabel *m_timezoneLabel = new ZoneLabel();
    connect(m_timezoneLabel, SIGNAL(sigZoneLabelChged()), this, SLOT(showZoneLabel()));

    // begin
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QGridLayout *gridLayout;
    QLabel *label;
    //QLabel *m_cityNameLabel;
    QLabel *label_2;
    //QLabel *m_continetLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *skipButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *returnButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    formLayout = new QFormLayout;

    formLayout->setObjectName(QStringLiteral("formLayout"));
    verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

    formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
    horizontalSpacer_7 = new QSpacerItem(34, 37, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer_7);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    label = new QLabel;
    label->setObjectName(QStringLiteral("label"));
    QFont font;
    font.setPointSize(12);
    label->setFont(font);
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(label, 0, 0, 1, 1);

    m_cityNameLabel = new QLabel;
    m_cityNameLabel->setObjectName(QStringLiteral("m_cityNameLabel"));
    m_cityNameLabel->setFont(font);

    gridLayout->addWidget(m_cityNameLabel, 0, 1, 1, 1);

    label_2 = new QLabel;
    label_2->setObjectName(QStringLiteral("label_2"));
    label_2->setFont(font);
    label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    m_continetLabel = new QLabel;
    m_continetLabel->setObjectName(QStringLiteral("m_continetLabel"));
    m_continetLabel->setFont(font);

    gridLayout->addWidget(m_continetLabel, 1, 1, 1, 1);

    //ZoneLabel *m_timezoneLabel = new ZoneLabel();
    //connect(m_timezoneLabel, SIGNAL(sigZoneLabelChged()), this, SLOT(showZoneLabel()));

    verticalLayout->addWidget(m_timezoneLabel);

    verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout->addItem(verticalSpacer_4);


    verticalLayout->addLayout(gridLayout);


    horizontalLayout_2->addLayout(verticalLayout);

    horizontalSpacer = new QSpacerItem(128, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer);


    formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout_2);

    verticalSpacer_2 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Fixed);

    formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer_2);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    horizontalSpacer_4 = new QSpacerItem(241, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_4);

    skipButton = new QPushButton;
    skipButton->setObjectName(QStringLiteral("skipButton"));
    sizePolicy.setHeightForWidth(skipButton->sizePolicy().hasHeightForWidth());
    skipButton->setSizePolicy(sizePolicy);

    horizontalLayout->addWidget(skipButton);

    horizontalSpacer_9 = new QSpacerItem(150, 28, QSizePolicy::Preferred, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_9);

    returnButton = new QPushButton;
    returnButton->setObjectName(QStringLiteral("returnButton"));
    sizePolicy.setHeightForWidth(returnButton->sizePolicy().hasHeightForWidth());
    returnButton->setSizePolicy(sizePolicy);

    horizontalLayout->addWidget(returnButton);

    horizontalSpacer_6 = new QSpacerItem(150, 28, QSizePolicy::Preferred, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_6);

    nextButton = new QPushButton;
    nextButton->setObjectName(QStringLiteral("nextButton"));
    sizePolicy.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
    nextButton->setSizePolicy(sizePolicy);

    horizontalLayout->addWidget(nextButton);

    horizontalSpacer_5 = new QSpacerItem(241, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_5);


    formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout);

    horizontalSpacer_3 = new QSpacerItem(1009, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    formLayout->setItem(6, QFormLayout::FieldRole, horizontalSpacer_3);

    verticalSpacer_3 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

    formLayout->setItem(7, QFormLayout::FieldRole, verticalSpacer_3);

    // end

    label->setText(i18n("Location:"));
    label_2->setText(i18n("Timezone:"));
    skipButton->setText(i18n("Skip"));
    returnButton->setText(i18n("Previous"));
    nextButton->setText(i18n("Next"));

    font.setPointSize(16);
    m_cityNameLabel->setFont(font);
    label->setFont(font);
    label_2->setFont(font);
    m_continetLabel->setFont(font);

    font.setWeight(QFont::Normal);
    skipButton->setFont(font);
    returnButton->setFont(font);
    nextButton->setFont(font);

    setLayout(formLayout);
    connect(skipButton, SIGNAL(clicked()), this, SLOT(skipIt()));
    connect(returnButton, SIGNAL(clicked()), this, SLOT(retIt()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextIt()));

    // set shanghai@+8
    m_timezoneLabel->setDefaultZone(635,189);

}

void ConfigPageTimezone::showZoneLabel()
{
    m_cityNameLabel->setText(g_location_str);
    m_continetLabel->setText(g_timezone_str);
}


void ConfigPageTimezone::skipIt()
{
    btnClicked(1);
}

void ConfigPageTimezone::retIt()
{
    btnClicked(-1);
}

void ConfigPageTimezone::nextIt()
{
    char cmd[512]="";
    if (g_timezone_str[0] != 0) {
        snprintf(cmd,sizeof(cmd),"timedatectl set-timezone  \"%s\" ",g_timezone_str);
        int ret = system(cmd);//printf("\n timezone[%s]\n",cmd);
        if (ret != 0) {
            // try again
            ret = system(cmd);
            if (ret != 0) {
                QMessageBox::warning(this, i18n("error"),
                    i18n("Fail to set timezone, please try it manually."));
            }
        }
    }

    btnClicked(1);
}

void ConfigPageTimezone::btnClicked(int index)
{
     Q_EMIT sigPageChged(index);
}


ZoneLabel::ZoneLabel(QWidget * parent,Qt::WindowFlags f)
    : QLabel(parent)
{
    m_location = NULL;
    m_orig_background = new  QImage(QString(DATA_PATH"data/timezone/bg.png"));
    m_orig_background_dim = new QImage (QString(DATA_PATH"data/timezone/bg_dim.png"));

    m_width = m_orig_background_dim->width();
    m_height = m_orig_background_dim->height();

    m_background = m_orig_background->scaled(m_width, m_height,
        Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    m_orig_color_map = new QImage(QString(DATA_PATH"data/timezone/cc.png"));

    m_width = m_orig_color_map->width();
    m_height = m_orig_color_map->height();
    m_color_map = m_orig_color_map->scaled(m_width, m_height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);


    m_visible_map_pixels = new  QPixmap(QString(DATA_PATH"data/timezone/bg.png"));
    m_tzdb = tz_load_db ();
    m_prefered_width = 400;
    setPixmap(QPixmap::fromImage(*m_orig_background));

}

void ZoneLabel::mousePressEvent(QMouseEvent *e)
{
    gint x, y;
    guchar r, g, b, a;
    guchar *pixels;
    gint rowstride;
    gint i;
    const GPtrArray *array;
    gint width, height;
    GList *distances = NULL;
    GtkAllocation alloc;

    x = e->x();
    y = e->y();

    //printf("\ntrace:%s,%d,xy[%d][%d].\n",__FUNCTION__,__LINE__,x,y); //trace:mousePressEvent,222,xy[635][189].

    //rowstride = priv->visible_map_rowstride;
    //priv->visible_map_rowstride = gdk_pixbuf_get_rowstride (priv->color_map);
    rowstride = 3200;

    width = m_orig_color_map->width();
    height = m_orig_color_map->height();

    pixels = (unsigned char *)m_color_map.bits();

    b = pixels[(rowstride * y + x * 4)];
    g = pixels[(rowstride * y + x * 4) + 1];
    r = pixels[(rowstride * y + x * 4) + 2];
    a = pixels[(rowstride * y + x * 4) + 3];

    for (i = 0; color_codes[i].offset != -100; i++)
    {
         if (color_codes[i].red == r && color_codes[i].green == g
             && color_codes[i].blue == b && color_codes[i].alpha == a)
         {
             m_selected_offset = color_codes[i].offset;
         }
    }

    array = tz_get_locations (m_tzdb);

    for (i = 0; i < array->len; i++)
    {
        gdouble pointx, pointy, dx, dy;
        TzLocation *loc = (TzLocation *)array->pdata[i];

        pointx = convert_longtitude_to_x (loc->longitude, width);
        pointy = convert_latitude_to_y (loc->latitude, height);

        dx = pointx - x;
        dy = pointy - y;

        loc->dist = dx * dx + dy * dy;
        distances = g_list_prepend (distances, loc);

    }
    distances = g_list_sort (distances, (GCompareFunc) sort_locations);

    set_location ((TzLocation*) distances->data);

    drawLabel();

    g_list_free (distances);
}

void ZoneLabel::set_location (TzLocation    *location)
{
    TzInfo *info = NULL;
    GString *str = NULL;
    gchar *c;
    g_location_str[0] = 0;
    g_timezone_str[0] = 0;

    m_location = location;

    info = tz_info_from_location (m_location);

    m_selected_offset = tz_location_get_utc_offset (m_location)
      / (60.0*60.0) + ((info->daylight) ? -1.0 : 0.0);

    str = g_string_new ("");
    if (!str) {
        goto cleanup;
    }
    for (c = location->zone; *c; c++)
    {
        switch (*c)
        {
        case '_':
            g_string_append_c (str, ' ');
            break;
        case '/':
            g_string_append (str, " / ");
            break;
        default:
            g_string_append_c (str, *c);
        }
    }

    if (!str->str) {
        goto cleanup;
    }

    c = strstr (str->str, " / ");

    if (!c) {
        goto cleanup;
    }

    snprintf(g_location_str,sizeof(g_location_str),"%s",c + 3);
    snprintf(g_timezone_str,sizeof(g_timezone_str),"%s",location->zone);

    Q_EMIT sigZoneLabelChged();

cleanup:
    if(str) {
        g_string_free (str, TRUE);
    }
    if (info) {
        tz_info_free (info);
    }
}


void ZoneLabel::drawLabel()
{
    char selectedFile[512]="";
    int  i = 0;

    QSize resultSize(m_width, m_height);
    QImage resultImage = QImage(resultSize, QImage::Format_ARGB32_Premultiplied);
    QPainter::CompositionMode mode = QPainter::CompositionMode_SourceOver;

    QPainter painterComplex(&resultImage);

    painterComplex.setCompositionMode(QPainter::CompositionMode_Source);
    painterComplex.fillRect(resultImage.rect(), Qt::transparent);
    painterComplex.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painterComplex.drawImage(0, 0, m_background);
    painterComplex.setCompositionMode(mode);

    char buf[32]="";
    snprintf(buf,sizeof(buf),"%g",m_selected_offset);
    for (i = 0;i<strlen(buf); i++) {
        char c = buf[i];
        if (c !='-' && (c > '9' || c < '0' )) {
            buf[i] = '.';
        }
    }

    snprintf(selectedFile,sizeof(selectedFile),DATA_PATH"data/timezone/timezone_%s.png",buf);
    QImage orig_hilight = QImage(selectedFile);
    QImage hilight = orig_hilight.scaled(m_width, m_height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painterComplex.drawImage(0, 0, hilight);
    snprintf(selectedFile,sizeof(selectedFile),DATA_PATH"data/timezone/pin.png");

    QImage pin = QImage(selectedFile);
    gdouble pointx = 0.0, pointy = 0.0;
    if (m_location)
    {
        pointx = convert_longtitude_to_x (m_location->longitude, m_width);
        pointy = convert_latitude_to_y (m_location->latitude, m_height);

        if (pointx > m_width)
            pointx = m_width;
        if (pointy > m_height)
            pointy = m_height;

        painterComplex.drawImage(pointx - PIN_HOT_POINT_X, pointy - PIN_HOT_POINT_Y, pin);
    }

    painterComplex.end();
    setPixmap(QPixmap::fromImage(resultImage));

}

void ZoneLabel::setDefaultZone(int x,int y)
{
    guchar r, g, b, a;
    guchar *pixels;
    gint rowstride;
    gint i;
    const GPtrArray *array;
    gint width, height;
    GList *distances = NULL;
    GtkAllocation alloc;

#if 0 // shanghai
    x = 635;
    y = 189;
    printf("\ntrace:%s,%d,xy[%d][%d].\n",__FUNCTION__,__LINE__,x,y); //trace:mousePressEvent,222,xy[635][189].
#endif

    //rowstride = priv->visible_map_rowstride;
    //priv->visible_map_rowstride = gdk_pixbuf_get_rowstride (priv->color_map);
    rowstride = 3200;

    width = m_orig_color_map->width();
    height = m_orig_color_map->height();

    pixels = (unsigned char *)m_color_map.bits();

    b = pixels[(rowstride * y + x * 4)];
    g = pixels[(rowstride * y + x * 4) + 1];
    r = pixels[(rowstride * y + x * 4) + 2];
    a = pixels[(rowstride * y + x * 4) + 3];

    for (i = 0; color_codes[i].offset != -100; i++)
    {
         if (color_codes[i].red == r && color_codes[i].green == g
             && color_codes[i].blue == b && color_codes[i].alpha == a)
         {
             m_selected_offset = color_codes[i].offset;
         }
    }

    array = tz_get_locations (m_tzdb);

    for (i = 0; i < array->len; i++)
    {
        gdouble pointx, pointy, dx, dy;
        TzLocation *loc = (TzLocation *)array->pdata[i];

        pointx = convert_longtitude_to_x (loc->longitude, width);
        pointy = convert_latitude_to_y (loc->latitude, height);

        dx = pointx - x;
        dy = pointy - y;

        loc->dist = dx * dx + dy * dy;
        distances = g_list_prepend (distances, loc);

    }
    distances = g_list_sort (distances, (GCompareFunc) sort_locations);

    set_location ((TzLocation*) distances->data);

    drawLabel();

    g_list_free (distances);
}
