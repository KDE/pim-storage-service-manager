/*
  Copyright (c) 2014-2017 Montel Laurent <montel@kde.org>

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

#include "PimCommon/StorageServiceTreeWidget"
#include "PimCommon/StorageServiceAbstract"
class QEvent;
class StorageServiceTreeWidget : public PimCommon::StorageServiceTreeWidget
{
    Q_OBJECT
public:
    explicit StorageServiceTreeWidget(PimCommon::StorageServiceAbstract *storageService, QWidget *parent = nullptr);
    ~StorageServiceTreeWidget();

    void setIsInitialized();
    bool uploadFileToService();

    void canDownloadFile();

    bool listFolderWasLoaded() const;
    void logout();

    void deleteItem();
    void renameItem();
Q_SIGNALS:
    void uploadFile();
    void downloadFile();
    void listFileWasInitialized();

public Q_SLOTS:
    void slotCreateFolder();
    void slotDownloadFile();
    void slotDeleteFolder();
    void slotDeleteFile();
    void slotShareFile();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void createMenuActions(QMenu *menu) Q_DECL_OVERRIDE;
    void changeEvent(QEvent *event) Q_DECL_OVERRIDE;
private Q_SLOTS:

    void slotRenameFile();
    void slotRenameFolder();
    void slotCutFile();
    void slotCutFolder();
    void slotCopyFile();
    void slotCopyFolder();
    void slotMoveFolder();
    void slotMoveFile();
    void slotPasteFolder();
    void slotPasteFile();
    void slotFileDoubleClicked();
private:
    void generalPaletteChanged();
    void generalFontChanged();
    bool checkName(const QString &name);
    void readConfig();
    void writeConfig();
    void deleteFile();
    void deleteFolder();

    enum CopyType {
        UnknownType = 0,
        FileType = 1,
        FolderType = 2
    };

    struct copyCutItem {
        copyCutItem()
            : moveItem(false),
              type(UnknownType)
        {

        }
        bool moveItem;
        CopyType type;
        QString identifier;
    };

    QColor mTextColor;
    copyCutItem mCopyItem;
    PimCommon::StorageServiceAbstract::Capabilities mCapabilities;
    bool mInitialized;
};

#endif // STORAGESERVICETREEWIDGET_H
