#include <QtWidgets>
#include <QtSql>
#include <QFile>
#include <QLibrary>
#include "astroinfo.h"
#include "mainwindow.h"
#include "utils.h"
#include <QDateTime>
#include <QtSql>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(resource);
    QApplication a(argc, argv);        
    MainWindow* w = MainWindow::instance();
    w->setLocale(QLocale(QLocale::Spanish, QLocale::Argentina));
    w->show();
    return a.exec();
}
