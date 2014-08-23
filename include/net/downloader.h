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

#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QUrl>

class Downloader : public QObject
{
    Q_OBJECT

public:
    Downloader(QObject *parent = 0);
    ~Downloader();

public:
    void get(const QUrl &url);
    void get(const QList<QUrl> &urls);
    void post(const QUrl &url, const QByteArray &data);

private slots:
    void manageReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *_manager;
};

#endif // DOWNLOADER_H
