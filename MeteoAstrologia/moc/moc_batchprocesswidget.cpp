/****************************************************************************
** Meta object code from reading C++ file 'batchprocesswidget.h'
**
** Created: Sun 19. May 01:44:43 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../batchprocesswidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batchprocesswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BatchProcessWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BatchProcessWidget[] = {
    "BatchProcessWidget\0\0doCalc()\0"
};

void BatchProcessWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BatchProcessWidget *_t = static_cast<BatchProcessWidget *>(_o);
        switch (_id) {
        case 0: _t->doCalc(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BatchProcessWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BatchProcessWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BatchProcessWidget,
      qt_meta_data_BatchProcessWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BatchProcessWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BatchProcessWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BatchProcessWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BatchProcessWidget))
        return static_cast<void*>(const_cast< BatchProcessWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BatchProcessWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
