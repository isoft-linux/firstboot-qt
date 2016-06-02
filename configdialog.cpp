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

#include "welcome.h"
#include "configdialog.h"
#include "lang.h"
#include "timezone.h"
#include "userinfo.h"

ConfigDialog::ConfigDialog()
{
    m_current = 0;
    m_pagesWidget = new QStackedWidget;
    //ConfigPageWelcome * pageWelcome = new ConfigPageWelcome;
    //m_pagesWidget->addWidget(pageWelcome);

    ConfigPageLang * pageLang = new ConfigPageLang;
    m_pagesWidget->addWidget(pageLang);
#if 0
    ConfigPageTimezone *pageTimezone = new ConfigPageTimezone;
    m_pagesWidget->addWidget(pageTimezone);
    ConfigPageInfo *pageInfo  = new ConfigPageInfo;
    m_pagesWidget->addWidget(pageInfo);
    m_pagesWidget->setCurrentIndex(m_current);
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(m_pagesWidget, 1);

    //connect(pageWelcome, SIGNAL(sigPageChged(int)), this, SLOT(pagesChanged(int)));
    connect(pageLang, SIGNAL(sigPageChged(int)), this, SLOT(pagesChanged(int)));
    connect(pageTimezone, SIGNAL(sigPageChged(int)), this, SLOT(pagesChanged(int)));
    connect(pageInfo, SIGNAL(sigPageChged(int)), this, SLOT(pagesChanged(int)));
#else
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(m_pagesWidget, 1);
    ConfigPageTimezone *pageTimezone = new ConfigPageTimezone;
    m_pagesWidget->addWidget(pageTimezone);
    ConfigPageInfo *pageInfo  = new ConfigPageInfo;
    m_pagesWidget->addWidget(pageInfo);

    m_pagesWidget->setCurrentIndex(m_current);

    connect(pageLang, SIGNAL(sigPageChged(int)), this, SLOT(pagesChanged(int)));
    connect(pageTimezone, SIGNAL(sigPageChged(int)), this, SLOT(pagesChanged(int)));
    connect(pageInfo, SIGNAL(sigPageChged(int)), this, SLOT(pagesChanged(int)));

#endif
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);

    setLayout(mainLayout);

    setWindowTitle(i18n("Config Dialog"));

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState( Qt::WindowFullScreen );

    QImage *orig_bg = new QImage(QString(DATA_PATH"data/images/bg.png"));
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect cr = desktopWidget->availableGeometry();
    int width = cr.width();
    int height = cr.height();
    QPixmap m_bgPixmap = QPixmap::fromImage(*orig_bg);
    QPalette palette = this->palette();
    palette.setBrush(backgroundRole(), QBrush(m_bgPixmap));
    setPalette(palette);
    setAutoFillBackground(true);

    QString styleSheet;
    styleSheet.sprintf("QPushButton{ background-image: url(%s); width: 113px;height:43px;border: 0px;}\n "
                       "QPushButton:hover{ background-image: url(%s); width: 113px;height:43px;border: 0px;}\n "
                       "QPushButton:checked{ background-image: url(%s); width: 113px;height:43px; border: 0px;} ",
                       DATA_PATH"data/images/3.png",
                       DATA_PATH"data/images/2.png",
                       DATA_PATH"data/images/1.png");

    qApp->setStyleSheet(styleSheet);

}

 ConfigDialog::~ConfigDialog()
{

}

void ConfigDialog::pagesChanged(int index)
{
    m_current += index;
    if (m_current < 1 || m_current > 4) {
        m_current = 0;
    }
    m_pagesWidget->setCurrentIndex(m_current);
}

void ConfigDialog::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape) {
        return;
    }

}
void ConfigDialog::closeEvent(QCloseEvent *event)
{
    event->ignore();
}
