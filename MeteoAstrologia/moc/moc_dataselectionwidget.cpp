/****************************************************************************
** Meta object code from reading C++ file 'dataselectionwidget.h'
**
** Created: Sun 19. May 01:44:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dataselectionwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataselectionwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dataSelectionWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   21,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_dataSelectionWidget[] = {
    "dataSelectionWidget\0\0l\0dataSelected(QStringList)\0"
    "select()\0"
};

void dataSelectionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dataSelectionWidget *_t = static_cast<dataSelectionWidget *>(_o);
        switch (_id) {
        case 0: _t->dataSelected((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->select(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dataSelectionWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dataSelectionWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dataSelectionWidget,
      qt_meta_data_dataSelectionWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dataSelectionWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dataSelectionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dataSelectionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dataSelectionWidget))
        return static_cast<void*>(const_cast< dataSelectionWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int dataSelectionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void dataSelectionWidget::dataSelected(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
