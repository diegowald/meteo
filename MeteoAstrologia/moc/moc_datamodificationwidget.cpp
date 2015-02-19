/****************************************************************************
** Meta object code from reading C++ file 'datamodificationwidget.h'
**
** Created: Sun 19. May 01:44:28 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../datamodificationwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datamodificationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dataModificationWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x0a,
      35,   23,   23,   23, 0x0a,
      44,   23,   23,   23, 0x0a,
      54,   23,   23,   23, 0x0a,
      67,   23,   23,   23, 0x0a,
      78,   23,   23,   23, 0x0a,
      89,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_dataModificationWidget[] = {
    "dataModificationWidget\0\0accepted()\0"
    "closed()\0refresh()\0changeType()\0"
    "loadData()\0saveData()\0eraseData()\0"
};

void dataModificationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dataModificationWidget *_t = static_cast<dataModificationWidget *>(_o);
        switch (_id) {
        case 0: _t->accepted(); break;
        case 1: _t->closed(); break;
        case 2: _t->refresh(); break;
        case 3: _t->changeType(); break;
        case 4: _t->loadData(); break;
        case 5: _t->saveData(); break;
        case 6: _t->eraseData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dataModificationWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dataModificationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dataModificationWidget,
      qt_meta_data_dataModificationWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dataModificationWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dataModificationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dataModificationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dataModificationWidget))
        return static_cast<void*>(const_cast< dataModificationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int dataModificationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
