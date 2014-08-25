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

#include <include/globals.h>
#include <include/launcher.h>

Launcher::Launcher(QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    _downloader = new Downloader;
    _config = new QSettings(CONFIGURATION_DIR + "/config.ini");

    checkConfig();

    _modpackManager = new ModpackManager(_config->value("general/modpacksPath").toString());
    _sessionManager = new SessionManager(_config->value("general/sessionsPath").toString());
    _loginService = new LoginService(_sessionManager, _config);

    availableModpack->addItem("Minecraft classic");
    connect(availableModpack, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(launching(QListWidgetItem*)));

    connect(launch, SIGNAL(clicked()), this, SLOT(launching()));
}

Launcher::~Launcher()
{
    delete _loginService;
    delete _modpackManager;
    delete _sessionManager;
    delete _config;
    delete _downloader;
}

void Launcher::checkConfig()
{
    // General configuration
    if (!_config->contains("general/modpacksPath"))
        _config->setValue("general/modpacksPath", QVariant(MODPACKS_DIR + "/modpacks.dat"));

    if (!_config->contains("general/sessionsPath"))
        _config->setValue("general/sessionsPath", QVariant(SESSIONS_DIR + "/sessions.dat"));
}

void Launcher::launching(QListWidgetItem *item)
{
}
