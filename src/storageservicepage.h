/*
  Copyright (c) 2013-2017 Montel Laurent <montel@kde.org>

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

#ifndef STORAGESERVICEPAGE_H
#define STORAGESERVICEPAGE_H

#include <QWidget>
#include "PimCommon/StorageServiceAbstract"
#include "storageservicemanagerutil.h"
#include "PimCommon/StorageServiceTreeWidget"

namespace PimCommon
{
class StorageServiceAbstract;
class StorageServiceProgressWidget;
class StorageServiceProgressIndicator;
}
class StorageServiceWarning;
class StorageServiceTreeWidget;
class StorageServiceNavigationButtons;
class StorageServicePage : public QWidget
{
    Q_OBJECT
public:
    explicit StorageServicePage(const QString &serviceName, PimCommon::StorageServiceAbstract *storageService, QWidget *parent = nullptr);
    ~StorageServicePage();

    void authenticate();
    void createFolder();

    void accountInfo();
    void uploadFile();
    void deleteFile();
    PimCommon::StorageServiceAbstract::Capabilities capabilities() const;
    QString serviceName() const;
    bool hasUploadDownloadProgress() const;
    void setNetworkIsDown(bool state);
    void refreshList();
    void showLog();
    void downloadFile();
    bool listFolderWasLoaded() const;
    void logout();

    PimCommon::StorageServiceTreeWidget::ItemType itemTypeSelected() const;

    void deleteItem();
    void renameItem();
Q_SIGNALS:
    void updateIcon(const QIcon &pix, StorageServicePage *page);
    void updateStatusBarMessage(const QString &msg);
    void listFileWasInitialized();
    void selectionChanged();

public Q_SLOTS:
    void slotUploadFile();

private Q_SLOTS:
    void slotDownloadFile();
    void slotAccountInfoDone(const QString &serviceName, const PimCommon::AccountInfo &accountInfo);
    void slotUploadFileDone(const QString &serviceName, const QString &fileName);
    void slotuploadDownloadFileProgress(const QString &serviceName, qint64 done, qint64 total);
    void slotShareLinkDone(const QString &serviceName, const QString &link);
    void slotAuthenticationFailed(const QString &serviceName, const QString &error);
    void slotAuthenticationDone(const QString &serviceName);
    void slotActionFailed(const QString &serviceName, const QString &error);
    void slotProgressStateChanged(bool state);
    void slotUpdatePixmap(const QPixmap &pix);
    void slotListFolderDone(const QString &serviceName, const QVariant &data);
    void slotCreateFolderDone(const QString &serviceName, const QString &folder);
    void slotDeleteFolderDone(const QString &serviceName, const QString &folder);
    void slotDeleteFileDone(const QString &serviceName, const QString &filename);
    void slotRenameFolderDone(const QString &serviceName, const QString &fileName);
    void slotRenameFileDone(const QString &serviceName, const QString &fileName);
    void slotMoveFileDone(const QString &serviceName, const QString &filename);
    void slotMoveFolderDone(const QString &serviceName, const QString &filename);
    void slotCopyFileDone(const QString &serviceName, const QString &filename);
    void slotCopyFolderDone(const QString &serviceName, const QString &filename);
    void slotDownloadFileDone(const QString &serviceName, const QString &filename);
    void slotUploadFileFailed(const QString &serviceName, const QString &filename);
    void slotDownloadFileFailed(const QString &serviceName, const QString &filename);
    void slotGoHome();
    void slotChangeFolder(const QString &previousCurrentFolder, const QString &previousParentFolder);
    void slotChangeUrl(const InformationUrl &info);

private:
    bool verifyService(const QString &serviceName);
    inline void updateList(const QString &serviceName);
    void connectStorageService();
    QString mServiceName;
    PimCommon::StorageServiceAbstract *mStorageService;
    StorageServiceTreeWidget *mTreeWidget;
    PimCommon::StorageServiceProgressIndicator *mProgressIndicator;
    StorageServiceWarning *mStorageServiceWarning;
    StorageServiceNavigationButtons *mStorageServiceNavigationBar;
    PimCommon::StorageServiceProgressWidget *mProgressWidget;
};

#endif // STORAGESERVICEPAGE_H
