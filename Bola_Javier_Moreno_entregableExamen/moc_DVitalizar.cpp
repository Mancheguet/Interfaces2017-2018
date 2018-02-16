/****************************************************************************
** Meta object code from reading C++ file 'DVitalizar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DVitalizar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DVitalizar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DVitalizar_t {
    QByteArrayData data[9];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DVitalizar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DVitalizar_t qt_meta_stringdata_DVitalizar = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DVitalizar"
QT_MOC_LITERAL(1, 11, 27), // "inicializarWidgetsVitalizar"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 14), // "QVector<Bola*>"
QT_MOC_LITERAL(4, 55, 5), // "bolas"
QT_MOC_LITERAL(5, 61, 13), // "slotSiguiente"
QT_MOC_LITERAL(6, 75, 12), // "slotAnterior"
QT_MOC_LITERAL(7, 88, 10), // "slotBuscar"
QT_MOC_LITERAL(8, 99, 9) // "inciarUna"

    },
    "DVitalizar\0inicializarWidgetsVitalizar\0"
    "\0QVector<Bola*>\0bolas\0slotSiguiente\0"
    "slotAnterior\0slotBuscar\0inciarUna"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DVitalizar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,
       7,    0,   44,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DVitalizar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DVitalizar *_t = static_cast<DVitalizar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inicializarWidgetsVitalizar((*reinterpret_cast< QVector<Bola*>(*)>(_a[1]))); break;
        case 1: _t->slotSiguiente(); break;
        case 2: _t->slotAnterior(); break;
        case 3: _t->slotBuscar(); break;
        case 4: _t->inciarUna(); break;
        default: ;
        }
    }
}

const QMetaObject DVitalizar::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DVitalizar.data,
      qt_meta_data_DVitalizar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DVitalizar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DVitalizar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DVitalizar.stringdata0))
        return static_cast<void*>(const_cast< DVitalizar*>(this));
    if (!strcmp(_clname, "Ui::DVitalizar"))
        return static_cast< Ui::DVitalizar*>(const_cast< DVitalizar*>(this));
    return QDialog::qt_metacast(_clname);
}

int DVitalizar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
