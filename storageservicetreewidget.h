/*
  Copyright (c) 2014 Montel Laurent <montel@kde.org>

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU Library General Public License as published by
  the Free Software Foundation; either version 2 of the License, or (at your
  option) any later version.

  This library is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
  License for more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; see the file COPYING.LIB.  If not, write to the
  Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.

*/


#ifndef STORAGESERVICETREEWIDGET_H
#define STORAGESERVICETREEWIDGET_H

#include "pimcommon/storageservice/storageservicetreewidget.h"
#include "pimcommon/storageservice/storageserviceabstract.h"
class StorageServiceTreeWidget : public PimCommon::StorageServiceTreeWidget
{
    Q_OBJECT
public:
    explicit StorageServiceTreeWidget(PimCommon::StorageServiceAbstract *storageService, QWidget *parent=0);
    ~StorageServiceTreeWidget();

Q_SIGNALS:
    void goToFolder(const QString &folder);

public Q_SLOTS:
    void slotCreateFolder();
    void slotUploadFile();
    void slotDownloadFile();
    void slotDeleteFolder();
    void slotDeleteFile();
    void slotShareFile();

private Q_SLOTS:
    void slotContextMenu(const QPoint &pos);
    void slotMoveUp();
    void slotItemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    PimCommon::StorageServiceAbstract *mStorageService;
    PimCommon::StorageServiceAbstract::Capabilities mCapabilities;
};

#endif // STORAGESERVICETREEWIDGET_H