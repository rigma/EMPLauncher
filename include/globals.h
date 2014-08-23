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

#define USER_AGENT "Qt/EMPLauncher 1.0"

#define ASSETS_DIR        QCoreApplication::applicationDirPath() + "/assets"
#define CONFIGURATION_DIR QCoreApplication::applicationDirPath() + "/etc"
#define LIBRARIES_DIR     QCoreApplication::applicationDirPath() + "/libraries"
#define SESSIONS_DIR      QCoreApplication::applicationDirPath() + "/sessions"
#define DOWNLOAD_DIR      QCoreApplication::applicationDirPath() + "/tmp"
#define VERSIONS_DIR      QCoreApplication::applicationDirPath() + "/versions"

#endif // GENERAL_H
