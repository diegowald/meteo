/****************************************************************************
** Meta object code from reading C++ file 'weatherdialog.h'
**
** Created: Sun 19. May 01:44:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../weatherdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_weatherDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x05,
      63,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,   14,   14,   14, 0x0a,
     114,   14,   14,   14, 0x0a,
     127,  123,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_weatherDialog[] = {
    "weatherDialog\0\0weather\0"
    "weatherAdd(metAstro::weatherParameter*)\0"
    "weatherMod(metAstro::weatherParameter*)\0"
    "accepted()\0closed()\0val\0typeChanged(QString)\0"
};

void weatherDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        weatherDialog *_t = static_cast<weatherDialog *>(_o);
        switch (_id) {
        case 0: _t->weatherAdd((*reinterpret_cast< metAstro::weatherParameter*(*)>(_a[1]))); break;
        case 1: _t->weatherMod((*reinterpret_cast< metAstro::weatherParameter*(*)>(_a[1]))); break;
        case 2: _t->accepted(); break;
        case 3: _t->closed(); break;
        case 4: _t->typeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData weatherDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject weatherDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_weatherDialog,
      qt_meta_data_weatherDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &weatherDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *weatherDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *weatherDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_weatherDialog))
        return static_cast<void*>(const_cast< weatherDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int weatherDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void weatherDialog::weatherAdd(metAstro::weatherParameter * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void weatherDialog::weatherMod(metAstro::weatherParameter * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
