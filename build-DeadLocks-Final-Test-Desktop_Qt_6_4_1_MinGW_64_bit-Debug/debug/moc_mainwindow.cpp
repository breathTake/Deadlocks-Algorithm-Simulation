/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DeadLocks-Final-Test/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[4];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[21];
    char stringdata5[27];
    char stringdata6[30];
    char stringdata7[17];
    char stringdata8[8];
    char stringdata9[9];
    char stringdata10[6];
    char stringdata11[17];
    char stringdata12[34];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 3),  // "run"
        QT_MOC_LITERAL(15, 0),  // ""
        QT_MOC_LITERAL(16, 24),  // "update_occupation_matrix"
        QT_MOC_LITERAL(41, 20),  // "update_needed_matrix"
        QT_MOC_LITERAL(62, 26),  // "update_resource_occupation"
        QT_MOC_LITERAL(89, 29),  // "updateStillNeededRessources_R"
        QT_MOC_LITERAL(119, 16),  // "reserveResources"
        QT_MOC_LITERAL(136, 7),  // "process"
        QT_MOC_LITERAL(144, 8),  // "resource"
        QT_MOC_LITERAL(153, 5),  // "count"
        QT_MOC_LITERAL(159, 16),  // "releaseResources"
        QT_MOC_LITERAL(176, 33)   // "on_button_stop_simulation_cli..."
    },
    "MainWindow",
    "run",
    "",
    "update_occupation_matrix",
    "update_needed_matrix",
    "update_resource_occupation",
    "updateStillNeededRessources_R",
    "reserveResources",
    "process",
    "resource",
    "count",
    "releaseResources",
    "on_button_stop_simulation_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    3,   67,    2, 0x08,    6 /* Private */,
      11,    3,   74,    2, 0x08,   10 /* Private */,
      12,    0,   81,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'run'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_occupation_matrix'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_needed_matrix'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_resource_occupation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateStillNeededRessources_R'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reserveResources'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'releaseResources'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button_stop_simulation_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->run(); break;
        case 1: _t->update_occupation_matrix(); break;
        case 2: _t->update_needed_matrix(); break;
        case 3: _t->update_resource_occupation(); break;
        case 4: _t->updateStillNeededRessources_R(); break;
        case 5: _t->reserveResources((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 6: _t->releaseResources((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->on_button_stop_simulation_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
