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

#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkRequest>

#include <include/globals.h>
#include <include/net/loginservice.h>

LoginService::LoginService(QObject *parent) : QObject(parent),
    _sessionManager(0),
    _configuration(0)
{
    _manager = new QNetworkAccessManager(this);
    connect(_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manageReply(QNetworkReply*)));
}

LoginService::LoginService(SessionManager *sessionManager, Settings *configuration, QObject *parent) : QObject(parent),
    _sessionManager(sessionManager),
    _configuration(configuration)
{
    _manager = new QNetworkAccessManager(this);
    connect(_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manageReply(QNetworkReply*)));
}

LoginService::~LoginService()
{
    disconnect(_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manageReply(QNetworkReply*)));
    delete _manager;
}

void LoginService::login(const QString &username, const QString &password)
{
    QNetworkRequest request(QUrl("https://authserver.mojang.com/"));

    QJsonDocument payload;
    QJsonObject json, agent;

    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setHeader(QNetworkRequest::UserAgentHeader, QVariant(USER_AGENT));

    agent.insert("name", QJsonValue("Minecraft"));
    agent.insert("version", QJsonValue(1));

    json.insert("agent", agent);
    json.insert("username", QJsonValue(username));
    json.insert("password", QJsonValue(password));

    payload.setObject(json);
    _manager->post(request, payload.toJson());
}

void LoginService::login(const QJsonDocument &payload)
{
    QNetworkRequest request(QUrl("https://authserver.mojang.com/"));

    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setHeader(QNetworkRequest::UserAgentHeader, QVariant(USER_AGENT));

    _manager->post(request, payload.toJson());
}

void LoginService::manageReply(QNetworkReply *reply)
{
    QJsonDocument *response(0);

    if (reply->error() != QNetworkReply::NoError)
    {
        response = new QJsonDocument(QJsonDocument::fromJson(reply->readAll()));

        emit loginFailed(response);

        reply->close();
        reply->deleteLater();
    }

    emit loginSuccessfull(_sessionManager->createSession(QJsonDocument::fromJson(reply->readAll()).object()));

    reply->close();
    reply->deleteLater();
}
