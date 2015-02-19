/****************************************************************************
** Meta object code from reading C++ file 'dignitydialog.h'
**
** Created: Sun 19. May 01:44:53 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dignitydialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dignitydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dignityDialog[] = {

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
      21,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_dignityDialog[] = {
    "dignityDialog\0\0param\0"
    "addDignity(metAstro::dignityParam&)\0"
    "accepted()\0"
};

void dignityDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dignityDialog *_t = static_cast<dignityDialog *>(_o);
        switch (_id) {
        case 0: _t->addDignity((*reinterpret_cast< metAstro::dignityParam(*)>(_a[1]))); break;
        case 1: _t->accepted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dignityDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dignityDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dignityDialog,
      qt_meta_data_dignityDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dignityDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dignityDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dignityDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dignityDialog))
        return static_cast<void*>(const_cast< dignityDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int dignityDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void dignityDialog::addDignity(metAstro::dignityParam & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
