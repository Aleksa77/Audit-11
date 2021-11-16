#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SlotGetDiskInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotGetDiskInfo() {
    QStorageInfo storage = QStorageInfo::root();
    QList<QStorageInfo> list = QStorageInfo::mountedVolumes();

    int count = list.size();
    QString strInfo = "";
    for(int i = 0; i < count; ++i) {
        QStorageInfo diskInfo = list.at(i);
        qint64 freeSize = diskInfo.bytesFree();
        qint64 totalSize = diskInfo.bytesTotal();
        QString tempInfo = QString("Name:   %1\n   TypeFileSystem:   %2\n   TotalSize:   %3\n   FreeSize:   %4\n").arg(diskInfo.displayName()).arg(storage.fileSystemType()).arg(GetStorageSize(totalSize)).arg(GetStorageSize(freeSize));

        strInfo.append(tempInfo);
    }
    ui->textEdit->setText(strInfo);
}

QString MainWindow::GetStorageSize(qint64 size)
{
    if(size < 1024)
        return QString("%1 B").arg(size);
    else
        size = size / 1024;

    double tempSize = 1.0 * size;
    if(tempSize < 1024)
        return QString("%1 KB").arg(tempSize);
    else
        tempSize = tempSize / 1024;


    if(tempSize < 1024)
        return QString("%1 MB").arg(tempSize);
    else
        tempSize = tempSize / 1024;

    if(tempSize < 1024)
        return QString("%1 GB").arg(tempSize);
    else
        tempSize = tempSize / 1024;

    return "";
}

