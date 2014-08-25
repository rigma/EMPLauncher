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

#define BIN_DIR           QCoreApplication::applicationDirPath() + "/bin"
#define ETC_DIR           QCoreApplication::applicationDirPath() + "/etc"
#define LIB_DIR           QCoreApplication::applicationDirPath() + "/lib"
#define SHARE_DIR         QCoreApplication::applicationDirPath() + "/share"
#define TMP_DIR           QCoreApplication::applicationDirPath() + "/tmp"

#define ASSETS_DIR        SHARE_DIR + "/assets"
#define CONFIGURATION_DIR ETC_DIR
#define MODPACKS_DIR      SHARE_DIR + "/modpacks"
#define SESSIONS_DIR      SHARE_DIR + "/sessions"
#define DOWNLOAD_DIR      TMP_DIR + "/downloads"
#define VERSIONS_DIR      BIN_DIR + "/versions"

#endif // GENERAL_H
