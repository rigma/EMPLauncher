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
#include <QNetworkRequest>

#include <include/globals.h>
#include <include/net/downloader.h>

Downloader::Downloader(QObject *parent) : QObject(parent),
    _downloads()
{
    _manager = new QNetworkAccessManager(this);

    connect(_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manageReply(QNetworkReply*)));
}

Downloader::~Downloader()
{
    disconnect(_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manageReply(QNetworkReply*)));

    delete _manager;
}

QNetworkAccessManager *Downloader::manager()
{
    return _manager;
}

void Downloader::get(const QUrl &url, const QString &destPath)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, QVariant(USER_AGENT));

    _manager->get(request);
    _downloads.insert(url.fileName(), destPath);
}

void Downloader::get(const QList<QUrl> &urls, const QStringList &destPaths)
{
    QNetworkRequest *request = 0;

    if (urls.size() != destPaths.size())
        return; // TODO : display an error message

    for (int i = 0 ; i < urls.size() ; i++)
    {
        request = new QNetworkRequest(urls[i]);
        request->setHeader(QNetworkRequest::UserAgentHeader, QVariant(USER_AGENT));

        _manager->get(*request);
        _downloads.insert(urls[i].fileName(), destPaths[i]);

        delete request;
    }
}

void Downloader::post(const QUrl &url, const QByteArray &data, const QString &destPath)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, QVariant(USER_AGENT));

    _manager->post(request, data);
    _downloads.insert(url.fileName(), destPath);
}

void Downloader::manageReply(QNetworkReply *reply)
{
    QDir dir;
    QFile f;

    if (reply->error() == QNetworkReply::NoError)
    {
        if (!_downloads.contains(reply->url().fileName()))
        {
            emit downloadFailed(reply);

            return;
        }

        if (!dir.exists(_downloads.value(reply->url().fileName())))
            dir.mkpath(_downloads.value(reply->url().fileName()));

        f.setFileName(_downloads.value(reply->url().fileName()) + "/" + reply->url().fileName());
        if (!f.open(QIODevice::WriteOnly))
            return;

        f.write(reply->readAll());
        f.close();
    }
    else
        emit downloadFailed(reply);

    reply->close();
    reply->deleteLater();

    emit downloadFinished(_downloads.value(reply->url().fileName()) + "/" + reply->url().fileName());

    _downloads.remove(reply->url().fileName());
}
