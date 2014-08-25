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

#ifndef SESSION_H
#define SESSION_H

#include <QJsonObject>
#include <QObject>
#include <QUuid>

class Session : public QObject
{
    Q_OBJECT

public:
    Session(QObject *parent = nullptr);
    Session(Session *session, QObject *parent = nullptr);
    Session(const QJsonObject &json, const bool &offline = true, QObject *parent = nullptr);
    Session(const QString &accessToken, const QString &clientToken, const QString &uuid, const QString &name, const bool &legacy, const bool &offline = true, QObject *parent = nullptr);
    ~Session();

public:
    QUuid accessToken() const;
    QUuid clientToken() const;
    QUuid uuid() const;
    QString name() const;
    bool legacy() const;
    bool isOffline() const;

public:
    void setAccessToken(const QString &accessToken);
    void setClientToken(const QString &clientToken);
    void setUuid(const QString &uuid);
    void setName(const QString &name);
    void setLegacy(const bool &legacy);
    void setActive(const bool &active);
    void setOffline(const bool &offline);

private:
    QUuid _accessToken;
    QUuid _clientToken;
    QUuid _uuid;
    QString _name;
    bool _legacy;
    bool _offline;
};

#endif // SESSION_H
