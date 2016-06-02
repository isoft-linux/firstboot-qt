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

#include "welcome.h"

#define CLOSE_WELCOME_TIMEINTERVAL 1000

ConfigPageWelcome::ConfigPageWelcome(QWidget *parent)
    : QWidget(parent)
{
    m_WelcomeLabel = new QLabel("");

    QImage *orig_bg = new QImage(QString(DATA_PATH"data/timezone/welcome.png"));
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect cr = desktopWidget->availableGeometry();
    int width = cr.width() -80;
    int height = cr.height() -80;

    QImage scaled_bg = orig_bg->scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    m_WelcomeLabel->setPixmap(QPixmap::fromImage(scaled_bg));

    QHBoxLayout *upLayout = new QHBoxLayout;
    QSpacerItem* hSpacerLeft1=
            new QSpacerItem(30, 30,
                            QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSpacerItem* hSpacerRight1=
            new QSpacerItem(30, 30,
                            QSizePolicy::Expanding, QSizePolicy::Expanding);
    upLayout->addSpacerItem(hSpacerLeft1);
    upLayout->addWidget(m_WelcomeLabel);
    upLayout->addSpacerItem(hSpacerRight1);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    QSpacerItem* hSpacerTop=
            new QSpacerItem(20, 10,
                            QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addSpacerItem(hSpacerTop);
    mainLayout->addLayout(upLayout);
    QSpacerItem* vSpacerBotton=
            new QSpacerItem(20, 10,
                            QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addSpacerItem(vSpacerBotton);

    setLayout(mainLayout);

    m_closeTimer = new QTimer(this);
    connect( m_closeTimer, SIGNAL(timeout()), SLOT(closeTimerFun()) );

    m_closeTimer->start( CLOSE_WELCOME_TIMEINTERVAL );

}


void ConfigPageWelcome::closeTimerFun()
{
    m_closeTimer->stop();
    Q_EMIT sigPageChged(1);
}


