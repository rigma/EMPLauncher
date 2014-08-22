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
#include <include/downloader.h>

#include <QFile>
#include <QNetworkRequest>

Downloader::Downloader(QObject *parent) : QObject(parent)
{
    _manager = new QNetworkAccessManager(this);

    connect(_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manageReply(QNetworkReply*)));
}

Downloader::~Downloader()
{
    disconnect(_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manageReply(QNetworkReply*)));

    delete _manager;
}

void Downloader::get(const QUrl &url)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, QVariant(USER_AGENT));

    _manager->get(request);
}

void Downloader::get(const QList<QUrl> &urls)
{
    QNetworkRequest *request = 0;

    for (auto url : urls.toStdList())
    {
        request = new QNetworkRequest(url);
        request->setHeader(QNetworkRequest::UserAgentHeader, QVariant(USER_AGENT));

        _manager->get(*request);

        delete request;
    }
}

void Downloader::manageReply(QNetworkReply *reply)
{
    QFile f(DOWNLOAD_PATH + "/" + reply->url().fileName());

    if (reply->error() == QNetworkReply::NoError)
    {
        if (!f.open(QIODevice::WriteOnly))
            return;

        f.write(reply->readAll());
        f.close();
    }

    reply->close();
    reply->deleteLater();
}
