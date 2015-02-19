/****************************************************************************
** Meta object code from reading C++ file 'grabdatawidget.h'
**
** Created: Sun 19. May 01:44:21 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../grabdatawidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grabdatawidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_grabDataWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      28,   15,   15,   15, 0x0a,
      39,   15,   15,   15, 0x0a,
      57,   15,   15,   15, 0x0a,
      77,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_grabDataWidget[] = {
    "grabDataWidget\0\0saveData2()\0saveData()\0"
    "addSatelmecData()\0addStarFisherData()\0"
    "calculateAstro()\0"
};

void grabDataWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        grabDataWidget *_t = static_cast<grabDataWidget *>(_o);
        switch (_id) {
        case 0: _t->saveData2(); break;
        case 1: _t->saveData(); break;
        case 2: _t->addSatelmecData(); break;
        case 3: _t->addStarFisherData(); break;
        case 4: _t->calculateAstro(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData grabDataWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject grabDataWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_grabDataWidget,
      qt_meta_data_grabDataWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &grabDataWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *grabDataWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *grabDataWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_grabDataWidget))
        return static_cast<void*>(const_cast< grabDataWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int grabDataWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
