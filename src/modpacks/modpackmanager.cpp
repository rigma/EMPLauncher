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

#include <include/globals.h>
#include <include/modpacks/modpackmanager.h>

ModpackManager::ModpackManager(QObject *parent) : QObject(parent),
    _modpacks(),
    _modpackDir()
{

}

ModpackManager::ModpackManager(const QString &modpackDir, QObject *parent) : QObject(parent),
    _modpacks(),
    _modpackDir(modpackDir)
{
    QDir dir(modpackDir);
    QFile f;

    for (QString entry : dir.entryList().toStdList())
    {
        f.setFileName(dir.absoluteFilePath(entry));
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
            continue;

        _modpacks.append(new Modpack(QJsonDocument::fromJson(f.readAll())));

        f.close();
    }
}

ModpackManager::~ModpackManager()
{
    for (Modpack *m : _modpacks.toStdList())
    {
        _modpacks.removeOne(m);

        delete m;
    }
}

Modpack *ModpackManager::modpack(const QString &name) const
{
    Modpack *result(nullptr);

    for (Modpack *m : _modpacks.toStdList())
    {
        if (m->name() == name)
        {
            result = m;

            break;
        }
    }

    return result;
}

QString ModpackManager::getModpackSettings(const QString &name) const
{
    QFile f(MODPACKS_DIR + "/" + name + ".ini");

    if (!f.exists())
    {
        f.open(QIODevice::WriteOnly);
        f.close();
    }

    return MODPACKS_DIR + "/" + name + ".ini";
}

QString ModpackManager::getModpackPresentation(const QString &name) const
{
    // TODO

    return QString();
}

QString ModpackManager::modpackDir() const
{
    return _modpackDir;
}

void ModpackManager::setModpackDir(const QString &modpackDir)
{
    _modpackDir = modpackDir;
}

void ModpackManager::addModpack(QString name)
{
    QFile f(QDir(_modpackDir).absoluteFilePath(name));

    if (!f.exists() || !f.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    _modpacks.append(new Modpack(QJsonDocument::fromJson(f.readAll())));
    f.close();
}
