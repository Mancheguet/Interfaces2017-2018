/****************************************************************************
** Meta object code from reading C++ file 'DControlBolas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DControlBolas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DControlBolas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DControlBolas_t {
    QByteArrayData data[3];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DControlBolas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DControlBolas_t qt_meta_stringdata_DControlBolas = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DControlBolas"
QT_MOC_LITERAL(1, 14, 17), // "slotCambioPestana"
QT_MOC_LITERAL(2, 32, 0) // ""

    },
    "DControlBolas\0slotCambioPestana\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DControlBolas[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void DControlBolas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DControlBolas *_t = static_cast<DControlBolas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotCambioPestana((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DControlBolas::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DControlBolas.data,
      qt_meta_data_DControlBolas,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DControlBolas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DControlBolas::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DControlBolas.stringdata0))
        return static_cast<void*>(const_cast< DControlBolas*>(this));
    if (!strcmp(_clname, "Ui::DControlBolas"))
        return static_cast< Ui::DControlBolas*>(const_cast< DControlBolas*>(this));
    return QDialog::qt_metacast(_clname);
}

int DControlBolas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
