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

#include <unistd.h>
#include <sys/reboot.h>
#include <linux/reboot.h>
#include <sys/types.h>
#include <pwd.h>

#include <QtWidgets>
#include <QObject>
#include <klocalizedstring.h>
#include "userinfo.h"
#define CLEAN_ERRINFO_TIMEINTERVAL 3000
#define XSESSION  "/usr/share/xsessions/"
#define SDDM_CONF "/etc/sddm.conf"

#ifndef FB_LOG_FILE
#define FB_LOG_FILE "/var/log/firstboot.log"
#endif

ConfigPageInfo::ConfigPageInfo(QWidget *parent)
    : QWidget(parent)
{
    // begin

    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    //QLabel *m_errInfoLabel;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_8;
    //QLineEdit *m_cfmPwdLineEdit;
    //QLineEdit *m_pwdLineEdit;
    QLabel *label_7;
    QLabel *label_5;
    //QLineEdit *m_userNameLineEdit;
    QLabel *label_6;
    QLabel *label_9;
    //QCheckBox *m_autoLoginBox;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    //QLineEdit *m_compNameLineEdit;
    //QLineEdit *m_rootPwdLineEdit;
    QLabel *label_2;
    //QLineEdit *m_rootPwdLineEdit2;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *verticalSpacer_15;
    QSpacerItem *verticalSpacer_16;
    QCheckBox *checkBox;
    QLabel *label_10;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    //QPushButton *returnButton;
    QSpacerItem *horizontalSpacer_6;
    //QPushButton *m_nextButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_7;


    QWidget *Form=NULL;


    gridLayout_5 = new QGridLayout(Form);
    gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
    gridLayout_4 = new QGridLayout();
    gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
    m_errInfoLabel = new QLabel(Form);
    m_errInfoLabel->setObjectName(QStringLiteral("m_errInfoLabel"));
    m_errInfoLabel->setLayoutDirection(Qt::LeftToRight);
    m_errInfoLabel->setAlignment(Qt::AlignCenter);

    gridLayout_4->addWidget(m_errInfoLabel, 2, 0, 1, 1);

    gridLayout_3 = new QGridLayout();
    gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

    gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_3->addItem(horizontalSpacer_2, 1, 0, 1, 1);

    horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_3->addItem(horizontalSpacer_3, 1, 4, 1, 1);

    gridLayout_2 = new QGridLayout();
    gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
    m_pwdLineEdit = new QLineEdit(Form);
    m_pwdLineEdit->setObjectName(QStringLiteral("m_pwdLineEdit"));
    QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(m_pwdLineEdit->sizePolicy().hasHeightForWidth());
    m_pwdLineEdit->setSizePolicy(sizePolicy);
    m_pwdLineEdit->setMinimumSize(QSize(152, 29));
    m_pwdLineEdit->setMaximumSize(QSize(152, 29));
    m_pwdLineEdit->setEchoMode(QLineEdit::Password);

    gridLayout_2->addWidget(m_pwdLineEdit, 4, 1, 1, 1);

    label_5 = new QLabel(Form);
    label_5->setObjectName(QStringLiteral("label_5"));
    QFont font;
    font.setPointSize(16);
    label_5->setFont(font);

    gridLayout_2->addWidget(label_5, 0, 0, 1, 2);

    label_8 = new QLabel(Form);
    label_8->setObjectName(QStringLiteral("label_8"));
    QFont font1;
    font1.setPointSize(12);
    label_8->setFont(font1);

    gridLayout_2->addWidget(label_8, 6, 0, 1, 1, Qt::AlignRight);

    verticalSpacer_11 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_11, 1, 0, 1, 1);

    label_7 = new QLabel(Form);
    label_7->setObjectName(QStringLiteral("label_7"));
    label_7->setFont(font1);

    gridLayout_2->addWidget(label_7, 4, 0, 1, 1, Qt::AlignRight);

    m_cfmPwdLineEdit = new QLineEdit(Form);
    m_cfmPwdLineEdit->setObjectName(QStringLiteral("m_cfmPwdLineEdit"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(m_cfmPwdLineEdit->sizePolicy().hasHeightForWidth());
    m_cfmPwdLineEdit->setSizePolicy(sizePolicy1);
    m_cfmPwdLineEdit->setMinimumSize(QSize(152, 29));
    m_cfmPwdLineEdit->setMaximumSize(QSize(152, 29));
    m_cfmPwdLineEdit->setEchoMode(QLineEdit::Password);

    gridLayout_2->addWidget(m_cfmPwdLineEdit, 6, 1, 1, 1);

    label_6 = new QLabel(Form);
    label_6->setObjectName(QStringLiteral("label_6"));
    label_6->setFont(font1);

    gridLayout_2->addWidget(label_6, 2, 0, 1, 1, Qt::AlignRight);

    m_userNameLineEdit = new QLineEdit(Form);
    m_userNameLineEdit->setObjectName(QStringLiteral("m_userNameLineEdit"));
    sizePolicy1.setHeightForWidth(m_userNameLineEdit->sizePolicy().hasHeightForWidth());
    m_userNameLineEdit->setSizePolicy(sizePolicy1);
    m_userNameLineEdit->setMinimumSize(QSize(152, 29));
    m_userNameLineEdit->setMaximumSize(QSize(152, 29));

    gridLayout_2->addWidget(m_userNameLineEdit, 2, 1, 1, 1);

    verticalSpacer_7 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_7, 3, 1, 1, 1);

    verticalSpacer_8 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_8, 5, 1, 1, 1);

    label_12 = new QLabel(Form);
    label_12->setObjectName(QStringLiteral("label_12"));

    gridLayout_2->addWidget(label_12, 2, 2, 1, 1);

    label_13 = new QLabel(Form);
    label_13->setObjectName(QStringLiteral("label_13"));

    gridLayout_2->addWidget(label_13, 4, 2, 1, 1);

    label_14 = new QLabel(Form);
    label_14->setObjectName(QStringLiteral("label_14"));

    gridLayout_2->addWidget(label_14, 6, 2, 1, 1);

    verticalSpacer_14 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_14, 1, 1, 1, 1);

    label_15 = new QLabel(Form);
    label_15->setObjectName(QStringLiteral("label_15"));
    label_15->setFont(font1);

    gridLayout_2->addWidget(label_15, 8, 0, 1, 1);

    verticalSpacer_9 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_9, 7, 0, 1, 1);

    verticalSpacer_15 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_15, 7, 1, 1, 1);

    m_autoLoginBox = new QCheckBox(Form);
    m_autoLoginBox->setObjectName(QStringLiteral("m_autoLoginBox"));
    m_autoLoginBox->setMaximumSize(QSize(16777215, 16777215));
    m_autoLoginBox->setFont(font1);
    m_autoLoginBox->setContextMenuPolicy(Qt::DefaultContextMenu);
    m_autoLoginBox->setAcceptDrops(false);
    m_autoLoginBox->setLayoutDirection(Qt::LeftToRight);

    gridLayout_2->addWidget(m_autoLoginBox, 8, 1, 1, 1);


    gridLayout_3->addLayout(gridLayout_2, 1, 3, 2, 1);

    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_5, 3, 1, 1, 1);

    label_9 = new QLabel(Form);
    label_9->setObjectName(QStringLiteral("label_9"));
    label_9->setFont(font1);

    gridLayout->addWidget(label_9, 8, 0, 1, 1);

    m_compNameLineEdit = new QLineEdit(Form);
    m_compNameLineEdit->setObjectName(QStringLiteral("m_compNameLineEdit"));
    sizePolicy1.setHeightForWidth(m_compNameLineEdit->sizePolicy().hasHeightForWidth());
    m_compNameLineEdit->setSizePolicy(sizePolicy1);
    m_compNameLineEdit->setMinimumSize(QSize(152, 29));
    m_compNameLineEdit->setMaximumSize(QSize(152, 29));

    gridLayout->addWidget(m_compNameLineEdit, 2, 1, 1, 1);

    m_rootPwdLineEdit = new QLineEdit(Form);
    m_rootPwdLineEdit->setObjectName(QStringLiteral("m_rootPwdLineEdit"));
    sizePolicy1.setHeightForWidth(m_rootPwdLineEdit->sizePolicy().hasHeightForWidth());
    m_rootPwdLineEdit->setSizePolicy(sizePolicy1);
    m_rootPwdLineEdit->setMinimumSize(QSize(152, 29));
    m_rootPwdLineEdit->setMaximumSize(QSize(152, 29));
    m_rootPwdLineEdit->setEchoMode(QLineEdit::Password);

    gridLayout->addWidget(m_rootPwdLineEdit, 4, 1, 1, 1);

    label_2 = new QLabel(Form);
    label_2->setObjectName(QStringLiteral("label_2"));
    label_2->setFont(font1);
    label_2->setLayoutDirection(Qt::RightToLeft);

    gridLayout->addWidget(label_2, 2, 0, 1, 1, Qt::AlignRight);

    m_rootPwdLineEdit2 = new QLineEdit(Form);
    m_rootPwdLineEdit2->setObjectName(QStringLiteral("m_rootPwdLineEdit2"));
    sizePolicy1.setHeightForWidth(m_rootPwdLineEdit2->sizePolicy().hasHeightForWidth());
    m_rootPwdLineEdit2->setSizePolicy(sizePolicy1);
    m_rootPwdLineEdit2->setMinimumSize(QSize(152, 29));
    m_rootPwdLineEdit2->setMaximumSize(QSize(152, 29));
    m_rootPwdLineEdit2->setEchoMode(QLineEdit::Password);

    gridLayout->addWidget(m_rootPwdLineEdit2, 6, 1, 1, 1);

    label_4 = new QLabel(Form);
    label_4->setObjectName(QStringLiteral("label_4"));
    label_4->setFont(font1);
    label_4->setLayoutDirection(Qt::RightToLeft);

    gridLayout->addWidget(label_4, 6, 0, 1, 1, Qt::AlignRight);

    label_3 = new QLabel(Form);
    label_3->setObjectName(QStringLiteral("label_3"));
    label_3->setFont(font1);
    label_3->setLayoutDirection(Qt::RightToLeft);

    gridLayout->addWidget(label_3, 4, 0, 1, 1, Qt::AlignRight);

    label_10 = new QLabel(Form);
    label_10->setObjectName(QStringLiteral("label_10"));

    gridLayout->addWidget(label_10, 4, 2, 1, 1);

    label_11 = new QLabel(Form);
    label_11->setObjectName(QStringLiteral("label_11"));

    gridLayout->addWidget(label_11, 6, 2, 1, 1);

    verticalSpacer_12 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_12, 7, 0, 1, 1);

    label = new QLabel(Form);
    label->setObjectName(QStringLiteral("label"));
    label->setFont(font);

    gridLayout->addWidget(label, 0, 0, 1, 1);

    verticalSpacer_6 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_6, 5, 1, 1, 1);

    verticalSpacer_13 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_13, 1, 0, 1, 1);

    verticalSpacer_10 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_10, 1, 1, 1, 1);

    verticalSpacer_16 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_16, 7, 1, 1, 1);


    gridLayout_3->addLayout(gridLayout, 1, 1, 2, 1);


    gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    horizontalSpacer_4 = new QSpacerItem(241, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_4);

    returnButton = new QPushButton(Form);
    returnButton->setObjectName(QStringLiteral("returnButton"));
    QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(returnButton->sizePolicy().hasHeightForWidth());
    returnButton->setSizePolicy(sizePolicy2);
    returnButton->setMouseTracking(false);
    returnButton->setAutoDefault(false);

    horizontalLayout->addWidget(returnButton);

    horizontalSpacer_6 = new QSpacerItem(241, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_6);

    m_nextButton = new QPushButton(Form);
    m_nextButton->setObjectName(QStringLiteral("m_nextButton"));
    sizePolicy2.setHeightForWidth(m_nextButton->sizePolicy().hasHeightForWidth());
    m_nextButton->setSizePolicy(sizePolicy2);

    horizontalLayout->addWidget(m_nextButton);

    horizontalSpacer_5 = new QSpacerItem(241, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_5);


    gridLayout_4->addLayout(horizontalLayout, 4, 0, 1, 1);

    verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

    gridLayout_4->addItem(verticalSpacer_2, 3, 0, 1, 1);

    verticalSpacer_4 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

    gridLayout_4->addItem(verticalSpacer_4, 1, 0, 1, 1);


    gridLayout_5->addLayout(gridLayout_4, 1, 1, 1, 1);

    horizontalSpacer_8 = new QSpacerItem(29, 361, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_5->addItem(horizontalSpacer_8, 1, 2, 1, 1);

    verticalSpacer = new QSpacerItem(915, 84, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_5->addItem(verticalSpacer, 0, 1, 1, 1);

    verticalSpacer_3 = new QSpacerItem(915, 34, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_5->addItem(verticalSpacer_3, 2, 1, 1, 1);

    horizontalSpacer_7 = new QSpacerItem(29, 361, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_5->addItem(horizontalSpacer_7, 1, 0, 1, 1);

    label_10->setText("*");
    label_11->setText("*");
    label_12->setText("*");
    label_13->setText("*");
    label_14->setText("*");

    // end

    m_compNameLineEdit->setMinimumSize(QSize(152, 29));
    m_compNameLineEdit->setMaximumSize(QSize(152, 29));

    m_rootPwdLineEdit->setMinimumSize(QSize(152, 29));
    m_rootPwdLineEdit->setMaximumSize(QSize(152, 29));
    m_rootPwdLineEdit2->setMinimumSize(QSize(152, 29));
    m_rootPwdLineEdit2->setMaximumSize(QSize(152, 29));

    m_userNameLineEdit->setMinimumSize(QSize(152, 29));
    m_userNameLineEdit->setMaximumSize(QSize(152, 29));

    m_pwdLineEdit->setMinimumSize(QSize(152, 29));
    m_pwdLineEdit->setMaximumSize(QSize(152, 29));
    m_cfmPwdLineEdit->setMinimumSize(QSize(152, 29));
    m_cfmPwdLineEdit->setMaximumSize(QSize(152, 29));

    setLayout(gridLayout_5);

    label->setText(i18n("Computer info"));
    m_compNameLineEdit->setToolTip(i18n("The most length of Compter Name is 255.The name must be english alphabets."));
    QRegExp regx("^[a-zA-Z][A-Za-z0-9_]+$");
    QValidator *validator = new QRegExpValidator(regx, m_compNameLineEdit );
    m_compNameLineEdit->setValidator( validator );
    QValidator *unameValidator = new QRegExpValidator(regx, m_userNameLineEdit );
    m_userNameLineEdit->setValidator( unameValidator );


    m_compNameLineEdit->setMaxLength(255);
    m_userNameLineEdit->setMaxLength(32);
    m_pwdLineEdit->setMaxLength(32);
    m_cfmPwdLineEdit->setMaxLength(32);
    m_rootPwdLineEdit->setMaxLength(32);
    m_rootPwdLineEdit2->setMaxLength(32);
    m_pwdLineEdit->setToolTip(i18n("The most length of the Password is 32."));
    m_cfmPwdLineEdit->setToolTip(i18n("The most length of the Password is 32."));
    m_rootPwdLineEdit->setToolTip(i18n("The most length of the Password is 32."));
    m_rootPwdLineEdit2->setToolTip(i18n("The most length of the Password is 32."));

    label_2->setText(i18n("Computer name:"));
    label_3->setText(i18n("Admin password:"));
    label_4->setText(i18n("Admin confirm pwd:"));

    label_5->setText(i18n("User info"));

    m_userNameLineEdit->setToolTip(i18n("The most length of User Name is 32."));
    label_6->setText(i18n("User name:"));
    label_7->setText(i18n("Password:"));
    label_8->setText(i18n("Confirm password:"));

    m_autoLoginBox->setText(i18n("Auto Login"));

    returnButton->setText(i18n("Previous"));
    m_nextButton->setText(i18n("Ok"));

    font.setPointSize(11);
    label_2->setFont(font);
    label_3->setFont(font);
    label_4->setFont(font);
    label_6->setFont(font);
    label_7->setFont(font);
    label_8->setFont(font);
    label_9->setFont(font);
    label_15->setFont(font);
    m_compNameLineEdit->setFont(font);
    m_userNameLineEdit->setFont(font);
    m_autoLoginBox->setFont(font);


    font.setPointSize(18);
    font.setWeight(QFont::Normal);
    label->setFont(font);
    label_5->setFont(font);

    returnButton->setFont(font);
    m_nextButton->setFont(font);
    QWidget::setTabOrder(m_compNameLineEdit, m_rootPwdLineEdit);
    QWidget::setTabOrder(m_rootPwdLineEdit, m_rootPwdLineEdit2);
    QWidget::setTabOrder(m_rootPwdLineEdit2, m_userNameLineEdit);
    QWidget::setTabOrder(m_userNameLineEdit, m_pwdLineEdit);
    QWidget::setTabOrder(m_pwdLineEdit, m_cfmPwdLineEdit);
    QWidget::setTabOrder(m_cfmPwdLineEdit, m_autoLoginBox);
    QWidget::setTabOrder(m_autoLoginBox, returnButton);
    QWidget::setTabOrder(returnButton, m_nextButton);

    connect(m_pwdLineEdit, SIGNAL(editingFinished()),
                this, SLOT(slotCheckPwd()));
    connect(m_cfmPwdLineEdit, SIGNAL(editingFinished()),
                this, SLOT(slotCheckPwd()));
    connect(m_rootPwdLineEdit, SIGNAL(editingFinished()),
                this, SLOT(slotCheckPwdRoot()));
    connect(m_rootPwdLineEdit2, SIGNAL(editingFinished()),
                this, SLOT(slotCheckPwdRoot()));

    m_cleanErrInfoTimer = new QTimer(this);
    connect( m_cleanErrInfoTimer, SIGNAL(timeout()), SLOT(cleanupTimerFun()) );

    connect(returnButton, SIGNAL(clicked()), this, SLOT(retIt()));
    connect(m_nextButton, SIGNAL(clicked()), this, SLOT(nextIt()));

}


bool checkPwd(const char *src)
{
    char otherStr[] = "~!@#$%^&*()_+{}|:\"<>?`-=[]\\;',./ ";
    bool isAlpha  = false, isDig = false;

    if (src == NULL || src[0] == 0)
        return false;

    for (int i =0; i < strlen(src); i++) {
        if (isalpha(src[i]) ) {
            isAlpha = true;
        } else if (isdigit(src[i]) ) {
            isDig = true;
        }
    }

    return (isAlpha && isDig);

}

bool ConfigPageInfo::slotCheckPwdRoot()
{
    QString strPwd = m_rootPwdLineEdit->text();
    QString strcfmPwd = m_rootPwdLineEdit2->text();

    if (strPwd.length() < 6) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("The password is shorter than 6 characters."));
        m_rootPwdLineEdit->selectAll();
        return false;
    }

    if (!checkPwd(qPrintable(strPwd))) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("Try to mix up alphabets and numbers."));
        m_rootPwdLineEdit->selectAll();
        return false;
    }

    if (strcfmPwd.length() < 6) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("The password is shorter than 6 characters."));
        m_rootPwdLineEdit2->selectAll();
        return false;
    }

    if (!checkPwd(qPrintable(strcfmPwd))) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("Try to mix up alphabets and numbers."));
        m_rootPwdLineEdit2->selectAll();
        return false;
    }

    if (strPwd != strcfmPwd) {

        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("The Password are not the same, please input again."));
        m_rootPwdLineEdit->selectAll();
        return false;
    }

    return true;


}

bool ConfigPageInfo::slotCheckPwd()
{

    QString strPwd = m_pwdLineEdit->text();
    QString strcfmPwd = m_cfmPwdLineEdit->text();

    if (strPwd.length() < 6) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("The password is shorter than 6 characters."));
        m_pwdLineEdit->selectAll();
        return false;
    }

    if (!checkPwd(qPrintable(strPwd))) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("Try to mix up alphabets and numbers."));
        m_pwdLineEdit->selectAll();
        return false;
    }

    if (strcfmPwd.length() < 6) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("The password is shorter than 6 characters."));
        m_cfmPwdLineEdit->selectAll();
        return false;
    }

    if (!checkPwd(qPrintable(strcfmPwd))) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("Try to mix up alphabets and numbers."));
        m_cfmPwdLineEdit->selectAll();
        return false;
    }

    if (strPwd != strcfmPwd) {

        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("The Password are not the same, please input again."));
        m_pwdLineEdit->selectAll();
        return false;
    }


    return true;

}



void ConfigPageInfo::skipIt()
{
    int ret = reboot(LINUX_REBOOT_CMD_RESTART);
    if (ret == -1) {
        QMessageBox::warning(this, i18n("error"),
            i18n("Fail to reboot machine, please try it manually."));
    }
}

void ConfigPageInfo::retIt()
{
    btnClicked(-1);
    return;
}

void ConfigPageInfo::nextIt()
{
    char cmd[512] = "";

    if (!slotCheckPwdRoot()) {
        return;
    }
    if (!slotCheckPwd()) {
        return;
    }
    QString str = m_compNameLineEdit->text();
    if (!str.isEmpty()) {
        snprintf(cmd,sizeof(cmd),"hostnamectl set-hostname \"%s\" ",qPrintable(str));
        int ret = system(cmd);
        if (ret != 0) {
            ret = system(cmd);
        }
    }

    QString strPwd = m_rootPwdLineEdit->text();
    QString strcfmPwd = m_rootPwdLineEdit2->text();
    if (strPwd.isEmpty()) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("Please input admin password."));
        m_rootPwdLineEdit->selectAll();
        return ;
    }

    if (strPwd != strcfmPwd) {

        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("The Password are not the same, please input again."));
        m_rootPwdLineEdit->selectAll();
        return ;
    }

    snprintf(cmd,sizeof(cmd),"echo \"root:%s\" | chpasswd",
                               qPrintable(strcfmPwd));
    int ret = system(cmd);
    if( ret != 0) {
        ret = system(cmd);
        if( ret != 0) {
            QMessageBox::warning(this, i18n("warning"),
                i18n("Failed to change admin's password, please try it manually."));
        }
    }

    if (!addUserAccount() ) {
        return;
    }

    m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
    m_errInfoLabel->setText(i18n("Completed,enjoy it now."));

    disconnect(m_nextButton, SIGNAL(clicked()), 0, 0);
    m_nextButton->setText(i18n("Ok"));
    returnButton->setEnabled(false);
    connect(m_nextButton, SIGNAL(clicked()), this, SLOT(exitIt()));

}

void ConfigPageInfo::exitIt()
{
system("echo will_exit > /tmp/fb.log");
system("/usr/bin/systemctl  enable sddm-plymouth&");
system("echo after_enable >> /tmp/fb.log");
system("/usr/bin/systemctl  start sddm-plymouth&");
system("echo after_start >> /tmp/fb.log");
     exit(0);
}


void ConfigPageInfo::btnClicked(int index)
{
     Q_EMIT sigPageChged(index);
}

void ConfigPageInfo::cleanupTimerFun()
{
     if (!m_errInfoLabel->text().isEmpty()) {
         m_errInfoLabel->setText("");
     }

     m_cleanErrInfoTimer->stop();

}

bool ConfigPageInfo::addUserAccount()
{
    char cmd[512]="";
    int ret = 0;
    char userName[256]="";

    QString strUname = m_userNameLineEdit->text();
    if (strUname.isEmpty()) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );

        m_errInfoLabel->setText(i18n("Please input User name."));
        m_userNameLineEdit->selectAll();
        return false;
    }

    QString strPwd = m_pwdLineEdit->text();
    QString strcfmPwd = m_cfmPwdLineEdit->text();
    if (strPwd.isEmpty()) {
        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("Please input password."));
        m_pwdLineEdit->setFocus();
        return false;
    }

    if (strPwd != strcfmPwd) {

        m_cleanErrInfoTimer->start( CLEAN_ERRINFO_TIMEINTERVAL );
        m_errInfoLabel->setText(i18n("The Password are not the same, please input again."));
        m_pwdLineEdit->selectAll();
        return false;
    }

    snprintf(userName,sizeof(userName),"%s",qPrintable(strUname));

    //snprintf(cmd,sizeof(cmd),"useradd -g users -G wheel,sys,video,audio,disk -m %s",userName);
    snprintf(cmd,sizeof(cmd),"useradd -U -G wheel,sys,video,audio,disk -m %s",userName);
    ret = system (cmd);
    usleep(500);

    struct passwd *pw = NULL;
    pw = getpwnam(userName);
    if (pw == NULL) {
        QMessageBox::warning(this, i18n("warning"),
            i18n("Fail to add this user, please try it manually."));
        m_userNameLineEdit->setFocus();

        // only exit
        disconnect(m_nextButton, SIGNAL(clicked()), 0, 0);
        connect(m_nextButton, SIGNAL(clicked()), this, SLOT(exitIt()));

        return false;
    }

 #if 0
    snprintf(cmd,sizeof(cmd),"echo -e '%s\n%s' | passwd %s",
                               qPrintable(strPwd),
                               qPrintable(strcfmPwd),
                               qPrintable(strUname) );
#else
    snprintf(cmd,sizeof(cmd),"echo \"%s:%s\" | chpasswd",
                               qPrintable(strUname),
                               qPrintable(strcfmPwd));
#endif

#if 0
    const char *msg = FascistCheck(qPrintable(strcfmPwd), NULL);
    if (msg) {
            QMessageBox::warning(this, i18n("warning"),msg);

            printf("%s,%d,msg[%s]\n",__FUNCTION__,__LINE__,msg); //pwquality_check,738,msg[过于简单化/系统化]

            return false;
    }
#endif
    ret = system (cmd);
    if (m_autoLoginBox->isChecked()) {
        ret = setAutoLogin();
    }

    QString str = m_compNameLineEdit->text();
    if (str.isEmpty()) {
        snprintf(cmd,sizeof(cmd),"hostnamectl set-hostname \"%s\" ",qPrintable(strUname));
        ret = system (cmd);
        if (ret != 0) {
            ret = system (cmd);
        }
    }

    return true;

}

int ConfigPageInfo::setAutoLogin()
{
    const char   *file = NULL;
    char    *command = NULL;
    GDir    *dir = NULL;
    char   **strs = NULL;
    GError  *err = NULL;
    int ret = -1;
    char cmd[1024]="";

    QString strUname = m_userNameLineEdit->text();

    dir = g_dir_open (XSESSION, 0, &err);
    if (!g_file_test (SDDM_CONF, G_FILE_TEST_EXISTS))
    {
        command = g_strdup_printf ("sddm --example-config > %s", SDDM_CONF);
        ret = system (command);
        g_free (command);
    }

    file = XSESSION "plasma.desktop";

#if 0
    if (!g_file_test (file, G_FILE_TEST_EXISTS))
    {
        file = g_dir_read_name (dir);
    }

    if (file)
#endif
    if (g_file_test (file, G_FILE_TEST_EXISTS))
    {
        sprintf(cmd,"echo \" find desktop file,will set session \" >> %s",FB_LOG_FILE);
        system(cmd);

        ///fiel[/usr/share/xsessions/plasma.desktop]
        strs = g_strsplit (file, "/", -1);
        file = g_strjoinv ("\\/", strs);

        // delete
        command = g_strdup_printf ("sed -i '/^Session=.*/d' %s", SDDM_CONF);
        ret = system (command);
        g_free (command);

        command = g_strdup_printf ("sed -i '/^User=.*/d' %s", SDDM_CONF);
        ret = system (command);
        g_free (command);

        //insert
        command = g_strdup_printf ("sed -i '/^\\[Autologin\\]/a\\Session=%s' %s", file, SDDM_CONF);
        ret = system (command);
        g_free (command);

        command = g_strdup_printf ("sed -i '/^Session=.*/a\\User=%s' %s", qPrintable(strUname), SDDM_CONF);
        ret = system (command);
        g_free (command);

        g_strfreev (strs);
    } else {

        sprintf(cmd,"echo \"no desktop file,will create %s \" >> %s",XSESSION "plasma.desktop",FB_LOG_FILE);
        system(cmd);

        char buffer[512]="";
        snprintf(buffer,sizeof(buffer),
                 "[Desktop Entry]\n"
                 "Encoding=UTF-8\n"
                 "Type=XSession\n"
                 "Exec=/usr/bin/startkde\n"
                 "TryExec=/usr/bin/startkde\n"
                 "DesktopNames=KDE\n"
                 "Name=Plasma\n"
                 "Comment=Plasma by KDE\n"
                 "X-KDE-PluginInfo-Version=5.4.3\n");
        command = g_strdup_printf ("echo \"%s\" > %s ", buffer, XSESSION "plasma.desktop");
        system(command);

        sprintf(cmd,"echo \"set sddm file \" >> %s",FB_LOG_FILE);
        system(cmd);

        file = "plasma.desktop";
        // delete
        command = g_strdup_printf ("sed -i '/^Session=.*/d' %s", SDDM_CONF);
        ret = system (command);
        g_free (command);

        command = g_strdup_printf ("sed -i '/^User=.*/d' %s", SDDM_CONF);
        ret = system (command);
        g_free (command);

        //insert
        command = g_strdup_printf ("sed -i '/^\\[Autologin\\]/a\\Session=%s' %s", file, SDDM_CONF);
        ret = system (command);
        g_free (command);

        command = g_strdup_printf ("sed -i '/^Session=.*/a\\User=%s' %s", qPrintable(strUname), SDDM_CONF);
        ret = system (command);
        g_free (command);
    }

    if (dir) {
        g_free (dir);
    }
    if (err) {
        g_free (err);
    }

    return 0;

}

