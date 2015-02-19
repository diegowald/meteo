/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 19. May 01:43:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSalir;
    QAction *actionCarga_de_Dia;
    QAction *actionCarga_de_Sizigia;
    QAction *actionOpciones;
    QAction *actionVer_Tabla_de_Datos;
    QAction *actionModificacion_de_Datos;
    QAction *actionAspectos;
    QAction *actionTiempos;
    QAction *actionProcesar_Datos;
    QAction *actionBusqueda_Ping_Pong;
    QAction *actionBusqueda_por_Estado_de_Tiempo;
    QAction *actionCarga_en_Batch;
    QAction *actionProceso_Por_Tiempo;
    QAction *actionProceso_Por_Aspectos;
    QAction *actionProceso_Por_Ciclos;
    QAction *actionProceso_por_Posicion_Astral;
    QAction *actionVer_dias;
    QAction *actionCarga_de_Archivos;
    QAction *actionRecalcular_datos_Mensuales;
    QAction *actionVer_Datos_Mensuales;
    QAction *actionProcesar_por_Dignidad;
    QAction *actionProcesar_por_mes_lluvia;
    QAction *actionExportar_por_Sizigias_P_Primordiales;
    QAction *actionExportar_por_Fechas_Escogidas;
    QAction *actionCalcular_Pto_Primordiales;
    QAction *actionDefinir_Fecha_de_Trabajo;
    QAction *actionCargar_datos_RBD_y_SFD;
    QAction *actionRBD_a_Tiempos_Astrales;
    QAction *actionTiempos_Astrales_a_NOAA;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuCarga_de_Datos;
    QMenu *menuInformacion_Guardada;
    QMenu *menuListados;
    QMenu *menuExcel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(839, 525);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionCarga_de_Dia = new QAction(MainWindow);
        actionCarga_de_Dia->setObjectName(QString::fromUtf8("actionCarga_de_Dia"));
        actionCarga_de_Sizigia = new QAction(MainWindow);
        actionCarga_de_Sizigia->setObjectName(QString::fromUtf8("actionCarga_de_Sizigia"));
        actionOpciones = new QAction(MainWindow);
        actionOpciones->setObjectName(QString::fromUtf8("actionOpciones"));
        actionVer_Tabla_de_Datos = new QAction(MainWindow);
        actionVer_Tabla_de_Datos->setObjectName(QString::fromUtf8("actionVer_Tabla_de_Datos"));
        actionModificacion_de_Datos = new QAction(MainWindow);
        actionModificacion_de_Datos->setObjectName(QString::fromUtf8("actionModificacion_de_Datos"));
        actionAspectos = new QAction(MainWindow);
        actionAspectos->setObjectName(QString::fromUtf8("actionAspectos"));
        actionTiempos = new QAction(MainWindow);
        actionTiempos->setObjectName(QString::fromUtf8("actionTiempos"));
        actionProcesar_Datos = new QAction(MainWindow);
        actionProcesar_Datos->setObjectName(QString::fromUtf8("actionProcesar_Datos"));
        actionBusqueda_Ping_Pong = new QAction(MainWindow);
        actionBusqueda_Ping_Pong->setObjectName(QString::fromUtf8("actionBusqueda_Ping_Pong"));
        actionBusqueda_por_Estado_de_Tiempo = new QAction(MainWindow);
        actionBusqueda_por_Estado_de_Tiempo->setObjectName(QString::fromUtf8("actionBusqueda_por_Estado_de_Tiempo"));
        actionCarga_en_Batch = new QAction(MainWindow);
        actionCarga_en_Batch->setObjectName(QString::fromUtf8("actionCarga_en_Batch"));
        actionCarga_en_Batch->setEnabled(true);
        actionProceso_Por_Tiempo = new QAction(MainWindow);
        actionProceso_Por_Tiempo->setObjectName(QString::fromUtf8("actionProceso_Por_Tiempo"));
        actionProceso_Por_Aspectos = new QAction(MainWindow);
        actionProceso_Por_Aspectos->setObjectName(QString::fromUtf8("actionProceso_Por_Aspectos"));
        actionProceso_Por_Ciclos = new QAction(MainWindow);
        actionProceso_Por_Ciclos->setObjectName(QString::fromUtf8("actionProceso_Por_Ciclos"));
        actionProceso_por_Posicion_Astral = new QAction(MainWindow);
        actionProceso_por_Posicion_Astral->setObjectName(QString::fromUtf8("actionProceso_por_Posicion_Astral"));
        actionVer_dias = new QAction(MainWindow);
        actionVer_dias->setObjectName(QString::fromUtf8("actionVer_dias"));
        actionCarga_de_Archivos = new QAction(MainWindow);
        actionCarga_de_Archivos->setObjectName(QString::fromUtf8("actionCarga_de_Archivos"));
        actionRecalcular_datos_Mensuales = new QAction(MainWindow);
        actionRecalcular_datos_Mensuales->setObjectName(QString::fromUtf8("actionRecalcular_datos_Mensuales"));
        actionVer_Datos_Mensuales = new QAction(MainWindow);
        actionVer_Datos_Mensuales->setObjectName(QString::fromUtf8("actionVer_Datos_Mensuales"));
        actionProcesar_por_Dignidad = new QAction(MainWindow);
        actionProcesar_por_Dignidad->setObjectName(QString::fromUtf8("actionProcesar_por_Dignidad"));
        actionProcesar_por_mes_lluvia = new QAction(MainWindow);
        actionProcesar_por_mes_lluvia->setObjectName(QString::fromUtf8("actionProcesar_por_mes_lluvia"));
        actionExportar_por_Sizigias_P_Primordiales = new QAction(MainWindow);
        actionExportar_por_Sizigias_P_Primordiales->setObjectName(QString::fromUtf8("actionExportar_por_Sizigias_P_Primordiales"));
        actionExportar_por_Fechas_Escogidas = new QAction(MainWindow);
        actionExportar_por_Fechas_Escogidas->setObjectName(QString::fromUtf8("actionExportar_por_Fechas_Escogidas"));
        actionCalcular_Pto_Primordiales = new QAction(MainWindow);
        actionCalcular_Pto_Primordiales->setObjectName(QString::fromUtf8("actionCalcular_Pto_Primordiales"));
        actionDefinir_Fecha_de_Trabajo = new QAction(MainWindow);
        actionDefinir_Fecha_de_Trabajo->setObjectName(QString::fromUtf8("actionDefinir_Fecha_de_Trabajo"));
        actionCargar_datos_RBD_y_SFD = new QAction(MainWindow);
        actionCargar_datos_RBD_y_SFD->setObjectName(QString::fromUtf8("actionCargar_datos_RBD_y_SFD"));
        actionRBD_a_Tiempos_Astrales = new QAction(MainWindow);
        actionRBD_a_Tiempos_Astrales->setObjectName(QString::fromUtf8("actionRBD_a_Tiempos_Astrales"));
        actionTiempos_Astrales_a_NOAA = new QAction(MainWindow);
        actionTiempos_Astrales_a_NOAA->setObjectName(QString::fromUtf8("actionTiempos_Astrales_a_NOAA"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(true);

        verticalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 839, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuCarga_de_Datos = new QMenu(menuBar);
        menuCarga_de_Datos->setObjectName(QString::fromUtf8("menuCarga_de_Datos"));
        menuInformacion_Guardada = new QMenu(menuBar);
        menuInformacion_Guardada->setObjectName(QString::fromUtf8("menuInformacion_Guardada"));
        menuListados = new QMenu(menuBar);
        menuListados->setObjectName(QString::fromUtf8("menuListados"));
        menuExcel = new QMenu(menuBar);
        menuExcel->setObjectName(QString::fromUtf8("menuExcel"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuCarga_de_Datos->menuAction());
        menuBar->addAction(menuInformacion_Guardada->menuAction());
        menuBar->addAction(menuListados->menuAction());
        menuBar->addAction(menuExcel->menuAction());
        menuArchivo->addAction(actionDefinir_Fecha_de_Trabajo);
        menuArchivo->addAction(actionOpciones);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuCarga_de_Datos->addAction(actionCarga_de_Dia);
        menuCarga_de_Datos->addAction(actionCarga_de_Sizigia);
        menuCarga_de_Datos->addAction(actionModificacion_de_Datos);
        menuCarga_de_Datos->addAction(actionCargar_datos_RBD_y_SFD);
        menuCarga_de_Datos->addAction(actionRBD_a_Tiempos_Astrales);
        menuCarga_de_Datos->addAction(actionTiempos_Astrales_a_NOAA);
        menuCarga_de_Datos->addAction(actionCarga_en_Batch);
        menuCarga_de_Datos->addAction(actionCarga_de_Archivos);
        menuCarga_de_Datos->addAction(actionRecalcular_datos_Mensuales);
        menuInformacion_Guardada->addAction(actionVer_Tabla_de_Datos);
        menuInformacion_Guardada->addAction(actionVer_dias);
        menuInformacion_Guardada->addAction(actionVer_Datos_Mensuales);
        menuListados->addAction(actionProceso_Por_Tiempo);
        menuListados->addAction(actionProceso_Por_Aspectos);
        menuListados->addAction(actionProceso_Por_Ciclos);
        menuListados->addAction(actionProceso_por_Posicion_Astral);
        menuListados->addAction(actionProcesar_por_Dignidad);
        menuListados->addAction(actionProcesar_por_mes_lluvia);
        menuExcel->addAction(actionExportar_por_Sizigias_P_Primordiales);
        menuExcel->addAction(actionExportar_por_Fechas_Escogidas);
        menuExcel->addAction(actionCalcular_Pto_Primordiales);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MeteoAstrologia v 1.0.115", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
        actionCarga_de_Dia->setText(QApplication::translate("MainWindow", "Carga de Dia", 0, QApplication::UnicodeUTF8));
        actionCarga_de_Sizigia->setText(QApplication::translate("MainWindow", "Carga de Sizigia", 0, QApplication::UnicodeUTF8));
        actionOpciones->setText(QApplication::translate("MainWindow", "Opciones", 0, QApplication::UnicodeUTF8));
        actionVer_Tabla_de_Datos->setText(QApplication::translate("MainWindow", "Ver Tabla de Datos", 0, QApplication::UnicodeUTF8));
        actionModificacion_de_Datos->setText(QApplication::translate("MainWindow", "Modificar Datos", 0, QApplication::UnicodeUTF8));
        actionAspectos->setText(QApplication::translate("MainWindow", "Aspectos", 0, QApplication::UnicodeUTF8));
        actionTiempos->setText(QApplication::translate("MainWindow", "Tiempos", 0, QApplication::UnicodeUTF8));
        actionProcesar_Datos->setText(QApplication::translate("MainWindow", "Procesar Datos por Varios", 0, QApplication::UnicodeUTF8));
        actionBusqueda_Ping_Pong->setText(QApplication::translate("MainWindow", "Busqueda \"Ping-Pong\"", 0, QApplication::UnicodeUTF8));
        actionBusqueda_por_Estado_de_Tiempo->setText(QApplication::translate("MainWindow", "Busqueda por Estado de Tiempo", 0, QApplication::UnicodeUTF8));
        actionCarga_en_Batch->setText(QApplication::translate("MainWindow", "Carga en Batch", 0, QApplication::UnicodeUTF8));
        actionProceso_Por_Tiempo->setText(QApplication::translate("MainWindow", "Proceso Por Estado de Tiempo", 0, QApplication::UnicodeUTF8));
        actionProceso_Por_Aspectos->setText(QApplication::translate("MainWindow", "Procesar por Aspectos", 0, QApplication::UnicodeUTF8));
        actionProceso_Por_Ciclos->setText(QApplication::translate("MainWindow", "Procesar por Ciclos", 0, QApplication::UnicodeUTF8));
        actionProceso_por_Posicion_Astral->setText(QApplication::translate("MainWindow", "Procesar por Posicion Astral", 0, QApplication::UnicodeUTF8));
        actionVer_dias->setText(QApplication::translate("MainWindow", "Ver dias", 0, QApplication::UnicodeUTF8));
        actionCarga_de_Archivos->setText(QApplication::translate("MainWindow", "Carga de Archivos", 0, QApplication::UnicodeUTF8));
        actionRecalcular_datos_Mensuales->setText(QApplication::translate("MainWindow", "Recalcular datos Mensuales", 0, QApplication::UnicodeUTF8));
        actionVer_Datos_Mensuales->setText(QApplication::translate("MainWindow", "Ver Datos Mensuales", 0, QApplication::UnicodeUTF8));
        actionProcesar_por_Dignidad->setText(QApplication::translate("MainWindow", "Procesar por Dignidad", 0, QApplication::UnicodeUTF8));
        actionProcesar_por_mes_lluvia->setText(QApplication::translate("MainWindow", "Procesar por mes-lluvia", 0, QApplication::UnicodeUTF8));
        actionExportar_por_Sizigias_P_Primordiales->setText(QApplication::translate("MainWindow", "Exportar por Sizigias/P. Primordiales", 0, QApplication::UnicodeUTF8));
        actionExportar_por_Fechas_Escogidas->setText(QApplication::translate("MainWindow", "Exportar por Fechas Escogidas", 0, QApplication::UnicodeUTF8));
        actionCalcular_Pto_Primordiales->setText(QApplication::translate("MainWindow", "Calcular Pto Primordiales", 0, QApplication::UnicodeUTF8));
        actionDefinir_Fecha_de_Trabajo->setText(QApplication::translate("MainWindow", "Definir Fecha de Trabajo", 0, QApplication::UnicodeUTF8));
        actionCargar_datos_RBD_y_SFD->setText(QApplication::translate("MainWindow", "Cargar datos RBD y SFD", 0, QApplication::UnicodeUTF8));
        actionRBD_a_Tiempos_Astrales->setText(QApplication::translate("MainWindow", "RBD a Tiempos Astrales", 0, QApplication::UnicodeUTF8));
        actionTiempos_Astrales_a_NOAA->setText(QApplication::translate("MainWindow", "Tiempos Astrales a NOAA", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuCarga_de_Datos->setTitle(QApplication::translate("MainWindow", "Carga de Datos", 0, QApplication::UnicodeUTF8));
        menuInformacion_Guardada->setTitle(QApplication::translate("MainWindow", "Informacion Guardada", 0, QApplication::UnicodeUTF8));
        menuListados->setTitle(QApplication::translate("MainWindow", "Procesar Datos", 0, QApplication::UnicodeUTF8));
        menuExcel->setTitle(QApplication::translate("MainWindow", "Excel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
