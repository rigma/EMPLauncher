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

#include <include/sessionmanager.h>

SessionManager::SessionManager(QObject *parent) : QObject(parent)
{

}

SessionManager::SessionManager(const QString &sessionsPath, QObject *parent) : QObject(parent)
{
    // TODO : gérer le chargement des sessions existantes
}

SessionManager::~SessionManager()
{
    for (auto key : _sessions.keys().toStdList())
        delete _sessions[key];
}

Session *SessionManager::session(const QString &key)
{
    return _sessions.contains(key) ? _sessions.value(key) : 0;
}

Session *SessionManager::createSession(const QJsonObject &json)
{
   QString key(json.value("selectedProfile").toObject().value("name").toString());
   Session *session = new Session(json);

   _sessions.insert(key, session);

   return session;
}

Session *SessionManager::createSession(const QString &accessToken, const QString &clientToken, const QString &uuid, const QString &name, const bool &legacy)
{
    Session *session = new Session(accessToken, clientToken, uuid, name, legacy);

    _sessions.insert(name, session);

    return session;
}

void SessionManager::addSession(Session *session)
{
    _sessions.insert(session->name(), session);
}

void SessionManager::removeSession(const QString &key)
{
    if (_sessions.contains(key))
        _sessions.remove(key);
}
