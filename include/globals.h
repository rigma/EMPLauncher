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

#ifndef GENERAL_H
#define GENERAL_H

#include <QtGlobal>
#include <QCoreApplication>

#ifdef Q_OS_WIN

#define CONFIGURATION_PATH "%appdata%/EMP"

#elif Q_OS_LINUX | Q_OS_UNIX

#define CONFIGURATION_PATH "/etc/EMP"

#endif

#define DOWNLOAD_PATH QCoreApplication::applicationDirPath() + "/tmp"
#define USER_AGENT "Qt/EMPLauncher 1.0"

#endif // GENERAL_H
