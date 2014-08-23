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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QJsonObject>
#include <QSettings>

class Settings : public QSettings
{
    Q_OBJECT

public:
    Settings(QObject *parent = 0);
    Settings(const QString &fileName, QSettings::Format format, QObject *parent = 0);
    ~Settings();

public:
    void setValue(const QString &group, const QString &key, const QVariant &value);
    QVariant value(const QString &group, const QString &key, const QVariant &defaultValue = QVariant());

public:
    void json(const QJsonObject &jsonObject);
    QJsonObject toJson(bool save = false);

protected:
    QString _fileName;
};

#endif // SETTINGS_H
