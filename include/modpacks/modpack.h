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

#ifndef MODPACK_H
#define MODPACK_H

#include <QJsonDocument>
#include <QMap>
#include <QObject>
#include <QVariant>

class Modpack : public QObject
{
    Q_OBJECT

public:
    Modpack(QObject *parent = nullptr);
    Modpack(const QString &name, QObject *parent = nullptr);
    Modpack(const QJsonDocument &doc, QObject *parent = nullptr);
    Modpack(const Modpack &modpack);
    ~Modpack();

public:
    QString name() const;
    QString fullName() const;
    QString website() const;
    QStringList authors() const;
    QString version() const;
    QString minecraftVersion() const;
    QString icon() const;
    QString background() const;
    QMap<QString, QString> mods() const;

private:
    QString _name;
    QJsonDocument _doc;
};

#endif // MODPACK_H
