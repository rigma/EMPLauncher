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

#ifndef MODPACKMANAGER_H
#define MODPACKMANAGER_H

#include <QList>
#include <QObject>

#include "modpack.h"

class ModpackManager : public QObject
{
    Q_OBJECT

public:
    ModpackManager(QObject *parent = nullptr);
    ModpackManager(const QString &modpackDir, QObject *parent = nullptr);
    ~ModpackManager();

public:
    Modpack *modpack(const QString &name) const;
    QString getModpackIni(const QString &name) const;
    QString getModpackPresentation(const QString &name) const;

public:
    QString modpackDir() const;
    void setModpackDir(const QString &modpackDir);

public slots:
    void addModpack(QString name);

private:
    QList<Modpack*> _modpacks;
    QString _modpackDir;
};

#endif // MODPACKMANAGER_H
