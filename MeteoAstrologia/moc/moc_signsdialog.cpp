/****************************************************************************
** Meta object code from reading C++ file 'signsdialog.h'
**
** Created: Sun 19. May 01:44:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../signsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_signsDialog[] = {

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
      18,   13,   12,   12, 0x05,
      56,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      95,   12,   12,   12, 0x0a,
     106,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_signsDialog[] = {
    "signsDialog\0\0sign\0"
    "signsAdded(metAstro::signsParameter*)\0"
    "signsModded(metAstro::signsParameter*)\0"
    "accepted()\0closed()\0"
};

void signsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        signsDialog *_t = static_cast<signsDialog *>(_o);
        switch (_id) {
        case 0: _t->signsAdded((*reinterpret_cast< metAstro::signsParameter*(*)>(_a[1]))); break;
        case 1: _t->signsModded((*reinterpret_cast< metAstro::signsParameter*(*)>(_a[1]))); break;
        case 2: _t->accepted(); break;
        case 3: _t->closed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData signsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject signsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_signsDialog,
      qt_meta_data_signsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &signsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *signsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *signsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_signsDialog))
        return static_cast<void*>(const_cast< signsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int signsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void signsDialog::signsAdded(metAstro::signsParameter * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void signsDialog::signsModded(metAstro::signsParameter * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
