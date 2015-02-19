/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun 19. May 01:44:20 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x0a,
      42,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      69,   11,   11,   11, 0x0a,
      86,   11,   11,   11, 0x0a,
      99,   11,   11,   11, 0x0a,
     114,   11,   11,   11, 0x0a,
     128,   11,   11,   11, 0x0a,
     142,   11,   11,   11, 0x0a,
     156,   11,   11,   11, 0x0a,
     173,   11,   11,   11, 0x0a,
     187,   11,   11,   11, 0x0a,
     203,   11,   11,   11, 0x0a,
     220,   11,   11,   11, 0x0a,
     237,   11,   11,   11, 0x0a,
     256,   11,   11,   11, 0x0a,
     275,   11,   11,   11, 0x0a,
     293,   11,   11,   11, 0x0a,
     312,   11,   11,   11, 0x0a,
     333,   11,   11,   11, 0x0a,
     344,   11,   11,   11, 0x0a,
     359,   11,   11,   11, 0x0a,
     371,   11,   11,   11, 0x0a,
     392,   11,   11,   11, 0x0a,
     415,   11,   11,   11, 0x0a,
     432,   11,   11,   11, 0x0a,
     459,  448,   11,   11, 0x0a,
     488,  483,   11,   11, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0val\0setWorkingDate(QDateTime)\0"
    "workingDate()\0cargaDeDia()\0cargaDeSizigia()\0"
    "modifyData()\0browseTables()\0browseMonth()\0"
    "showOptions()\0loadTPSData()\0"
    "loadSQLiteData()\0loadRDBData()\0"
    "weatherToNOAA()\0refreshFromRBD()\0"
    "refreshWeather()\0processByWeather()\0"
    "processByAspects()\0processByCycles()\0"
    "processByDignity()\0processByMonthRain()\0"
    "showDays()\0showSizigias()\0showExcel()\0"
    "recalcMothlyValues()\0calcPrimordialPoints()\0"
    "batchProcessor()\0fileProcessor()\0"
    "form,modal\0showForm(QWidget*,bool)\0"
    "form\0showForm(QWidget*)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->setWorkingDate((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 1: _t->workingDate(); break;
        case 2: _t->cargaDeDia(); break;
        case 3: _t->cargaDeSizigia(); break;
        case 4: _t->modifyData(); break;
        case 5: _t->browseTables(); break;
        case 6: _t->browseMonth(); break;
        case 7: _t->showOptions(); break;
        case 8: _t->loadTPSData(); break;
        case 9: _t->loadSQLiteData(); break;
        case 10: _t->loadRDBData(); break;
        case 11: _t->weatherToNOAA(); break;
        case 12: _t->refreshFromRBD(); break;
        case 13: _t->refreshWeather(); break;
        case 14: _t->processByWeather(); break;
        case 15: _t->processByAspects(); break;
        case 16: _t->processByCycles(); break;
        case 17: _t->processByDignity(); break;
        case 18: _t->processByMonthRain(); break;
        case 19: _t->showDays(); break;
        case 20: _t->showSizigias(); break;
        case 21: _t->showExcel(); break;
        case 22: _t->recalcMothlyValues(); break;
        case 23: _t->calcPrimordialPoints(); break;
        case 24: _t->batchProcessor(); break;
        case 25: _t->fileProcessor(); break;
        case 26: _t->showForm((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 27: _t->showForm((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
