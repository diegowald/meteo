/****************************************************************************
** Meta object code from reading C++ file 'processdatawidget.h'
**
** Created: Sun 19. May 01:44:29 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processdatawidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processdatawidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_processDataWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   19,   18,   18, 0x0a,
      67,   19,   18,   18, 0x0a,
     108,   18,   18,   18, 0x0a,
     121,   18,   18,   18, 0x0a,
     134,   18,   18,   18, 0x0a,
     155,  147,   18,   18, 0x0a,
     197,  147,   18,   18, 0x0a,
     239,   18,   18,   18, 0x0a,
     252,   18,   18,   18, 0x0a,
     265,   18,   18,   18, 0x0a,
     278,   18,   18,   18, 0x0a,
     288,   18,   18,   18, 0x0a,
     305,   18,   18,   18, 0x0a,
     321,   18,   18,   18, 0x0a,
     337,   18,   18,   18, 0x0a,
     353,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_processDataWidget[] = {
    "processDataWidget\0\0aspect\0"
    "aspectsAdded(metAstro::aspectParameter*)\0"
    "aspectsModif(metAstro::aspectParameter*)\0"
    "addAspects()\0modAspects()\0delAspects()\0"
    "weather\0weatherAdded(metAstro::weatherParameter*)\0"
    "weatherModif(metAstro::weatherParameter*)\0"
    "addWeather()\0modWeather()\0delWeather()\0"
    "refresh()\0refreshWeather()\0refreshAspect()\0"
    "refreshResult()\0processAspect()\0"
    "processWeather()\0"
};

void processDataWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        processDataWidget *_t = static_cast<processDataWidget *>(_o);
        switch (_id) {
        case 0: _t->aspectsAdded((*reinterpret_cast< metAstro::aspectParameter*(*)>(_a[1]))); break;
        case 1: _t->aspectsModif((*reinterpret_cast< metAstro::aspectParameter*(*)>(_a[1]))); break;
        case 2: _t->addAspects(); break;
        case 3: _t->modAspects(); break;
        case 4: _t->delAspects(); break;
        case 5: _t->weatherAdded((*reinterpret_cast< metAstro::weatherParameter*(*)>(_a[1]))); break;
        case 6: _t->weatherModif((*reinterpret_cast< metAstro::weatherParameter*(*)>(_a[1]))); break;
        case 7: _t->addWeather(); break;
        case 8: _t->modWeather(); break;
        case 9: _t->delWeather(); break;
        case 10: _t->refresh(); break;
        case 11: _t->refreshWeather(); break;
        case 12: _t->refreshAspect(); break;
        case 13: _t->refreshResult(); break;
        case 14: _t->processAspect(); break;
        case 15: _t->processWeather(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData processDataWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject processDataWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_processDataWidget,
      qt_meta_data_processDataWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &processDataWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *processDataWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *processDataWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_processDataWidget))
        return static_cast<void*>(const_cast< processDataWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int processDataWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
