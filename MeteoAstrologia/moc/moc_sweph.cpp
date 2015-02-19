/****************************************************************************
** Meta object code from reading C++ file 'sweph.h'
**
** Created: Sun 19. May 01:44:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sweph.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sweph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_sweph[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       6, 0x0,   17,   22,
      12, 0x0,   16,   56,

 // enum data: key, value
      20, uint(sweph::SEFLG_JPLEPH),
      33, uint(sweph::SEFLG_SWIEPH),
      46, uint(sweph::SEFLG_MOSEPH),
      59, uint(sweph::SEFLG_HELCTR),
      72, uint(sweph::SEFLG_TRUEPOS),
      86, uint(sweph::SEFLG_J2000),
      98, uint(sweph::SEFLG_NONUT),
     110, uint(sweph::SEFLG_SPEED3),
     123, uint(sweph::SEFLG_SPEED),
     135, uint(sweph::SEFLG_NOGDEFL),
     149, uint(sweph::SEFLG_NOABERR),
     163, uint(sweph::SEFLG_EQUATORIAL),
     180, uint(sweph::SEFLG_XYZ),
     190, uint(sweph::SEFLG_RADIANS),
     204, uint(sweph::SEFLG_BARYCTR),
     218, uint(sweph::SEFLG_TOPOCTR),
     232, uint(sweph::SEFLG_SIDEREAL),
     247, uint(sweph::SE_SUN),
     254, uint(sweph::SE_MOON),
     262, uint(sweph::SE_MERCURY),
     273, uint(sweph::SE_VENUS),
     282, uint(sweph::SE_MARS),
     290, uint(sweph::SE_JUPITER),
     301, uint(sweph::SE_SATURN),
     311, uint(sweph::SE_URANUS),
     321, uint(sweph::SE_NEPTUNE),
     332, uint(sweph::SE_PLUTO),
     341, uint(sweph::SE_MEAN_NODE),
     354, uint(sweph::SE_TRUE_NODE),
     367, uint(sweph::SE_MEAN_APOG),
     380, uint(sweph::SE_OSCU_APOG),
     393, uint(sweph::SE_EARTH),
     402, uint(sweph::SE_CHIRON),

       0        // eod
};

static const char qt_meta_stringdata_sweph[] = {
    "sweph\0flags\0planets\0SEFLG_JPLEPH\0"
    "SEFLG_SWIEPH\0SEFLG_MOSEPH\0SEFLG_HELCTR\0"
    "SEFLG_TRUEPOS\0SEFLG_J2000\0SEFLG_NONUT\0"
    "SEFLG_SPEED3\0SEFLG_SPEED\0SEFLG_NOGDEFL\0"
    "SEFLG_NOABERR\0SEFLG_EQUATORIAL\0SEFLG_XYZ\0"
    "SEFLG_RADIANS\0SEFLG_BARYCTR\0SEFLG_TOPOCTR\0"
    "SEFLG_SIDEREAL\0SE_SUN\0SE_MOON\0SE_MERCURY\0"
    "SE_VENUS\0SE_MARS\0SE_JUPITER\0SE_SATURN\0"
    "SE_URANUS\0SE_NEPTUNE\0SE_PLUTO\0"
    "SE_MEAN_NODE\0SE_TRUE_NODE\0SE_MEAN_APOG\0"
    "SE_OSCU_APOG\0SE_EARTH\0SE_CHIRON\0"
};

void sweph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData sweph::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject sweph::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_sweph,
      qt_meta_data_sweph, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &sweph::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *sweph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *sweph::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sweph))
        return static_cast<void*>(const_cast< sweph*>(this));
    return QObject::qt_metacast(_clname);
}

int sweph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
