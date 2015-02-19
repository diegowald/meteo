/****************************************************************************
** Meta object code from reading C++ file 'specialrowtablemodel.h'
**
** Created: Sun 19. May 01:45:01 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../specialrowtablemodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'specialrowtablemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_specialRowTableModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   22,   21,   21, 0x0a,
      49,   47,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_specialRowTableModel[] = {
    "specialRowTableModel\0\0v\0setDateTime(QDateTime)\0"
    "t\0setType(modelType)\0"
};

void specialRowTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        specialRowTableModel *_t = static_cast<specialRowTableModel *>(_o);
        switch (_id) {
        case 0: _t->setDateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 1: _t->setType((*reinterpret_cast< modelType(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData specialRowTableModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject specialRowTableModel::staticMetaObject = {
    { &QSqlTableModel::staticMetaObject, qt_meta_stringdata_specialRowTableModel,
      qt_meta_data_specialRowTableModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &specialRowTableModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *specialRowTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *specialRowTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_specialRowTableModel))
        return static_cast<void*>(const_cast< specialRowTableModel*>(this));
    return QSqlTableModel::qt_metacast(_clname);
}

int specialRowTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
