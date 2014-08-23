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

#include <QDataStream>
#include <QFile>
#include <QVariant>

#include <include/globals.h>
#include <include/sessions/sessionmanager.h>

SessionManager::SessionManager(QObject *parent) : QObject(parent),
    _sessions(),
    _sessionsPath(SESSIONS_DIR + "/sessions.dat"),
    _activeSession(nullptr)
{

}

SessionManager::SessionManager(const QString &sessionsPath, QObject *parent) : QObject(parent),
    _sessions(),
    _sessionsPath(sessionsPath),
    _activeSession(nullptr)
{
    // Loading of the previous sessions
    read();
}

SessionManager::~SessionManager()
{
    _activeSession = nullptr;

    // Saving the registered sessions
    save();

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

Session *SessionManager::activeSession() const
{
    return _activeSession;
}

QString SessionManager::sessionPath() const
{
    return _sessionsPath;
}

void SessionManager::setSessionPath(const QString &path)
{
    _sessionsPath = path;
}

void SessionManager::read()
{
    QFile f(_sessionsPath);
    QDataStream in;
    QVariant tmp;
    Session *session(0);

    // Opening the saving file
    if (!f.open(QIODevice::ReadOnly))
        return;

    in.setDevice(&f);

    // Reading of all sessions
    while (!in.atEnd())
    {
        session = new Session();

        // Retrieving of the access token
        in >> tmp;

        session->setAccessToken(tmp.toString());
        tmp.clear();

        // Retrieving of the client token
        in >> tmp;

        session->setClientToken(tmp.toString());
        tmp.clear();

        // Retrieving of the player's uuid
        in >> tmp;

        session->setUuid(tmp.toString());
        tmp.clear();

        // Retrieving of the player's username
        in >> tmp;

        session->setName(tmp.toString());
        tmp.clear();

        // Retrieving of the player's legacy
        in >> tmp;

        session->setLegacy(tmp.toBool());
        tmp.clear();
    }

    f.close();
}

void SessionManager::save()
{
    QFile f(_sessionsPath);
    QDataStream out;

    // Opening the saving file
    if (!f.open(QIODevice::WriteOnly))
        return;

    out.setDevice(&f);

    // Writing of all sessions
    for (auto key : _sessions.keys().toStdList())
    {
        out << QVariant(_sessions[key]->accessToken().toString()) << QVariant(_sessions[key]->clientToken().toString());
        out << QVariant(_sessions[key]->uuid().toString()) << QVariant(_sessions[key]->name()) << QVariant(_sessions[key]->legacy());
    }

    // Closing the file
    f.close();
}

void SessionManager::setActiveSession(const QString &name)
{
    _activeSession = session(name);
}

void SessionManager::unsetActiveSession()
{
    _activeSession = nullptr;
}
