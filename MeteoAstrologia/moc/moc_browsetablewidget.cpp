/****************************************************************************
** Meta object code from reading C++ file 'browsetablewidget.h'
**
** Created: Sun 19. May 01:44:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../browsetablewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'browsetablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_browseTableWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      38,   32,   18,   18, 0x0a,
      60,   55,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_browseTableWidget[] = {
    "browseTableWidget\0\0changeType()\0table\0"
    "changeTable(int)\0date\0fechaChange(QString)\0"
};

void browseTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        browseTableWidget *_t = static_cast<browseTableWidget *>(_o);
        switch (_id) {
        case 0: _t->changeType(); break;
        case 1: _t->changeTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->fechaChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData browseTableWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject browseTableWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_browseTableWidget,
      qt_meta_data_browseTableWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &browseTableWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *browseTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *browseTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_browseTableWidget))
        return static_cast<void*>(const_cast< browseTableWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int browseTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
