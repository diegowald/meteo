/****************************************************************************
** Meta object code from reading C++ file 'positionsdialog.h'
**
** Created: Sun 19. May 01:44:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../positionsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'positionsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_positionsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   17,   16,   16, 0x05,
      70,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     115,   16,   16,   16, 0x0a,
     126,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_positionsDialog[] = {
    "positionsDialog\0\0position\0"
    "positionAdded(metAstro::positionParameter*)\0"
    "positionModded(metAstro::positionParameter*)\0"
    "accepted()\0closed()\0"
};

void positionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        positionsDialog *_t = static_cast<positionsDialog *>(_o);
        switch (_id) {
        case 0: _t->positionAdded((*reinterpret_cast< metAstro::positionParameter*(*)>(_a[1]))); break;
        case 1: _t->positionModded((*reinterpret_cast< metAstro::positionParameter*(*)>(_a[1]))); break;
        case 2: _t->accepted(); break;
        case 3: _t->closed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData positionsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject positionsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_positionsDialog,
      qt_meta_data_positionsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &positionsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *positionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *positionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_positionsDialog))
        return static_cast<void*>(const_cast< positionsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int positionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void positionsDialog::positionAdded(metAstro::positionParameter * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void positionsDialog::positionModded(metAstro::positionParameter * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
