/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VentanaPrincipal_t {
    QByteArrayData data[14];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VentanaPrincipal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VentanaPrincipal_t qt_meta_stringdata_VentanaPrincipal = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VentanaPrincipal"
QT_MOC_LITERAL(1, 17, 9), // "slotAbrir"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "slotGuardar"
QT_MOC_LITERAL(4, 40, 25), // "slotActualizarBarraEstado"
QT_MOC_LITERAL(5, 66, 9), // "slotNuevo"
QT_MOC_LITERAL(6, 76, 10), // "closeEvent"
QT_MOC_LITERAL(7, 87, 12), // "QCloseEvent*"
QT_MOC_LITERAL(8, 100, 5), // "event"
QT_MOC_LITERAL(9, 106, 24), // "slotAbrirFicheroReciente"
QT_MOC_LITERAL(10, 131, 10), // "slotBuscar"
QT_MOC_LITERAL(11, 142, 12), // "slotFindNext"
QT_MOC_LITERAL(12, 155, 19), // "Qt::CaseSensitivity"
QT_MOC_LITERAL(13, 175, 16) // "slotFindPrevious"

    },
    "VentanaPrincipal\0slotAbrir\0\0slotGuardar\0"
    "slotActualizarBarraEstado\0slotNuevo\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "slotAbrirFicheroReciente\0slotBuscar\0"
    "slotFindNext\0Qt::CaseSensitivity\0"
    "slotFindPrevious"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    2,   68,    2, 0x08 /* Private */,
      13,    2,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 12,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 12,    2,    2,

       0        // eod
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VentanaPrincipal *_t = static_cast<VentanaPrincipal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotAbrir(); break;
        case 1: _t->slotGuardar(); break;
        case 2: _t->slotActualizarBarraEstado(); break;
        case 3: _t->slotNuevo(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 5: _t->slotAbrirFicheroReciente(); break;
        case 6: _t->slotBuscar(); break;
        case 7: _t->slotFindNext((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 8: _t->slotFindPrevious((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject VentanaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VentanaPrincipal.data,
      qt_meta_data_VentanaPrincipal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal.stringdata0))
        return static_cast<void*>(const_cast< VentanaPrincipal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
