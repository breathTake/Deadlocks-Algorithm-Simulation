/****************************************************************************
** Meta object code from reading C++ file 'preemptionworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DeadLocks-Final-Test/Algorithms/preemptionworker.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preemptionworker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_PreemptionWorker_t {
    uint offsetsAndSizes[42];
    char stringdata0[17];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[9];
    char stringdata5[6];
    char stringdata6[16];
    char stringdata7[19];
    char stringdata8[10];
    char stringdata9[13];
    char stringdata10[10];
    char stringdata11[20];
    char stringdata12[11];
    char stringdata13[14];
    char stringdata14[9];
    char stringdata15[14];
    char stringdata16[16];
    char stringdata17[22];
    char stringdata18[17];
    char stringdata19[22];
    char stringdata20[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_PreemptionWorker_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_PreemptionWorker_t qt_meta_stringdata_PreemptionWorker = {
    {
        QT_MOC_LITERAL(0, 16),  // "PreemptionWorker"
        QT_MOC_LITERAL(17, 16),  // "resourceReleased"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 9),  // "processID"
        QT_MOC_LITERAL(45, 8),  // "resource"
        QT_MOC_LITERAL(54, 5),  // "count"
        QT_MOC_LITERAL(60, 15),  // "notProcessedYet"
        QT_MOC_LITERAL(76, 18),  // "reservationStarted"
        QT_MOC_LITERAL(95, 9),  // "processId"
        QT_MOC_LITERAL(105, 12),  // "nextResource"
        QT_MOC_LITERAL(118, 9),  // "nextCount"
        QT_MOC_LITERAL(128, 19),  // "reservationFinished"
        QT_MOC_LITERAL(148, 10),  // "initTimers"
        QT_MOC_LITERAL(159, 13),  // "revokePrinter"
        QT_MOC_LITERAL(173, 8),  // "revokeCD"
        QT_MOC_LITERAL(182, 13),  // "revokePlotter"
        QT_MOC_LITERAL(196, 15),  // "revokeTapeDrive"
        QT_MOC_LITERAL(212, 21),  // "getTimerPrinterStatus"
        QT_MOC_LITERAL(234, 16),  // "getTimerCDStatus"
        QT_MOC_LITERAL(251, 21),  // "getTimerPlotterStatus"
        QT_MOC_LITERAL(273, 23)   // "getTimerTapeDriveStatus"
    },
    "PreemptionWorker",
    "resourceReleased",
    "",
    "processID",
    "resource",
    "count",
    "notProcessedYet",
    "reservationStarted",
    "processId",
    "nextResource",
    "nextCount",
    "reservationFinished",
    "initTimers",
    "revokePrinter",
    "revokeCD",
    "revokePlotter",
    "revokeTapeDrive",
    "getTimerPrinterStatus",
    "getTimerCDStatus",
    "getTimerPlotterStatus",
    "getTimerTapeDriveStatus"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_PreemptionWorker[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   86,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    3,   95,    2, 0x0a,    6 /* Public */,
      11,    4,  102,    2, 0x0a,   10 /* Public */,
      12,    0,  111,    2, 0x0a,   15 /* Public */,
      13,    0,  112,    2, 0x0a,   16 /* Public */,
      14,    0,  113,    2, 0x0a,   17 /* Public */,
      15,    0,  114,    2, 0x0a,   18 /* Public */,
      16,    0,  115,    2, 0x0a,   19 /* Public */,
      17,    0,  116,    2, 0x0a,   20 /* Public */,
      18,    0,  117,    2, 0x0a,   21 /* Public */,
      19,    0,  118,    2, 0x0a,   22 /* Public */,
      20,    0,  119,    2, 0x0a,   23 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    8,    9,   10,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

Q_CONSTINIT const QMetaObject PreemptionWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PreemptionWorker.offsetsAndSizes,
    qt_meta_data_PreemptionWorker,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_PreemptionWorker_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PreemptionWorker, std::true_type>,
        // method 'resourceReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'reservationStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'reservationFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'initTimers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'revokePrinter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'revokeCD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'revokePlotter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'revokeTapeDrive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getTimerPrinterStatus'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getTimerCDStatus'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getTimerPlotterStatus'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getTimerTapeDriveStatus'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void PreemptionWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreemptionWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resourceReleased((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 1: _t->reservationStarted((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->reservationFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 3: _t->initTimers(); break;
        case 4: _t->revokePrinter(); break;
        case 5: _t->revokeCD(); break;
        case 6: _t->revokePlotter(); break;
        case 7: _t->revokeTapeDrive(); break;
        case 8: { bool _r = _t->getTimerPrinterStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->getTimerCDStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->getTimerPlotterStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->getTimerTapeDriveStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PreemptionWorker::*)(int , int , int , bool );
            if (_t _q_method = &PreemptionWorker::resourceReleased; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *PreemptionWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreemptionWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PreemptionWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PreemptionWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void PreemptionWorker::resourceReleased(int _t1, int _t2, int _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
