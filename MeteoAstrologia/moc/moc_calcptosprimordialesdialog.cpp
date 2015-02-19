/****************************************************************************
** Meta object code from reading C++ file 'calcptosprimordialesdialog.h'
**
** Created: Sun 19. May 01:45:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calcptosprimordialesdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calcptosprimordialesdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_calcPtosPrimordialesDialog[] = {

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
      28,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_calcPtosPrimordialesDialog[] = {
    "calcPtosPrimordialesDialog\0\0doCalc()\0"
};

void calcPtosPrimordialesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        calcPtosPrimordialesDialog *_t = static_cast<calcPtosPrimordialesDialog *>(_o);
        switch (_id) {
        case 0: _t->doCalc(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData calcPtosPrimordialesDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject calcPtosPrimordialesDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_calcPtosPrimordialesDialog,
      qt_meta_data_calcPtosPrimordialesDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &calcPtosPrimordialesDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *calcPtosPrimordialesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *calcPtosPrimordialesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_calcPtosPrimordialesDialog))
        return static_cast<void*>(const_cast< calcPtosPrimordialesDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int calcPtosPrimordialesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
