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

#ifndef JSONSETTINGS_H
#define JSONSETTINGS_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QSettings>
#include <QVariant>

class JsonSettings
{
public:
    JsonSettings();
    JsonSettings(const QString &fileName);
    JsonSettings(const QJsonDocument &document);
    JsonSettings(const QJsonObject &object);
    JsonSettings(QSettings *settings);
    ~JsonSettings();

public:
    static JsonSettings load(const QString &fileName);
    void save(const QString &fileName = QString(), QJsonDocument::JsonFormat format = QJsonDocument::Indented);

public:
    static JsonSettings fromSettings(QSettings *settings);
    QSettings *toSettings();

public:
    QJsonDocument document() const;
    QJsonObject root() const;
    QString fileName() const;

public:
    QJsonObject getGroup(QString &key) const;
    QVariant get(QString &key, const QVariant &defaultValue = QVariant()) const;
    void set(QString &key, const QVariant &value);

private:
    QJsonObject resolve(QString &key) const;
    void importGroup(QSettings *settings, const QString &name, QJsonObject &obj);
    void exportGroup(QSettings *settings, const QString &name, const QJsonObject &group);

private:
    QJsonDocument _document;
    QString _fileName;
};

#endif // JSONSETTINGS_H
