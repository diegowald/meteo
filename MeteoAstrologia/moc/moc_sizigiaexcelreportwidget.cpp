/****************************************************************************
** Meta object code from reading C++ file 'sizigiaexcelreportwidget.h'
**
** Created: Sun 19. May 01:44:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sizigiaexcelreportwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sizigiaexcelreportwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_sizigiaExcelReportWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x0a,
      33,   25,   25,   25, 0x0a,
      49,   25,   25,   25, 0x0a,
      64,   58,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_sizigiaExcelReportWidget[] = {
    "sizigiaExcelReportWidget\0\0test()\0"
    "exportToExcel()\0filter()\0value\0"
    "typeChange(QString)\0"
};

void sizigiaExcelReportWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        sizigiaExcelReportWidget *_t = static_cast<sizigiaExcelReportWidget *>(_o);
        switch (_id) {
        case 0: _t->test(); break;
        case 1: _t->exportToExcel(); break;
        case 2: _t->filter(); break;
        case 3: _t->typeChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData sizigiaExcelReportWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject sizigiaExcelReportWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_sizigiaExcelReportWidget,
      qt_meta_data_sizigiaExcelReportWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &sizigiaExcelReportWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *sizigiaExcelReportWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *sizigiaExcelReportWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sizigiaExcelReportWidget))
        return static_cast<void*>(const_cast< sizigiaExcelReportWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int sizigiaExcelReportWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
