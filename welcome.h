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


#ifndef WELCOME_H
#define WELCOME_H
#include <QObject>
#include <QWidget>
#include <QTimeZone>
#include <QLabel>

#ifdef __cplusplus
extern "C" {
#endif
    #include "tz_config.h"

#ifdef __cplusplus
}
#endif


class ConfigPageWelcome : public QWidget
{
    Q_OBJECT

public:
    ConfigPageWelcome(QWidget *parent = 0);

private:
    QLabel    *m_WelcomeLabel;
    QTimer    *m_closeTimer;

private Q_SLOTS:
    void closeTimerFun();

Q_SIGNALS:
    void explains();
    void sigPageChged(int index);
};



#endif
