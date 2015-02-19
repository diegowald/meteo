/****************************************************************************
** Meta object code from reading C++ file 'batchastrologicgrabdata.h'
**
** Created: Sun 19. May 01:44:40 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../batchastrologicgrabdata.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batchastrologicgrabdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_batchAstrologicGrabData[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x0a,
      38,   24,   24,   24, 0x0a,
      49,   24,   24,   24, 0x0a,
      56,   24,   24,   24, 0x0a,
      75,   24,   24,   24, 0x0a,
      91,   87,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_batchAstrologicGrabData[] = {
    "batchAstrologicGrabData\0\0loadFechas()\0"
    "saveData()\0next()\0clipboardChanged()\0"
    "parseData()\0msg\0log(QString)\0"
};

void batchAstrologicGrabData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        batchAstrologicGrabData *_t = static_cast<batchAstrologicGrabData *>(_o);
        switch (_id) {
        case 0: _t->loadFechas(); break;
        case 1: _t->saveData(); break;
        case 2: _t->next(); break;
        case 3: _t->clipboardChanged(); break;
        case 4: _t->parseData(); break;
        case 5: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData batchAstrologicGrabData::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject batchAstrologicGrabData::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_batchAstrologicGrabData,
      qt_meta_data_batchAstrologicGrabData, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &batchAstrologicGrabData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *batchAstrologicGrabData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *batchAstrologicGrabData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_batchAstrologicGrabData))
        return static_cast<void*>(const_cast< batchAstrologicGrabData*>(this));
    return QWidget::qt_metacast(_clname);
}

int batchAstrologicGrabData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
