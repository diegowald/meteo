/****************************************************************************
** Meta object code from reading C++ file 'monthviewwidget.h'
**
** Created: Sun 19. May 01:44:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../monthviewwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monthviewwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_monthViewWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x0a,
      50,   17,   16,   16, 0x0a,
      80,   75,   16,   16, 0x0a,
     101,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_monthViewWidget[] = {
    "monthViewWidget\0\0index\0"
    "selectedMonth(QModelIndex)\0"
    "selectedDay(QModelIndex)\0data\0"
    "changeCombo(QString)\0resize()\0"
};

void monthViewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        monthViewWidget *_t = static_cast<monthViewWidget *>(_o);
        switch (_id) {
        case 0: _t->selectedMonth((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->selectedDay((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->changeCombo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->resize(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData monthViewWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject monthViewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_monthViewWidget,
      qt_meta_data_monthViewWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &monthViewWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *monthViewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *monthViewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_monthViewWidget))
        return static_cast<void*>(const_cast< monthViewWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int monthViewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
