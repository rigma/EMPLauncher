/**
 * EMPLauncher | This is a small project of Minecraft Launcher for a theoretical FTB modpack.
 *
 * Copyright (C) 2014 Romain Failla
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LOGINSERVICE_H
#define LOGINSERVICE_H

#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSettings>

#include <include/sessions/sessionmanager.h>

class LoginService : public QObject
{
    Q_OBJECT

public:
    LoginService(QObject *parent = nullptr);
    LoginService(SessionManager *sessionManager, QSettings *configuration, QObject *parent = nullptr);
    ~LoginService();

public:
    void login(const QString &username, const QString &password);
    void login(const QJsonDocument &payload);

private slots:
    void manageReply(QNetworkReply *reply);

signals:
    void loginSuccessfull(Session *session);
    void loginFailed(QJsonDocument *error);

private:
    QNetworkAccessManager *_manager;
    QSettings *_configuration;
    SessionManager *_sessionManager;
};

#endif // LOGINSERVICE_H
