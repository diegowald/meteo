/****************************************************************************
** Meta object code from reading C++ file 'processbyweatherwidget.h'
**
** Created: Sun 19. May 01:44:44 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processbyweatherwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processbyweatherwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_processByWeatherWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x0a,
      50,   44,   23,   23, 0x0a,
      90,   23,   23,   23, 0x0a,
     103,   23,   23,   23, 0x0a,
     113,   23,   23,   23, 0x0a,
     135,  129,   23,   23, 0x0a,
     163,   23,   23,   23, 0x0a,
     176,   23,   23,   23, 0x0a,
     190,  187,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_processByWeatherWidget[] = {
    "processByWeatherWidget\0\0openWeatherDialog()\0"
    "param\0addWeather(metAstro::weatherParameter*)\0"
    "delWeather()\0refresh()\0refreshResult()\0"
    "index\0openDateWidget(QModelIndex)\0"
    "typeChange()\0doFilter()\0pt\0dayMenu(QPoint)\0"
};

void processByWeatherWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        processByWeatherWidget *_t = static_cast<processByWeatherWidget *>(_o);
        switch (_id) {
        case 0: _t->openWeatherDialog(); break;
        case 1: _t->addWeather((*reinterpret_cast< metAstro::weatherParameter*(*)>(_a[1]))); break;
        case 2: _t->delWeather(); break;
        case 3: _t->refresh(); break;
        case 4: _t->refreshResult(); break;
        case 5: _t->openDateWidget((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->typeChange(); break;
        case 7: _t->doFilter(); break;
        case 8: _t->dayMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData processByWeatherWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject processByWeatherWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_processByWeatherWidget,
      qt_meta_data_processByWeatherWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &processByWeatherWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *processByWeatherWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *processByWeatherWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_processByWeatherWidget))
        return static_cast<void*>(const_cast< processByWeatherWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int processByWeatherWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
