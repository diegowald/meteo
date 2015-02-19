/****************************************************************************
** Meta object code from reading C++ file 'processbymonths.h'
**
** Created: Sun 19. May 01:44:54 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processbymonths.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processbymonths.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_processByMonths[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      33,   27,   16,   16, 0x0a,
      60,   27,   16,   16, 0x0a,
      83,   27,   16,   16, 0x0a,
     107,   16,   16,   16, 0x0a,
     119,  116,   16,   16, 0x0a,
     137,  116,   16,   16, 0x0a,
     153,  116,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_processByMonths[] = {
    "processByMonths\0\0refresh()\0index\0"
    "weatherChange(QModelIndex)\0"
    "dayChange(QModelIndex)\0noaaChange(QModelIndex)\0"
    "doCalc()\0pt\0monthMenu(QPoint)\0"
    "dayMenu(QPoint)\0noaaMenu(QPoint)\0"
};

void processByMonths::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        processByMonths *_t = static_cast<processByMonths *>(_o);
        switch (_id) {
        case 0: _t->refresh(); break;
        case 1: _t->weatherChange((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->dayChange((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->noaaChange((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: _t->doCalc(); break;
        case 5: _t->monthMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->dayMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->noaaMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData processByMonths::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject processByMonths::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_processByMonths,
      qt_meta_data_processByMonths, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &processByMonths::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *processByMonths::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *processByMonths::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_processByMonths))
        return static_cast<void*>(const_cast< processByMonths*>(this));
    return QWidget::qt_metacast(_clname);
}

int processByMonths::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
