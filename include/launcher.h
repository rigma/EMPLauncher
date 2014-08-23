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

#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QListWidgetItem>

#include "net/downloader.h"
#include "net/loginservice.h"
#include "sessions/sessionmanager.h"
#include "ui/ui_launcher.h"
#include "util/settings.h"

class Launcher : public QWidget, private Ui::Launcher
{
    Q_OBJECT

public:
    Launcher(QWidget *parent = 0);
    ~Launcher();

public:
    void checkConfig();

private slots:
    void launching(QListWidgetItem *item = nullptr);

private:
    Downloader *_downloader;
    LoginService *_loginService;
    SessionManager *_sessionManager;
    Settings *_config;
};

#endif // LAUNCHER_H
