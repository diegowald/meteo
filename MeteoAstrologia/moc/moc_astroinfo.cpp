/****************************************************************************
** Meta object code from reading C++ file 'astroinfo.h'
**
** Created: Sun 19. May 01:44:42 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../astroinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'astroinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_astroInfo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   22,   10,   10, 0x0a,
      55,   10,   10,   10, 0x0a,
      71,   64,   10,   10, 0x0a,
      93,   86,   10,   10, 0x0a,
     124,  108,   10,   10, 0x0a,
     149,  108,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_astroInfo[] = {
    "astroInfo\0\0calcDone()\0datetime\0"
    "setTimestamp(QDateTime)\0doCalc()\0"
    "newlat\0setLat(double)\0newlon\0"
    "setLon(double)\0deg,min,seg,pos\0"
    "setLat(int,int,int,char)\0"
    "setLon(int,int,int,char)\0"
};

void astroInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        astroInfo *_t = static_cast<astroInfo *>(_o);
        switch (_id) {
        case 0: _t->calcDone(); break;
        case 1: _t->setTimestamp((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 2: _t->doCalc(); break;
        case 3: _t->setLat((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setLon((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setLat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< char(*)>(_a[4]))); break;
        case 6: _t->setLon((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< char(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData astroInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject astroInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_astroInfo,
      qt_meta_data_astroInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &astroInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *astroInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *astroInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_astroInfo))
        return static_cast<void*>(const_cast< astroInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int astroInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void astroInfo::calcDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
