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

#include <include/globals.h>
#include <include/util/settings.h>

#include <QFile>
#include <QJsonDocument>

Settings::Settings(QObject *parent) : QSettings(CONFIGURATION_DIR + "/config.ini", QSettings::IniFormat, parent),
    _fileName(CONFIGURATION_DIR + "/config.ini")
{

}

Settings::Settings(const QString &fileName, QSettings::Format format, QObject *parent) : QSettings(fileName, format, parent),
    _fileName(fileName)
{

}

Settings::~Settings()
{

}

void Settings::setValue(const QString &group, const QString &key, const QVariant &value)
{
    beginGroup(group);

    QSettings::setValue(key, value);

    endGroup();
}

QVariant Settings::value(const QString &group, const QString &key, const QVariant &defaultValue)
{
    QVariant result;

    beginGroup(group);

    result = QSettings::value(key, defaultValue);

    endGroup();

    return result;
}

void Settings::fromJson(const QJsonObject &jsonObject)
{
    QMap<QString, QVariant> map(jsonObject.toVariantMap());

    for (auto key : map.keys().toStdList())
        QSettings::setValue(key, map[key]);
}

QJsonObject Settings::toJson(bool save)
{
    QFile f(CONFIGURATION_DIR + "/" + _fileName + ".json");

    QJsonDocument doc;
    QJsonObject json;

    for (auto key : allKeys().toStdList())
        json.insert(key, QJsonValue(QSettings::value(key).toString()));

    if (save)
    {
        if (!f.open(QIODevice::WriteOnly))
            return json;

        doc = QJsonDocument(json);
        f.write(doc.toJson());
    }

    return json;
}
