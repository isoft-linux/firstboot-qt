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

#include <errno.h>
#include <QtWidgets>
#include <QObject>

#include "lang.h"
#define  ETC_DEFAULT_GRUB "/etc/default/grub"

bool g_isChinese = false;

ConfigPageLang::ConfigPageLang(QWidget *parent)
    : QWidget(parent)
{
    m_local_id[0] = '\0';
    strcpy(m_kbd_layout,"cn");

    //begin

    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    //QPushButton *skipButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *returnButton;
    QSpacerItem *horizontalSpacer_6;
    //QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *keyboardLabel;
    //QComboBox *m_keyboardCombo;
    QLabel *langLabel;
    //QComboBox *m_langCombo;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    //QLabel *tip_label;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;

    QWidget *Form = NULL;
    gridLayout_3 = new QGridLayout(Form);
    gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
    gridLayout_2 = new QGridLayout();
    gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
    horizontalSpacer_7 = new QSpacerItem(29, 17, QSizePolicy::Preferred, QSizePolicy::Minimum);

    gridLayout_2->addItem(horizontalSpacer_7, 0, 0, 1, 1);

    verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_6, 1, 1, 1, 1);

    verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

    gridLayout_2->addItem(verticalSpacer_2, 4, 1, 1, 1);

    horizontalSpacer_8 = new QSpacerItem(32, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

    gridLayout_2->addItem(horizontalSpacer_8, 0, 2, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    horizontalSpacer_4 = new QSpacerItem(241, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_4);

    skipButton = new QPushButton(Form);
    skipButton->setObjectName(QStringLiteral("skipButton"));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(skipButton->sizePolicy().hasHeightForWidth());
    skipButton->setSizePolicy(sizePolicy);

    horizontalLayout->addWidget(skipButton);

    horizontalSpacer_9 = new QSpacerItem(120, 28, QSizePolicy::Preferred, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_9);

    returnButton = new QPushButton(Form);
    returnButton->setObjectName(QStringLiteral("returnButton"));
    sizePolicy.setHeightForWidth(returnButton->sizePolicy().hasHeightForWidth());
    returnButton->setSizePolicy(sizePolicy);

    horizontalLayout->addWidget(returnButton);

    horizontalSpacer_6 = new QSpacerItem(120, 28, QSizePolicy::Preferred, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_6);

    nextButton = new QPushButton(Form);
    nextButton->setObjectName(QStringLiteral("nextButton"));
    sizePolicy.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
    nextButton->setSizePolicy(sizePolicy);

    horizontalLayout->addWidget(nextButton);

    horizontalSpacer_5 = new QSpacerItem(241, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_5);


    gridLayout_2->addLayout(horizontalLayout, 6, 0, 1, 3);

    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

    keyboardLabel = new QLabel(Form);
    keyboardLabel->setObjectName(QStringLiteral("keyboardLabel"));
    keyboardLabel->setMinimumSize(QSize(110, 50));
    keyboardLabel->setMaximumSize(QSize(110, 50));
    QFont font;
    font.setPointSize(12);
    keyboardLabel->setFont(font);
    keyboardLabel->setLayoutDirection(Qt::RightToLeft);
    keyboardLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(keyboardLabel, 0, 0, 1, 1);

    m_keyboardCombo = new QComboBox(Form);
    m_keyboardCombo->setObjectName(QStringLiteral("m_keyboardCombo"));
    m_keyboardCombo->setMinimumSize(QSize(250, 50));
    m_keyboardCombo->setMaximumSize(QSize(250, 50));

    gridLayout->addWidget(m_keyboardCombo, 2, 2, 1, 1);

    langLabel = new QLabel(Form);
    langLabel->setObjectName(QStringLiteral("langLabel"));
    langLabel->setMinimumSize(QSize(110, 50));
    langLabel->setMaximumSize(QSize(110, 50));
    langLabel->setFont(font);
    langLabel->setLayoutDirection(Qt::RightToLeft);
    langLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(langLabel, 2, 0, 1, 1);

    m_langCombo = new QComboBox(Form);
    m_langCombo->setObjectName(QStringLiteral("m_langCombo"));
    m_langCombo->setMinimumSize(QSize(250, 50));
    m_langCombo->setMaximumSize(QSize(250, 50));

    gridLayout->addWidget(m_langCombo, 0, 2, 1, 1);

    horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

    verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

    gridLayout->addItem(verticalSpacer_4, 1, 2, 1, 1);

    verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

    gridLayout->addItem(verticalSpacer_5, 1, 0, 1, 1);


    gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

    tip_label = new QLabel(Form);
    tip_label->setObjectName(QStringLiteral("tip_label"));

    gridLayout_2->addWidget(tip_label, 2, 1, 1, 1);


    gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

    verticalSpacer_3 = new QSpacerItem(20, 124, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_3->addItem(verticalSpacer_3, 2, 0, 1, 1);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);


    // end

    tip_label->setText(QString()); // new

    skipButton->setText(i18n("Skip"));
    returnButton->setText(i18n("Previous"));
    nextButton->setText(i18n("Next"));

    keyboardLabel->setText(i18n("language:"));
    langLabel->setText(i18n("keyboard:"));
    returnButton->hide();

    insertLang();
    insertKbd();

    font.setPointSize(16);
    langLabel->setFont(font);
    m_langCombo->setFont(font);
    keyboardLabel->setFont(font);
    m_keyboardCombo->setFont(font);
    tip_label->setFont(font);

    font.setWeight(QFont::Normal);
    skipButton->setFont(font);
    returnButton->setFont(font);
    returnButton->setDisabled(true);
    nextButton->setFont(font);

    setLayout(gridLayout_3);

    connect(skipButton, SIGNAL(clicked()), this, SLOT(skipIt()));
    connect(returnButton, SIGNAL(clicked()), this, SLOT(retIt()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextIt()));
    connect(m_langCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(setLocal(int)));
    connect(m_keyboardCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(setKbd(int)));

    m_cleanErrInfoTimer = new QTimer(this);
    connect( m_cleanErrInfoTimer, SIGNAL(timeout()), SLOT(cleanupTimerFun()) );

}

void ConfigPageLang::skipIt()
{
    btnClicked(1);
}

void ConfigPageLang::retIt()
{
    btnClicked(-1);
}

struct local_s {
    char local_id[128];
    char kbd_layout[128];
};
bool g_waiting = false;
struct local_s g_local;
static int g_dotsNumber = 0;

void *realNextIt(void *arg)
{
    char cmd[512]="";
    int  ret = -1;
    char lang[128]="";
    char distributor[128]="";
    struct local_s *plocal = (struct local_s *) arg;

    printf("%s %d,id[%s],key[%s]\n",__FUNCTION__,__LINE__,plocal->local_id,plocal->kbd_layout);

    if (plocal && plocal->local_id[0] != '\0') {
        char tmp[512]="";
        snprintf(tmp,sizeof(cmd),"%s",plocal->local_id);
        char *p = strchr(tmp,'|'); //strcpy(m_local_id,"zh_CN.UTF-8|普华桌面操作系统 V4.0");
        if(p) {
            snprintf(distributor,sizeof(distributor),"%s",p+1);
            *p = 0;
            p = strchr(tmp,'.');
            if (p) {
                *p = 0;
                snprintf(lang,sizeof(lang),"%s",tmp);

            } else {
                strcpy(lang,"zh_CN");
            }


        } else {
            strcpy(lang,"zh_CN");
            strcpy(distributor,"普华桌面操作系统 V4.0");
        }

    } else {
        strcpy(lang,"zh_CN");
        strcpy(distributor,"普华桌面操作系统 V4.0");
    }

    snprintf (cmd,sizeof(cmd),"localectl set-locale LANG=\"%s.UTF-8\"",lang); // appand .utf-8
    ret = system(cmd);
    printf("%s %d,cmd[%s],ret[%d]lang[%s],distributor[%s]\n",__FUNCTION__,__LINE__,cmd,ret,lang,distributor);
    if (ret != 0) {
        // try again
        ret = system(cmd);
        if (ret != 0) {
            //tip_label->setText(i18n("Fail to set language, please try it manually."));

        }
    }

    if (plocal && plocal->kbd_layout[0] != '\0') {
        snprintf (cmd,sizeof(cmd),"localectl --no-convert set-x11-keymap \"%s\"",plocal->kbd_layout);
        ret = system(cmd);
        printf("%s %d,cmd[%s],ret[%d][%s]\n",__FUNCTION__,__LINE__,cmd,ret,plocal->kbd_layout);

        if (ret != 0) {
            // try again
            ret = system(cmd);
            if (ret != 0) {
                //tip_label->setText(i18n("Fail to set keymap, please try it manually."));
            }
        }
    } else {

        snprintf (cmd,sizeof(cmd),"localectl --no-convert set-x11-keymap \"%s\"","cn");
        ret = system(cmd);
        printf("%s %d,cmd[%s],ret[%d]\n",__FUNCTION__,__LINE__,cmd,ret);

        if (ret != 0) {
            // try again
            ret = system(cmd);
            if (ret != 0) {
                //tip_label->setText(i18n("Fail to set keymap, please try it manually."));
            }
        }

    }
    time_t t = time(NULL);

    snprintf (cmd,sizeof(cmd),"/usr/bin/cp -rf  /etc/default/grub /tmp/etc_default_grub.bak.%d ",(int)t);
    ret = system(cmd);

    snprintf (cmd,sizeof(cmd),"sed -i 's/^GRUB_DISTRIBUTOR=.*/GRUB_DISTRIBUTOR=\"%s\"/' %s", distributor, ETC_DEFAULT_GRUB);
    ret = system(cmd);

    snprintf (cmd,sizeof(cmd),"sed -i 's/^LANG=.*/LANG=\"%s\"/' %s", lang, ETC_DEFAULT_GRUB);
    ret = system(cmd);
    char lcStr[128]="";
    snprintf(lcStr,sizeof(lcStr),"LC_ALL=%s.UTF-8",lang);

    snprintf (cmd,sizeof(cmd),"%s /usr/sbin/grub-mkconfig -o /boot/grub/grub.cfg ",lcStr);
    ret = system(cmd);
    if (ret != 0) {
        snprintf (cmd,sizeof(cmd),"%s /usr/sbin/grub-mkconfig -o /boot/grub/grub.cfg ",lcStr);
    }

    //sleep(9);

    g_waiting = false;

}

void ConfigPageLang::nextIt()
{
    GThread *thread = NULL;
    memset(&g_local,0,sizeof(struct local_s));
    snprintf(g_local.local_id,sizeof(g_local.local_id),"%s",m_local_id);
    snprintf(g_local.kbd_layout,sizeof(g_local.kbd_layout),"%s",m_kbd_layout);

    g_dotsNumber = 1;
    g_waiting = true;
    m_cleanErrInfoTimer->start( 500 );

    thread = g_thread_new(NULL, realNextIt, &g_local);
    if (thread) {
        g_thread_unref(thread);
        thread = NULL;
    }
    nextButton->setEnabled(false);
    skipButton->setEnabled(false);
    m_langCombo->setEnabled(false);
    m_keyboardCombo->setEnabled(false);

    //btnClicked(1);
}

void ConfigPageLang::cleanupTimerFun()
{
    char dis[256]="";
    char dots[8]="";
    memset(dots,0,sizeof(dots));
    memset(dots,'.',g_dotsNumber);
    if (g_dotsNumber >= 6 ) {
        g_dotsNumber = 0;
    }
    g_dotsNumber ++;

    snprintf(dis,sizeof(dis),"                    ");
    tip_label->setText(QString(dis + i18n("Setting") + dots));
    if (!g_waiting) {
        m_cleanErrInfoTimer->stop();

        tip_label->setText("");
        nextButton->setEnabled(true);
        skipButton->setEnabled(true);
        m_langCombo->setEnabled(true);
        m_keyboardCombo->setEnabled(true);
        btnClicked(1);
    }
}

void ConfigPageLang::btnClicked(int index)
{
     Q_EMIT sigPageChged(index);
}

void ConfigPageLang::setLocal(int index)
{
    snprintf(m_local_id,sizeof(m_local_id),"%s",
             qPrintable(m_langCombo->currentData().toString()) );

    //setCurrentKbd(m_local_id);
}

void ConfigPageLang::setCurrentKbd(const char * locale_id)
{
	return ;

}
void ConfigPageLang::setKbd(int index)
{
    snprintf(m_kbd_layout,sizeof(m_kbd_layout),"%s",
             qPrintable(m_keyboardCombo->currentData().toString()) );

    if (m_kbd_layout[0] == 0) {
        strcpy(m_kbd_layout,"cn");
    }

}


int ConfigPageLang::addOneItem(const char *locale_id)
{
return 0;
}

void ConfigPageLang::insertLang()
{
    if (g_isChinese) {
        m_langCombo->addItem(QString("中文(简体)"),"zh_CN.UTF-8|普华桌面操作系统 V4.0");
        m_langCombo->addItem(QString("中文(繁體)"),"zh_TW.UTF-8|普華桌面操作系統 V4.0");
        m_langCombo->addItem(QString("英语"),"en_US.UTF-8|iSoft Desktop OS V4.0");
        m_langCombo->addItem(QString("日本語"),"ja_JP.UTF-8|普华 デスクトップの OS V4.0");
        m_langCombo->addItem(QString("朝鲜语"),"ko_KR.UTF-8|보화 데스크 톱 운영 체제 V4.0");
    } else {
        m_langCombo->addItem(QString("Chinese(Simplified)"),"zh_CN.UTF-8|普华桌面操作系统 V4.0");
        m_langCombo->addItem(QString("Chinese(Traditional)"),"zh_TW.UTF-8|普華桌面操作系統 V4.0");
        m_langCombo->addItem(QString("English"),"en_US.UTF-8|iSoft Desktop OS V4.0");
        m_langCombo->addItem(QString("Japanese"),"ja_JP.UTF-8|普华 デスクトップの OS V4.0");
        m_langCombo->addItem(QString("Korean"),"ko_KR.UTF-8|보화 데스크 톱 운영 체제 V4.0");
    }

    if (m_local_id[0] == 0) {
        strcpy(m_local_id,"zh_CN.UTF-8|普华桌面操作系统 V4.0");
    }

    return ;

}

void ConfigPageLang::insertKbd()
{
    if (g_isChinese) {
        m_keyboardCombo->addItem(QString("汉语"),"cn");
        m_keyboardCombo->addItem(QString("英语(美国)"),"us");
        m_keyboardCombo->addItem(QString("英语(英国)"),"gb");
        m_keyboardCombo->addItem(QString("英语(喀麦隆)"),"gb");
        m_keyboardCombo->addItem(QString("英语(尼日利亚)"),"ng");
        m_keyboardCombo->addItem(QString("英语(南非)"),"za");
        m_keyboardCombo->addItem(QString("英语(加纳)"),"gh");
        m_keyboardCombo->addItem(QString("日语"),"jp");
        m_keyboardCombo->addItem(QString("朝鲜语"),"kr");
    } else {
        m_keyboardCombo->addItem(QString("Chinese"),"cn");
        m_keyboardCombo->addItem(QString("English(USA)"),"us");
        m_keyboardCombo->addItem(QString("English(UK)"),"gb");
        m_keyboardCombo->addItem(QString("English(Cameroon)"),"gb");
        m_keyboardCombo->addItem(QString("English(Nigeria)"),"ng");
        m_keyboardCombo->addItem(QString("English(South Africa)"),"za");
        m_keyboardCombo->addItem(QString("English(Ghana)"),"gh");
        m_keyboardCombo->addItem(QString("Japanese"),"jp");
        m_keyboardCombo->addItem(QString("Korean"),"kr");
    }

    return;
}

void ConfigPageLang::add_keybords
            (GList        *list,
              const gchar  *type,
              const gchar  *default_id,
              //GnomeXkbInfo *xkb_info,
              GHashTable   *inputs)
{
    GHashTableIter iter;
    gchar         *key;
    const char    *id;

    for (; list; list = list->next)
    {
        id = (const gchar *) list->data;

        if (g_strcmp0 (id, default_id) == 0)
            continue;

        key = g_strdup (id);
        if (g_hash_table_contains (inputs, key))
        {
            g_free (key);
            continue;
        }

        g_hash_table_add (inputs, key);

        char *country_name;
        char *country_name_untrans;

        const char *name = NULL;
        const gchar *xkb_layout = NULL;

        if (g_str_equal (type, "xkb"))
        {
            //gnome_xkb_info_get_layout_info (xkb_info, id, &name, NULL, &xkb_layout, NULL);
        }
        else {

            continue;
        }

        if (name && xkb_layout) {
            m_keyboardCombo->addItem(name,xkb_layout);
        }
    }
}



