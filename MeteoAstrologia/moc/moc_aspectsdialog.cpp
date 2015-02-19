/****************************************************************************
** Meta object code from reading C++ file 'aspectsdialog.h'
**
** Created: Sun 19. May 01:44:30 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../aspectsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aspectsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_aspectsDialog[] = {

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
      22,   15,   14,   14, 0x05,
      61,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     100,   14,   14,   14, 0x0a,
     111,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_aspectsDialog[] = {
    "aspectsDialog\0\0aspect\0"
    "aspectsAdd(metAstro::aspectParameter*)\0"
    "aspectsMod(metAstro::aspectParameter*)\0"
    "accepted()\0closed()\0"
};

void aspectsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        aspectsDialog *_t = static_cast<aspectsDialog *>(_o);
        switch (_id) {
        case 0: _t->aspectsAdd((*reinterpret_cast< metAstro::aspectParameter*(*)>(_a[1]))); break;
        case 1: _t->aspectsMod((*reinterpret_cast< metAstro::aspectParameter*(*)>(_a[1]))); break;
        case 2: _t->accepted(); break;
        case 3: _t->closed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData aspectsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject aspectsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_aspectsDialog,
      qt_meta_data_aspectsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &aspectsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *aspectsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *aspectsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_aspectsDialog))
        return static_cast<void*>(const_cast< aspectsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int aspectsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void aspectsDialog::aspectsAdd(metAstro::aspectParameter * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void aspectsDialog::aspectsMod(metAstro::aspectParameter * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
