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

#include <QApplication>
#include <QDir>

#include <iostream>

#include <include/globals.h>
#include <include/launcher.h>

void initFilesystem();

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // First, we'll init the launcher's filesystem
    initFilesystem();

    // On lance la fenêtre principale
    Launcher launcher;
    launcher.show();

    return app.exec();
}

void initFilesystem()
{
    QDir dir;

    // We will check the main filesystem before anything else
    if (!dir.exists(BIN_DIR))
        dir.mkpath(BIN_DIR);

    if (!dir.exists(ETC_DIR))
        dir.mkpath(ETC_DIR);

    if (!dir.exists(LIB_DIR))
        dir.mkpath(LIB_DIR);

    if (!dir.exists(SHARE_DIR))
        dir.mkpath(SHARE_DIR);

    if (!dir.exists(TMP_DIR))
        dir.mkpath(TMP_DIR);

    // Then, we will check the others paths of the launcher
    if (!dir.exists(ASSETS_DIR))
    {
        dir.mkpath(ASSETS_DIR);
        dir.mkpath(ASSETS_DIR + "/indexes");
        dir.mkpath(ASSETS_DIR + "/objects");
        dir.mkpath(ASSETS_DIR + "/skins");
        dir.mkpath(ASSETS_DIR + "/virtual");
     }

    if (!dir.exists(CONFIGURATION_DIR))
        dir.mkpath(CONFIGURATION_DIR);

    if (!dir.exists(MODPACKS_DIR))
        dir.mkpath(MODPACKS_DIR);

    if (!dir.exists(SESSIONS_DIR))
        dir.mkpath(SESSIONS_DIR);

    if (!dir.exists(DOWNLOAD_DIR))
        dir.mkpath(DOWNLOAD_DIR);

    if (!dir.exists(VERSIONS_DIR))
        dir.mkpath(VERSIONS_DIR);

    // Finally, we will clean the /tmp directory
    dir.setPath(TMP_DIR);
    for (QString fileName : dir.entryList(QDir::Files | QDir::NoDotAndDotDot))
        dir.remove(dir.absoluteFilePath(fileName));

    dir.setPath(DOWNLOAD_DIR);
    for (QString fileName : dir.entryList(QDir::Files | QDir::NoDotAndDotDot))
        dir.remove(dir.absoluteFilePath(fileName));
}
