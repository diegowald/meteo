/****************************************************************************
** Meta object code from reading C++ file 'processbydignitywidget.h'
**
** Created: Sun 19. May 01:44:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processbydignitywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processbydignitywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_processByDignityWidget[] = {

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
      24,   23,   23,   23, 0x0a,
      33,   23,   23,   23, 0x0a,
      53,   47,   23,   23, 0x0a,
      78,   23,   23,   23, 0x0a,
      84,   23,   23,   23, 0x0a,
      90,   23,   23,   23, 0x0a,
     106,  100,   23,   23, 0x0a,
     145,  142,   23,   23, 0x0a,
     163,  142,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_processByDignityWidget[] = {
    "processByDignityWidget\0\0doCalc()\0"
    "calcDignity()\0value\0dateTypeChanged(QString)\0"
    "add()\0del()\0refresh()\0param\0"
    "addDignity(metAstro::dignityParam&)\0"
    "pt\0dailyMenu(QPoint)\0noaaMenu(QPoint)\0"
};

void processByDignityWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        processByDignityWidget *_t = static_cast<processByDignityWidget *>(_o);
        switch (_id) {
        case 0: _t->doCalc(); break;
        case 1: _t->calcDignity(); break;
        case 2: _t->dateTypeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->add(); break;
        case 4: _t->del(); break;
        case 5: _t->refresh(); break;
        case 6: _t->addDignity((*reinterpret_cast< metAstro::dignityParam(*)>(_a[1]))); break;
        case 7: _t->dailyMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 8: _t->noaaMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData processByDignityWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject processByDignityWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_processByDignityWidget,
      qt_meta_data_processByDignityWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &processByDignityWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *processByDignityWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *processByDignityWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_processByDignityWidget))
        return static_cast<void*>(const_cast< processByDignityWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int processByDignityWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
