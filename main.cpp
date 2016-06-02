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

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <QApplication>

#include "configdialog.h"

#define ENV_LANG_VALUE "LANG"

#define FB_LOG_FILE "/var/log/firstboot.log"
extern bool g_isChinese;
int main(int argc, char *argv[])
{
    char cmd[512]="";
    setuid(0);
    QByteArray lang = qgetenv(ENV_LANG_VALUE);
    if (lang.isEmpty()) {
        sprintf(cmd,"echo \"lang is empty,set it.\" >> %s",FB_LOG_FILE);
        // i18n use LANG.
        qputenv(ENV_LANG_VALUE,"zh_CN.UTF-8");
        g_isChinese = true;
    } else {
        QString str = lang;
        char lang[128]="";
        snprintf(lang,sizeof(lang),"%s",qPrintable(str));
        sprintf(cmd,"echo \"lang is[%s].\" >> %s",lang,FB_LOG_FILE);

        if(strcasecmp(lang,"zh_CN.UTF-8") == 0) {
            g_isChinese = true;
        } else {
            g_isChinese = false;
        }

        printf("lang is [%s],[%s].\n",lang,g_isChinese?"cn":"en");
    }

    system(cmd);


    QApplication app(argc, argv);

    ConfigDialog dialog;
    dialog.show();
    return app.exec();
}
