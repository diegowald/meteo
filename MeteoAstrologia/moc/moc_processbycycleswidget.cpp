/****************************************************************************
** Meta object code from reading C++ file 'processbycycleswidget.h'
**
** Created: Sun 19. May 01:44:55 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processbycycleswidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processbycycleswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_processByCyclesWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      38,   32,   22,   22, 0x0a,
      70,   65,   22,   22, 0x0a,
      94,   91,   22,   22, 0x0a,
     113,   91,   22,   22, 0x0a,
     130,   91,   22,   22, 0x0a,
     148,   91,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_processByCyclesWidget[] = {
    "processByCyclesWidget\0\0doCalc()\0index\0"
    "phaseSelected(QModelIndex)\0type\0"
    "typeChanged(QString)\0pt\0astralMenu(QPoint)\0"
    "noaaMenu(QPoint)\0monthMenu(QPoint)\0"
    "phaseMenu(QPoint)\0"
};

void processByCyclesWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        processByCyclesWidget *_t = static_cast<processByCyclesWidget *>(_o);
        switch (_id) {
        case 0: _t->doCalc(); break;
        case 1: _t->phaseSelected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->typeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->astralMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->noaaMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->monthMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->phaseMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData processByCyclesWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject processByCyclesWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_processByCyclesWidget,
      qt_meta_data_processByCyclesWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &processByCyclesWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *processByCyclesWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *processByCyclesWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_processByCyclesWidget))
        return static_cast<void*>(const_cast< processByCyclesWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int processByCyclesWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
