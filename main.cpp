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

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // On va d'abord vérifier si le dossier de l'application à la bonne arborescence
    if (!QDir().exists(ASSETS_DIR))
        QDir().mkdir(ASSETS_DIR);

    if (!QDir().exists(CONFIGURATION_DIR))
        QDir().mkdir(CONFIGURATION_DIR);

    if (!QDir().exists(LIBRARIES_DIR))
        QDir().mkdir(LIBRARIES_DIR);

    if (!QDir().exists(SESSIONS_DIR))
        QDir().mkdir(SESSIONS_DIR);

    if (!QDir().exists(DOWNLOAD_DIR))
        QDir().mkdir(DOWNLOAD_DIR);

    if (!QDir().exists(VERSIONS_DIR))
        QDir().mkdir(VERSIONS_DIR);

    // On lance la fenêtre principale
    Launcher launcher;
    launcher.show();

    return app.exec();
}
