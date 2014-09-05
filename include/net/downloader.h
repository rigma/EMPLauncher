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
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QUrl>

#include <globals.h>

class Downloader : public QObject
{
    Q_OBJECT

public:
    Downloader(QObject *parent = nullptr);
    ~Downloader();

public:
    QNetworkAccessManager *manager();

public:
    void get(const QUrl &url, const QString &destPath = QString(DOWNLOAD_DIR));
    void get(const QList<QUrl> &urls, const QStringList &destPaths = QStringList(DOWNLOAD_DIR));
    void post(const QUrl &url, const QByteArray &data, const QString &destPath = QString(DOWNLOAD_DIR));

private slots:
    void manageReply(QNetworkReply *reply);

private:
    QMap<QString, QString> _downloads;
    QNetworkAccessManager *_manager;

signals:
    void downloadFailed(QNetworkReply *reply);
    void downloadFinished(const QString &path);
};

#endif // DOWNLOADER_H
