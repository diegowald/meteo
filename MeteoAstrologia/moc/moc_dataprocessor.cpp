/****************************************************************************
** Meta object code from reading C++ file 'dataprocessor.h'
**
** Created: Sun 19. May 01:44:26 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dataprocessor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dataProcessor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       1,  234, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      23,   14,   14,   14, 0x05,
      38,   14,   14,   14, 0x05,
      54,   14,   14,   14, 0x05,
      67,   63,   14,   14, 0x05,
      90,   84,   14,   14, 0x05,
     106,   84,   14,   14, 0x05,
     132,  122,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     153,   84,   14,   14, 0x0a,
     170,   84,   14,   14, 0x0a,
     193,   84,   14,   14, 0x0a,
     214,   84,   14,   14, 0x0a,
     232,   84,   14,   14, 0x0a,
     256,   84,   14,   14, 0x0a,
     278,   84,   14,   14, 0x0a,
     297,   84,   14,   14, 0x0a,
     322,   84,   14,   14, 0x0a,
     345,   84,   14,   14, 0x0a,
     361,   84,   14,   14, 0x0a,
     383,   84,   14,   14, 0x0a,
     403,   84,   14,   14, 0x0a,
     422,   84,   14,   14, 0x0a,
     447,   84,   14,   14, 0x0a,
     470,   84,   14,   14, 0x0a,
     485,   84,   14,   14, 0x0a,
     506,   84,   14,   14, 0x0a,
     533,  525,   14,   14, 0x0a,
     556,  525,   14,   14, 0x0a,
     578,  525,   14,   14, 0x0a,
     598,  525,   14,   14, 0x0a,
     622,  525,   14,   14, 0x0a,
     646,  525,   14,   14, 0x0a,
     667,   14,   14,   14, 0x0a,
     684,   14,   14,   14, 0x0a,
     701,   14,   14,   14, 0x0a,
     717,   14,   14,   14, 0x0a,
     736,   14,   14,   14, 0x0a,
     755,   14,   14,   14, 0x0a,
     770,   14,   14,   14, 0x0a,
     787,   14,   14,   14, 0x0a,
     804,  802,   14,   14, 0x0a,
     823,  802,   14,   14, 0x0a,
     843,   14,   14,   14, 0x0a,
     860,   14,   14,   14, 0x0a,

 // enums: name, flags, count, data
     879, 0x0,    6,  238,

 // enum data: key, value
     897, uint(dataProcessor::Aspects),
     905, uint(dataProcessor::Weathers),
     914, uint(dataProcessor::Houses),
     921, uint(dataProcessor::Positions),
     931, uint(dataProcessor::Sings),
     937, uint(dataProcessor::Quadrants),

       0        // eod
};

static const char qt_meta_stringdata_dataProcessor[] = {
    "dataProcessor\0\0begin()\0endFirstPass()\0"
    "endSecondPass()\0finish()\0msg\0"
    "message(QString)\0value\0setMaximun(int)\0"
    "setMinimun(int)\0value,max\0"
    "setProgress(int,int)\0setAspects(bool)\0"
    "setStrongAspects(bool)\0setWeakAspects(bool)\0"
    "setWeathers(bool)\0setStrongWeathers(bool)\0"
    "setWeakWeathers(bool)\0setPositions(bool)\0"
    "setStrongPositions(bool)\0"
    "setWeakPositions(bool)\0setHouses(bool)\0"
    "setStrongHouses(bool)\0setWeakHouses(bool)\0"
    "setQuadrants(bool)\0setStrongQuadrants(bool)\0"
    "setWeakQuadrants(bool)\0setSigns(bool)\0"
    "setStrongSigns(bool)\0setWeakSigns(bool)\0"
    "percent\0setWeatherPercent(int)\0"
    "setAspectPercent(int)\0setSignPercent(int)\0"
    "setPositionPercent(int)\0setQuadrantPercent(int)\0"
    "setHousePercent(int)\0processAspects()\0"
    "processWeather()\0processHouses()\0"
    "processPositions()\0processQuadrants()\0"
    "processSings()\0processResults()\0"
    "startProcess()\0v\0setUseNormal(bool)\0"
    "setUseSisigia(bool)\0setNOAAWeather()\0"
    "setAstralWeather()\0processTypeReturn\0"
    "Aspects\0Weathers\0Houses\0Positions\0"
    "Sings\0Quadrants\0"
};

void dataProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dataProcessor *_t = static_cast<dataProcessor *>(_o);
        switch (_id) {
        case 0: _t->begin(); break;
        case 1: _t->endFirstPass(); break;
        case 2: _t->endSecondPass(); break;
        case 3: _t->finish(); break;
        case 4: _t->message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setMaximun((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setMinimun((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->setAspects((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setStrongAspects((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setWeakAspects((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->setWeathers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setStrongWeathers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->setWeakWeathers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setPositions((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->setStrongPositions((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->setWeakPositions((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->setHouses((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->setStrongHouses((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->setWeakHouses((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->setQuadrants((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->setStrongQuadrants((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->setWeakQuadrants((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->setSigns((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->setStrongSigns((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->setWeakSigns((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->setWeatherPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->setAspectPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->setSignPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->setPositionPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->setQuadrantPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->setHousePercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->processAspects(); break;
        case 33: _t->processWeather(); break;
        case 34: _t->processHouses(); break;
        case 35: _t->processPositions(); break;
        case 36: _t->processQuadrants(); break;
        case 37: _t->processSings(); break;
        case 38: _t->processResults(); break;
        case 39: _t->startProcess(); break;
        case 40: _t->setUseNormal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->setUseSisigia((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->setNOAAWeather(); break;
        case 43: _t->setAstralWeather(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dataProcessor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dataProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_dataProcessor,
      qt_meta_data_dataProcessor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dataProcessor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dataProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dataProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dataProcessor))
        return static_cast<void*>(const_cast< dataProcessor*>(this));
    return QObject::qt_metacast(_clname);
}

int dataProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void dataProcessor::begin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void dataProcessor::endFirstPass()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void dataProcessor::endSecondPass()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void dataProcessor::finish()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void dataProcessor::message(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void dataProcessor::setMaximun(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void dataProcessor::setMinimun(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void dataProcessor::setProgress(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
