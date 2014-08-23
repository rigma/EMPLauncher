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

#include <include/sessions/session.h>

#include <QVariant>

Session::Session(QObject *parent) : QObject(parent),
    _accessToken(),
    _clientToken(),
    _uuid(),
    _name(),
    _legacy(false)
{

}

Session::Session(Session *session, QObject *parent) : QObject(parent)
{
    if (session != nullptr)
    {
        _accessToken = session->_accessToken;
        _clientToken = session->_clientToken;
        _uuid = session->_uuid;
        _name = session->_name;
        _legacy = session->_legacy;
        _offline = session->_offline;
    }
    else
    {
        _accessToken = 0x0;
        _clientToken = 0x0;
        _uuid = QUuid();
        _name = QString();
        _legacy = false;
        _offline = true;
    }
}

Session::Session(const QJsonObject &json, const bool &offline, QObject *parent) : QObject(parent),
    _offline(offline)
{
    QJsonObject selectedProfile;

    _accessToken = json.contains("accessToken") ? QUuid(json.value("accessToken").toString()) : QUuid();
    _clientToken = json.contains("clientToken") ? QUuid(json.value("clientToken").toString()) : QUuid();

    if (json.contains("selectedProfile"))
    {
        selectedProfile = json.value("selectedProfile").toObject();

        _uuid = selectedProfile.contains("id") ? QUuid(selectedProfile.value("id").toString()) : QUuid();
        _name = selectedProfile.contains("name") ? selectedProfile.value("name").toString() : QString();
        _legacy = selectedProfile.contains("legacy") ? selectedProfile.value("legacy").toBool() : false;
    }
    else
    {
        _uuid = QUuid();
        _name = QString();
        _legacy = false;
    }
}

Session::Session(const QString &accessToken, const QString &clientToken, const QString &uuid, const QString &name, const bool &legacy, const bool &offline, QObject *parent) : QObject(parent),
    _accessToken(accessToken),
    _clientToken(clientToken),
    _uuid(uuid),
    _name(name),
    _legacy(legacy),
    _offline(offline)
{

}

Session::~Session()
{

}

QUuid Session::accessToken() const
{
    return _accessToken;
}

QUuid Session::clientToken() const
{
    return _clientToken;
}

QUuid Session::uuid() const
{
    return _uuid;
}

QString Session::name() const
{
    return _name;
}

bool Session::legacy() const
{
    return _legacy;
}

void Session::setAccessToken(const QString &accessToken)
{
    _accessToken = QUuid(accessToken);
}

void Session::setClientToken(const QString &clientToken)
{
    _clientToken = QUuid(clientToken);
}

void Session::setUuid(const QString &uuid)
{
    _uuid = QUuid(uuid);
}

void Session::setName(const QString &name)
{
    _name = name;
}

void Session::setLegacy(const bool &legacy)
{
    _legacy = legacy;
}
