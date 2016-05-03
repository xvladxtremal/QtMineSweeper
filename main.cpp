#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QStringList>
#include <qDebug>

int main(int argc, char *argv[])
{
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("lib");
    paths.append("lib/platforms");
    QCoreApplication::setLibraryPaths(paths);

    QApplication a(argc, argv);
    a.setLibraryPaths(paths);
    MainWindow w;
    w.show();

    w.setWindowTitle("Сапёр");


    return a.exec();
}
