/****************************************************************************
** Meta object code from reading C++ file 'fileloadwidget.h'
**
** Created: Sun 19. May 01:44:47 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fileloadwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileloadwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fileLoadWidget[] = {

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
      16,   15,   15,   15, 0x0a,
      27,   15,   15,   15, 0x0a,
      41,   15,   15,   15, 0x0a,
      56,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_fileLoadWidget[] = {
    "fileLoadWidget\0\0addFiles()\0removeFiles()\0"
    "processFiles()\0refresh()\0"
};

void fileLoadWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        fileLoadWidget *_t = static_cast<fileLoadWidget *>(_o);
        switch (_id) {
        case 0: _t->addFiles(); break;
        case 1: _t->removeFiles(); break;
        case 2: _t->processFiles(); break;
        case 3: _t->refresh(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData fileLoadWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject fileLoadWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fileLoadWidget,
      qt_meta_data_fileLoadWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fileLoadWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fileLoadWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fileLoadWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fileLoadWidget))
        return static_cast<void*>(const_cast< fileLoadWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int fileLoadWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
