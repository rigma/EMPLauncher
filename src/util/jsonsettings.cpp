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
#include <QJsonObject>

#include <include/util/jsonsettings.h>

JsonSettings::JsonSettings() : _document(),
    _fileName()
{

}

JsonSettings::JsonSettings(const QString &fileName) : _document(),
    _fileName(fileName)
{
    QFile f(fileName);

    if (f.exists() && f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        _document = QJsonDocument::fromJson(f.readAll());

        f.close();
    }
}

JsonSettings::JsonSettings(const QJsonDocument &document) : _document(document),
    _fileName()
{

}

JsonSettings::JsonSettings(const QJsonObject &object) : _document(object),
    _fileName()
{

}

JsonSettings::JsonSettings(QSettings *settings) : _document(),
    _fileName(settings->fileName())
{
    QJsonObject root = _document.object();

    for (QString groupName : settings->childGroups().toStdList())
        importGroup((QSettings*) settings, groupName, root);

    for (QString key : settings->childKeys().toStdList())
        set(key, settings->value(key));
}

JsonSettings::~JsonSettings()
{
    save();
}

JsonSettings JsonSettings::load(const QString &fileName)
{
    JsonSettings *jsonSettings = new JsonSettings(fileName);

    return *jsonSettings;
}

void JsonSettings::save(const QString &fileName, QJsonDocument::JsonFormat format)
{
    QFile f(fileName != QString() ? fileName : _fileName);

    if (f.exists() && f.open(QIODevice::WriteOnly))
    {
        f.write(_document.toJson(format));
        f.close();
    }
}

JsonSettings JsonSettings::fromSettings(QSettings *settings)
{
    JsonSettings *jsonSettings = new JsonSettings(settings);

    return *jsonSettings;
}

QSettings *JsonSettings::toSettings()
{
    QSettings *settings(nullptr);
    QJsonObject root(_document.object()), object;
    QString path(_fileName);

    path.replace(QString(".json"), QString(".ini"));
    settings = new QSettings(path, QSettings::IniFormat);

    for (QString key : root.keys().toStdList())
    {
        if (root.value(key).isObject())
        {
            object = root.value(key).toObject();

            exportGroup((QSettings*) settings, key, object);
        }
        else
            settings->setValue(key, root.value(key).toVariant());
    }

    return settings;
}

QJsonDocument JsonSettings::document() const
{
    return _document;
}

QJsonObject JsonSettings::root() const
{
    return _document.object();
}

QString JsonSettings::fileName() const
{
    return _fileName;
}

QJsonObject JsonSettings::getGroup(QString &key) const
{
    QJsonObject group(resolve(key));

    return !group.isEmpty() ? group : QJsonObject();
}

QVariant JsonSettings::get(QString &key, const QVariant &defaultValue) const
{
    QJsonObject group(resolve(key));

    return group.contains(key) ? group.value(key).toVariant() : defaultValue;
}

void JsonSettings::set(QString &key, const QVariant &value)
{
    QJsonObject group(resolve(key));

    group[key] = value.toJsonValue();
}

QJsonObject JsonSettings::resolve(QString &key) const
{
    QStringList path(key.split("/"));
    QJsonObject group(root());

    if (path.size() > 1)
    {
        for (int i = 0 ; i < path.size() - 2 ; i++)
        {
            if (group.contains(path[i]) && group.value(path[i]).isObject())
                group = group.value(path[i]).toObject();
            else
                return root();
        }

        return group;
    }
    else
        return root();

    // Just in case
    return root();
}

void JsonSettings::importGroup(QSettings *settings, const QString &name, QJsonObject &obj)
{
    QJsonObject group;

    settings->beginGroup(name);

    for (QString groupName : settings->childGroups().toStdList())
        importGroup(settings, groupName, group);

    for (QString key : settings->childKeys().toStdList())
        group.insert(key, settings->value(key).toJsonValue());

    obj.insert(name, group);
    settings->endGroup();
}

void JsonSettings::exportGroup(QSettings *settings, const QString &name, const QJsonObject &group)
{
    settings->beginGroup(name);

    for (QString key : group.keys().toStdList())
    {
        if (group.value(key).isObject())
            exportGroup((QSettings*) settings, key, group.value(key).toObject());
        else
            settings->setValue(key, group.value(key).toVariant());
    }

    settings->endGroup();
}
