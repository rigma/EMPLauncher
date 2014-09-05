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

#ifndef INSTALLER_H
#define INSTALLER_H

#include <QDir>
#include <QObject>

#include "downloader.h"

class Installer : public QObject
{
    Q_OBJECT

public:
    Installer(QObject *parent = nullptr);
    ~Installer();

public:
    void install(const QString &modpackName, const QString &minecraftVersion);

private:
    void installMinecraft(const QString &version);

private:
    Downloader *_downloader;
};

#endif // INSTALLER_H
