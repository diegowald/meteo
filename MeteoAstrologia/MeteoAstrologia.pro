#-------------------------------------------------
#
# Project created by QtCreator 2011-04-01T09:40:54
#
#-------------------------------------------------

QT       += core gui sql

TARGET = AstroMeteorologia
TEMPLATE = app

MOC_DIR = moc
OBJECTS_DIR = obj
DESTDIR = bin

SOURCES += main.cpp\
        mainwindow.cpp \
    grabdatawidget.cpp \
    browsewidget.cpp \
    graphicswidget.cpp \
    dataselectionwidget.cpp \
    optionswidget.cpp \
    browsetablewidget.cpp \
    dataprocessor.cpp \
    datamodificationwidget.cpp \
    processdatawidget.cpp \
    aspectsdialog.cpp \
    weatherdialog.cpp \
    dataprocessorwidget.cpp \
    positionsdialog.cpp \
    housesdialog.cpp \
    signsdialog.cpp \
    cuadrantesdialog.cpp \
    pingpongwidget.cpp \
    batchastrologicgrabdata.cpp \
    sweph.cpp \
    astroinfo.cpp \
    utils.cpp \
    batchprocesswidget.cpp \
    processbyweatherwidget.cpp \
    weatherdisplaywidget.cpp \
    fileloadwidget.cpp \
    processbyaspectwidget.cpp \
    monthviewwidget.cpp \
    processbypositionwidget.cpp \
    processbydignitywidget.cpp \
    dignitydialog.cpp \
    processbymonths.cpp \
    processbycycleswidget.cpp \
    sizigiaexcelreportwidget.cpp \
    excelexportwidget.cpp \
    freezetablewidget.cpp \
    workingdatedialog.cpp \
    specialrowtablemodel.cpp \
    rbdtoweatherdialog.cpp \
    weathertonoaadialog.cpp \
    calcptosprimordialesdialog.cpp \
    monthcalcdialog.cpp

HEADERS  += mainwindow.h \
    grabdatawidget.h \
    browsewidget.h \
    graphicswidget.h \
    dataselectionwidget.h \
    optionswidget.h \
    browsetablewidget.h \
    dataprocessor.h \
    datamodificationwidget.h \
    processdatawidget.h \
    aspectsdialog.h \
    weatherdialog.h \
    dataprocessorwidget.h \
    positionsdialog.h \
    housesdialog.h \
    signsdialog.h \
    cuadrantesdialog.h \
    pingpongwidget.h \
    batchastrologicgrabdata.h \
    E:\shaka\dev\current\soft\MeteoAstrologia\sweph\src\swephexp.h \
    sweph.h \
    astroinfo.h \
    utils.h \
    batchprocesswidget.h \
    processbyweatherwidget.h \
    weatherdisplaywidget.h \
    fileloadwidget.h \
    version.h \
    processbyaspectwidget.h \
    monthviewwidget.h \
    processbypositionwidget.h \
    processbydignitywidget.h \
    dignitydialog.h \
    processbymonths.h \
    processbycycleswidget.h \
    sizigiaexcelreportwidget.h \
    excelexportwidget.h \
    freezetablewidget.h \
    workingdatedialog.h \
    specialrowtablemodel.h \
    rbdtoweatherdialog.h \
    weathertonoaadialog.h \
    calcptosprimordialesdialog.h \
    monthcalcdialog.h

FORMS    += mainwindow.ui \
    grabdatawidget.ui \
    browsewidget.ui \
    graphicswidget.ui \
    dataselectionwidget.ui \
    optionswidget.ui \
    browsetablewidget.ui \
    datamodificationwidget.ui \
    processdatawidget.ui \
    aspectsdialog.ui \
    weatherdialog.ui \
    dataprocessorwidget.ui \
    positionsdialog.ui \
    housesdialog.ui \
    signsdialog.ui \
    cuadrantesdialog.ui \
    batchastrologicgrabdata.ui \
    batchprocesswidget.ui \
    processbyweatherwidget.ui \
    weatherdisplaywidget.ui \
    fileloadwidget.ui \
    processbyaspectwidget.ui \
    monthviewwidget.ui \
    processbypositionwidget.ui \
    processbydignitywidget.ui \
    dignitydialog.ui \
    processbymonths.ui \
    processbycycleswidget.ui \
    sizigiaexcelreportwidget.ui \
    excelexportwidget.ui \
    workingdatedialog.ui \
    rbdtoweatherdialog.ui \
    weathertonoaadialog.ui \
    calcptosprimordialesdialog.ui \
    monthcalcdialog.ui

OTHER_FILES += \
    ToDo.txt \
    archivos.txt

INCLUDEPATH += "E:\shaka\dev\current\soft\MeteoAstrologia\sweph\src"
DEFINES += USE_DLL
DEFINES += DOS32
DEFINES += DOS_DEGREE
#LIBS += -L "E:\shaka\dev\current\soft\MeteoAstrologia\sweph\bin"
LIBS += "C:\trabajos\MeteoAstrologia\sweph\bin\swedll32.lib"
LIBS += "C:\trabajos\MeteoAstrologia\sweph\bin\swetrm32.lib"
LIBS += "C:\trabajos\MeteoAstrologia\sweph\bin\swetrs32.lib"

LIBS += -lqaxserver

CONFIG += thread
CONFIG += no_lflags_merge
CONFIG += qaxcontainer

RESOURCES += \
    resource.qrc








