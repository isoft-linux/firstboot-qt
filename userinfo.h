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

#ifndef USERINFO_H
#define USERINFO_H
#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <gtk/gtk.h>

class ConfigPageInfo : public QWidget
{
    Q_OBJECT
public:
    ConfigPageInfo(QWidget *parent = 0);
private:
    QLineEdit *m_compNameLineEdit;
    QLineEdit *m_userNameLineEdit;
    QLineEdit *m_pwdLineEdit;
    QLineEdit *m_cfmPwdLineEdit;
    QCheckBox *m_autoLoginBox;
    QLabel    *m_errInfoLabel;
    QTimer    *m_cleanErrInfoTimer;
    QPushButton *returnButton;
    QPushButton *m_nextButton;
    bool addUserAccount();
    int  setAutoLogin();
    QLineEdit *m_rootPwdLineEdit;
    QLineEdit *m_rootPwdLineEdit2;

public Q_SLOTS:
    void btnClicked(int index);

private Q_SLOTS:
    void skipIt();
    void retIt();
    void nextIt();
    void exitIt();
    void cleanupTimerFun();
    bool slotCheckPwd();
    bool slotCheckPwdRoot();

Q_SIGNALS:
    void explains();
    void sigPageChged(int index);
};


#endif
