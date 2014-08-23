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

#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <QJsonObject>
#include <QMap>
#include <QObject>

#include "session.h"

class SessionManager : public QObject
{
    Q_OBJECT

public:
    SessionManager(QObject *parent = 0);
    SessionManager(const QString &sessionsPath, QObject *parent = 0);
    ~SessionManager();

public:
    Session *session(const QString &key);
    Session *createSession(const QJsonObject &json);
    Session *createSession(const QString &accessToken, const QString &clientToken, const QString &uuid, const QString &name, const bool &legacy);
    void addSession(Session *session);
    void removeSession(const QString &key);

private:
    QMap<QString, Session*> _sessions;
};

#endif // SESSIONMANAGER_H
