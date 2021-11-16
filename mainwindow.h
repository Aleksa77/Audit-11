#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStorageInfo>
#include <QString>
#include <QList>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString GetStorageSize(qint64 size);

private:
    Ui::MainWindow *ui;

public slots:
    void SlotGetDiskInfo();

public:
      QList<QString> name;
      QList<qint64> freeSize;
      QList<qint64> totalSize;
      QList<QString> fileSystemType;
};
#endif // MAINWINDOW_H
