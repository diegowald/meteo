/****************************************************************************
** Meta object code from reading C++ file 'freezetablewidget.h'
**
** Created: Sun 19. May 01:44:59 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../freezetablewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'freezetablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FreezeTableWidget[] = {

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
      67,   45,   18,   18, 0x08,
      99,   45,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FreezeTableWidget[] = {
    "FreezeTableWidget\0\0resizeColumnsToContents()\0"
    "logicalIndex,,newSize\0"
    "updateSectionWidth(int,int,int)\0"
    "updateSectionHeight(int,int,int)\0"
};

void FreezeTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FreezeTableWidget *_t = static_cast<FreezeTableWidget *>(_o);
        switch (_id) {
        case 0: _t->resizeColumnsToContents(); break;
        case 1: _t->updateSectionWidth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->updateSectionHeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FreezeTableWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FreezeTableWidget::staticMetaObject = {
    { &QTableView::staticMetaObject, qt_meta_stringdata_FreezeTableWidget,
      qt_meta_data_FreezeTableWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FreezeTableWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FreezeTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FreezeTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FreezeTableWidget))
        return static_cast<void*>(const_cast< FreezeTableWidget*>(this));
    return QTableView::qt_metacast(_clname);
}

int FreezeTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
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
