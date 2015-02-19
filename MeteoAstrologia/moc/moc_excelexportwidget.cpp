/****************************************************************************
** Meta object code from reading C++ file 'excelexportwidget.h'
**
** Created: Sun 19. May 01:44:58 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../excelexportwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'excelexportwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_excelExportWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x0a,
      48,   19,   18,   18, 0x0a,
      64,   18,   18,   18, 0x0a,
      70,   18,   18,   18, 0x0a,
      76,   18,   18,   18, 0x0a,
      84,   18,   18,   18, 0x0a,
      93,   18,   18,   18, 0x0a,
     107,   18,   18,   18, 0x0a,
     116,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_excelExportWidget[] = {
    "excelExportWidget\0\0date\0addDateTime(QDateTime*)\0"
    "addDate(QDate&)\0del()\0add()\0added()\0"
    "cancel()\0refreshList()\0filter()\0"
    "excelExport()\0"
};

void excelExportWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        excelExportWidget *_t = static_cast<excelExportWidget *>(_o);
        switch (_id) {
        case 0: _t->addDateTime((*reinterpret_cast< QDateTime*(*)>(_a[1]))); break;
        case 1: _t->addDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 2: _t->del(); break;
        case 3: _t->add(); break;
        case 4: _t->added(); break;
        case 5: _t->cancel(); break;
        case 6: _t->refreshList(); break;
        case 7: _t->filter(); break;
        case 8: _t->excelExport(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData excelExportWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject excelExportWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_excelExportWidget,
      qt_meta_data_excelExportWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &excelExportWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *excelExportWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *excelExportWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_excelExportWidget))
        return static_cast<void*>(const_cast< excelExportWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int excelExportWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
