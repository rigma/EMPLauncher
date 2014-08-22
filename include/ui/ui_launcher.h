/********************************************************************************
** Form generated from reading UI file 'launcher.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHER_H
#define UI_LAUNCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Launcher
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *lists;
    QListWidget *availableModpack;
    QListWidget *news;
    QHBoxLayout *controls;
    QSpacerItem *horizontalSpacer;
    QCheckBox *forceUpdate;
    QPushButton *launch;
    QPushButton *pushButton;

    void setupUi(QWidget *Launcher)
    {
        if (Launcher->objectName().isEmpty())
            Launcher->setObjectName(QStringLiteral("Launcher"));
        Launcher->resize(1240, 640);
        verticalLayoutWidget = new QWidget(Launcher);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 1221, 621));
        mainLayout = new QVBoxLayout(verticalLayoutWidget);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        lists = new QHBoxLayout();
        lists->setObjectName(QStringLiteral("lists"));
        lists->setSizeConstraint(QLayout::SetMinAndMaxSize);
        availableModpack = new QListWidget(verticalLayoutWidget);
        availableModpack->setObjectName(QStringLiteral("availableModpack"));
        availableModpack->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(availableModpack->sizePolicy().hasHeightForWidth());
        availableModpack->setSizePolicy(sizePolicy);

        lists->addWidget(availableModpack);

        news = new QListWidget(verticalLayoutWidget);
        news->setObjectName(QStringLiteral("news"));

        lists->addWidget(news);


        mainLayout->addLayout(lists);

        controls = new QHBoxLayout();
        controls->setObjectName(QStringLiteral("controls"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        controls->addItem(horizontalSpacer);

        forceUpdate = new QCheckBox(verticalLayoutWidget);
        forceUpdate->setObjectName(QStringLiteral("forceUpdate"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(forceUpdate->sizePolicy().hasHeightForWidth());
        forceUpdate->setSizePolicy(sizePolicy1);
        forceUpdate->setLayoutDirection(Qt::LeftToRight);

        controls->addWidget(forceUpdate, 0, Qt::AlignRight);

        launch = new QPushButton(verticalLayoutWidget);
        launch->setObjectName(QStringLiteral("launch"));
        sizePolicy1.setHeightForWidth(launch->sizePolicy().hasHeightForWidth());
        launch->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        launch->setFont(font);
        launch->setLayoutDirection(Qt::LeftToRight);

        controls->addWidget(launch, 0, Qt::AlignRight);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        controls->addWidget(pushButton, 0, Qt::AlignRight);


        mainLayout->addLayout(controls);


        retranslateUi(Launcher);

        QMetaObject::connectSlotsByName(Launcher);
    } // setupUi

    void retranslateUi(QWidget *Launcher)
    {
        Launcher->setWindowTitle(QApplication::translate("Launcher", "EMP Launcher", 0));
        forceUpdate->setText(QApplication::translate("Launcher", "Forcer la mise \303\240 jour", 0));
        launch->setText(QApplication::translate("Launcher", "Lancer", 0));
        pushButton->setText(QApplication::translate("Launcher", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class Launcher: public Ui_Launcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHER_H
