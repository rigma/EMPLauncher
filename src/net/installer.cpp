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

#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>

#include <globals.h>
#include <launcher.h>
#include <net/installer.h>

Installer::Installer(QObject *parent) : QObject(parent)
{
    _downloader = new Downloader(this);
}

Installer::~Installer()
{
    delete _downloader;
}

void Installer::install(const QString &modpackName, const QString &minecraftVersion)
{
    QDir dir;
    QFile f;
    QMap<QString, QString> mods;
    QJsonDocument versions;

    // First, we'll check that the correct version of minecraft is installed
    if (minecraftVersion == "lastest")
    {
        _downloader->get(QUrl("http://s3.amazonaws.com/Minecraft.Download/versions/versions.json"));

        f.setFileName(DOWNLOAD_DIR + "/versions.json");
        if (!f.exists() || !f.open(QIODevice::ReadOnly | QIODevice::Text))
            return; // TODO : display an error message

        versions = QJsonDocument::fromJson(f.readAll());
        f.close();

        if (!dir.exists(VERSIONS_DIR + "/" + versions.object().value("lastest").toObject().value("release").toString()))
            installMinecraft(versions.object().value("lastest").toObject().value("realease").toString());
    }
    else if (!dir.exists(VERSIONS_DIR + "/" + minecraftVersion))
        installMinecraft(minecraftVersion);

    // Then, we'll force the update of all the mods
    if (!dir.exists(MODPACKS_DIR + "/" + modpackName))
    {
        dir.mkpath(MODPACKS_DIR + "/" + modpackName);
        dir.mkpath(MODPACKS_DIR + "/" + modpackName + "/config");
        dir.mkpath(MODPACKS_DIR + "/" + modpackName + "/crash-reports");
        dir.mkpath(MODPACKS_DIR + "/" + modpackName + "/mods");
        dir.mkpath(MODPACKS_DIR + "/" + modpackName + "/resourcespack");
        dir.mkpath(MODPACKS_DIR + "/" + modpackName + "/saves");
        dir.mkpath(MODPACKS_DIR + "/" + modpackName + "/screenshots");
        dir.mkpath(MODPACKS_DIR + "/" + modpackName + "/stats");
    }

    mods = qobject_cast<Launcher*>(parent())->modpackManager()->modpack(modpackName)->mods();
    for (QString key : mods.keys().toStdList())
    {
        QStringList pathList = mods[key].split(QString("/"));
        QString path;

        if (pathList.size() > 1)
        {
            for (int i = 0 ; i < pathList.size() - 1 ; i++)
                path += "/" + pathList[i];

            _downloader->get(QUrl(mods[key]), MODPACKS_DIR + "/" + modpackName + "/mods" + path);
        }
        else
            _downloader->get(QUrl(mods[key]), MODPACKS_DIR + "/" + modpackName + "/mods");
    }
}

void Installer::installMinecraft(const QString &version)
{
    QDir dir;
    QJsonDocument manifest;
    QJsonArray libraries;
    QJsonObject object;
    QStringList package;
    QFile f;

    dir.mkpath(VERSIONS_DIR + "/" + version);

    _downloader->get(QUrl("http://s3.amazonaws.com/Minecraft.Download/versions/" + version + "/" + version + ".jar"), VERSIONS_DIR + "/" + version);
    _downloader->get(QUrl("http://s3.amazonaws.con/Minecraft.Download/versions/" + version + "/" + version + ".json"), VERSIONS_DIR + "/" + version);

    f.setFileName(VERSIONS_DIR + "/" + version + "/" + version + ".json");
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        return; // TODO : add an error message

    manifest = QJsonDocument::fromJson(f.readAll());
    libraries = manifest.object().value("libraries").toArray();
    f.close();

    dir.mkpath(LIB_DIR + "/" + version);

    for (int i = 0 ; i < libraries.size() - 1 ; i++)
    {
        if (libraries[i].toObject().contains("native"))
        {
            package = libraries[i].toObject().value("name").toString().split(":");
            package[0].replace(QString("."), QString("/"));

#if defined(Q_OS_LINUX)
            _downloader->get(QUrl("https://libraries.minecraft.net/" + package[0] +
                                  "/" + package[1] +
                                  "/" + package[2] +
                                  "/" + package[1] +
                                  "-" + package[2] +
                                  "-" + libraries[i].toObject().value("native").toObject().value(QString("linux")).toString() + ".jar"), LIB_DIR + "/" + version);
            _downloader->get(QUrl("https://libraries.minecraft.net/" + package[0] +
                                  "/" + package[1] +
                                  "/" + package[2] +
                                  "/" + package[1] +
                                  "-" + package[2] +
                                  "-" + libraries[i].toObject().value("native").toObject().value(QString("linux")).toString() + ".jar.sha1"), LIB_DIR + "/" + version);
#elif defined(Q_OS_WIN)
            _downloader->get(QUrl("https://libraries.minecraft.net/" + package[0] +
                                  "/" + package[1] +
                                  "/" + package[2] +
                                  "/" + package[1] +
                                  "-" + package[2] +
                                  "-" + libraries[i].toObject().value("native").toObject().value(QString("windows")).toString() + ".jar"), LIB_DIR + "/" + version);
            _downloader->get(QUrl("https://libraries.minecraft.net/" + package[0] +
                                  "/" + package[1] +
                                  "/" + package[2] +
                                  "/" + package[1] +
                                  "-" + package[2] +
                                  "-" + libraries[i].toObject().value("native").toObject().value(QString("windows")).toString() + ".jar.sha1"), LIB_DIR + "/" + version);
#elif defined(Q_OS_OSX)
            _downloader->get(QUrl("https://libraries.minecraft.net/" + package[0] +
                                  "/" + package[1] +
                                  "/" + package[2] +
                                  "/" + package[1] +
                                  "-" + package[2] +
                                  "-" + libraries[i].toObject().value("native").toObject().value(QString("osx")).toString() + ".jar"), LIB_DIR + "/" + version);
            _downloader->get(QUrl("https://libraries.minecraft.net/" + package[0] +
                                  "/" + package[1] +
                                  "/" + package[2] +
                                  "/" + package[1] +
                                  "-" + package[2] +
                                  "-" + libraries[i].toObject().value("native").toObject().value(QString("osx")).toString() + ".jar.sha1"), LIB_DIR + "/" + version);
#endif
        }
        else
        {
            package = libraries[i].toObject().value("name").toString().split(":");
            package[0].replace(QString("."), QString("/"));

            _downloader->get(QUrl("https://libraries.minecraft.net/" + package[0] +
                                  "/" + package[1] +
                                  "/" + package[2] +
                                  "/" + package[1] + "-" + package[2] + ".jar"), LIB_DIR + "/" + version);
            _downloader->get(QUrl("https://libraries.minecraft.net/" + package[0] +
                                  "/" + package[1] +
                                  "/" + package[2] +
                                  "/" + package[1] + "-" + package[2] + ".jar"), LIB_DIR + "/" + version);
        }
    }

    _downloader->get(QUrl("https://s3.amazonaws.com/Minecraft.Download/indexes/" + version + ".json"), ASSETS_DIR + "/indexes");

    // TODO : display an message to signal that we've finished to install minecraft
}
