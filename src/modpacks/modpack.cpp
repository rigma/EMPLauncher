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

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>

#include <include/globals.h>
#include <include/modpacks/modpack.h>

Modpack::Modpack(QObject *parent) : QObject(parent),
    _name(),
    _doc()
{

}

Modpack::Modpack(const QString &name, QObject *parent) : QObject(parent),
    _name(name)
{
    QFile modpack(MODPACKS_DIR + "/" + name + ".json");
    if (!modpack.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    _doc = QJsonDocument::fromJson(modpack.readAll());
    modpack.close();
}

Modpack::Modpack(const QJsonDocument &doc, QObject *parent) : QObject(parent),
    _doc(doc)
{
    _name = _doc.object().value("name").toString();
}

Modpack::~Modpack()
{

}

QString Modpack::name() const
{
    return _name;
}

QString Modpack::icon() const
{
    return _doc.object().value("icon").toString();
}
QString Modpack::fullName() const
{
    return _doc.object().value("fullName").toString();
}

QString Modpack::website() const
{
    return _doc.object().value("website").toString();
}

QString Modpack::background() const
{
    return _doc.object().value("background").toString();
}

QStringList Modpack::authors() const
{
    QStringList result;

    for (QVariant author : _doc.object().value("authors").toArray().toVariantList().toStdList())
        result.append(author.toString());

    return result;
}

QMap<QString, QString> Modpack::mods() const
{
    QJsonObject object(_doc.object().value("mods").toObject());
    QMap<QString, QString> result;

    for (QString key : object.keys().toStdList())
        result.insert(key, object.value(key).toString());

    return result;
}
