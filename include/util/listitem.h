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

#ifndef LISTITEM_H
#define LISTITEM_H

#include <QListWidgetItem>
#include <QIcon>
#include <QString>

class ListItem : public QListWidgetItem
{
public:
    ListItem(QListWidget *view = nullptr);
    ListItem(const QString &text, QListWidget *view = nullptr);
    ListItem(const QIcon &icon, const QString &text, QListWidget *view = nullptr);
    ListItem(const QIcon &icon, const QString &text, const QString &id, QListWidget *view = nullptr);
    ListItem(const ListItem &item);

public:
    QString id() const;
    void setId(const QString &id);

private:
    QString _id;
};

#endif // LISTITEM_H
