/****************************************************************************
** Meta object code from reading C++ file 'processbyaspectwidget.h'
**
** Created: Sun 19. May 01:44:48 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processbyaspectwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processbyaspectwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_processByAspectWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      29,   22,   22,   22, 0x0a,
      39,   35,   22,   22, 0x0a,
      80,   22,   22,   22, 0x0a,
      97,   22,   22,   22, 0x0a,
     113,   22,   22,   22, 0x0a,
     126,  122,   22,   22, 0x0a,
     143,  122,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_processByAspectWidget[] = {
    "processByAspectWidget\0\0add()\0del()\0"
    "asp\0aspectsAdded(metAstro::aspectParameter*)\0"
    "refreshAspects()\0refreshResult()\0"
    "doCalc()\0val\0daysMenu(QPoint)\0"
    "noaaMenu(QPoint)\0"
};

void processByAspectWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        processByAspectWidget *_t = static_cast<processByAspectWidget *>(_o);
        switch (_id) {
        case 0: _t->add(); break;
        case 1: _t->del(); break;
        case 2: _t->aspectsAdded((*reinterpret_cast< metAstro::aspectParameter*(*)>(_a[1]))); break;
        case 3: _t->refreshAspects(); break;
        case 4: _t->refreshResult(); break;
        case 5: _t->doCalc(); break;
        case 6: _t->daysMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->noaaMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData processByAspectWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject processByAspectWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_processByAspectWidget,
      qt_meta_data_processByAspectWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &processByAspectWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *processByAspectWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *processByAspectWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_processByAspectWidget))
        return static_cast<void*>(const_cast< processByAspectWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int processByAspectWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
