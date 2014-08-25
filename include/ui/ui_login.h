/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelUsername;
    QComboBox *username;
    QLineEdit *password;
    QLabel *labelPassword;
    QCheckBox *rememberAccount;
    QCheckBox *rememberPassword;
    QPushButton *cancelButton;
    QPushButton *loginButton;
    QPushButton *playOfflineButton;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QStringLiteral("loginDialog"));
        loginDialog->setWindowModality(Qt::WindowModal);
        loginDialog->resize(500, 186);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginDialog->sizePolicy().hasHeightForWidth());
        loginDialog->setSizePolicy(sizePolicy);
        loginDialog->setContextMenuPolicy(Qt::NoContextMenu);
        loginDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        formLayoutWidget = new QWidget(loginDialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 481, 131));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelUsername = new QLabel(formLayoutWidget);
        labelUsername->setObjectName(QStringLiteral("labelUsername"));
        labelUsername->setScaledContents(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUsername);

        username = new QComboBox(formLayoutWidget);
        username->setObjectName(QStringLiteral("username"));
        username->setEditable(true);
        username->setInsertPolicy(QComboBox::InsertAtTop);
        username->setFrame(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, username);

        password = new QLineEdit(formLayoutWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, password);

        labelPassword = new QLabel(formLayoutWidget);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelPassword);

        rememberAccount = new QCheckBox(formLayoutWidget);
        rememberAccount->setObjectName(QStringLiteral("rememberAccount"));
        rememberAccount->setChecked(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, rememberAccount);

        rememberPassword = new QCheckBox(formLayoutWidget);
        rememberPassword->setObjectName(QStringLiteral("rememberPassword"));

        formLayout->setWidget(5, QFormLayout::FieldRole, rememberPassword);

        cancelButton = new QPushButton(loginDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(400, 150, 93, 28));
        loginButton = new QPushButton(loginDialog);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(290, 150, 93, 28));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        loginButton->setFont(font);
        loginButton->setDefault(true);
        playOfflineButton = new QPushButton(loginDialog);
        playOfflineButton->setObjectName(QStringLiteral("playOfflineButton"));
        playOfflineButton->setGeometry(QRect(10, 150, 93, 28));

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Minecraft Login", 0));
        labelUsername->setText(QApplication::translate("loginDialog", "Username :", 0));
        username->setCurrentText(QString());
        labelPassword->setText(QApplication::translate("loginDialog", "Password :", 0));
        rememberAccount->setText(QApplication::translate("loginDialog", "Remember my account", 0));
        rememberPassword->setText(QApplication::translate("loginDialog", "Remember my password", 0));
        cancelButton->setText(QApplication::translate("loginDialog", "Cancel", 0));
        loginButton->setText(QApplication::translate("loginDialog", "Login", 0));
        playOfflineButton->setText(QApplication::translate("loginDialog", "Play offline", 0));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
