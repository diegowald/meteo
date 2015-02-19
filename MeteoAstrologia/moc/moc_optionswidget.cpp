/****************************************************************************
** Meta object code from reading C++ file 'optionswidget.h'
**
** Created: Sun 19. May 01:44:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../optionswidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_optionsWidget[] = {

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
      15,   14,   14,   14, 0x0a,
      24,   14,   14,   14, 0x0a,
      39,   14,   14,   14, 0x0a,
      54,   14,   14,   14, 0x0a,
      81,   76,   68,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_optionsWidget[] = {
    "optionsWidget\0\0accept()\0searchForSFD()\0"
    "searchForRBD()\0searchForSF()\0QString\0"
    "kind\0searchForFile(QString)\0"
};

void optionsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        optionsWidget *_t = static_cast<optionsWidget *>(_o);
        switch (_id) {
        case 0: _t->accept(); break;
        case 1: _t->searchForSFD(); break;
        case 2: _t->searchForRBD(); break;
        case 3: _t->searchForSF(); break;
        case 4: { QString _r = _t->searchForFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData optionsWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject optionsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_optionsWidget,
      qt_meta_data_optionsWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &optionsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *optionsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *optionsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_optionsWidget))
        return static_cast<void*>(const_cast< optionsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int optionsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
