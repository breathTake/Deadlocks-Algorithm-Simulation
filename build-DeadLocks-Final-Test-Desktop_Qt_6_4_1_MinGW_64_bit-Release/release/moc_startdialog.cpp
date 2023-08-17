/****************************************************************************
** Meta object code from reading C++ file 'startdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DeadLocks-Final-Test/Dialogs/startdialog.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startdialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_StartDialog_t {
    uint offsetsAndSizes[20];
    char stringdata0[12];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[16];
    char stringdata5[19];
    char stringdata6[10];
    char stringdata7[17];
    char stringdata8[13];
    char stringdata9[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_StartDialog_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_StartDialog_t qt_meta_stringdata_StartDialog = {
    {
        QT_MOC_LITERAL(0, 11),  // "StartDialog"
        QT_MOC_LITERAL(12, 14),  // "countsFinished"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 4),  // "int*"
        QT_MOC_LITERAL(33, 15),  // "resourcesCounts"
        QT_MOC_LITERAL(49, 18),  // "algorithmsFinished"
        QT_MOC_LITERAL(68, 9),  // "algorithm"
        QT_MOC_LITERAL(78, 16),  // "getResourceCount"
        QT_MOC_LITERAL(95, 12),  // "getAlgorithm"
        QT_MOC_LITERAL(108, 27)   // "on_openGithubButton_clicked"
    },
    "StartDialog",
    "countsFinished",
    "",
    "int*",
    "resourcesCounts",
    "algorithmsFinished",
    "algorithm",
    "getResourceCount",
    "getAlgorithm",
    "on_openGithubButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_StartDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       5,    1,   47,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   50,    2, 0x0a,    5 /* Public */,
       8,    0,   51,    2, 0x0a,    6 /* Public */,
       9,    0,   52,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject StartDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_StartDialog.offsetsAndSizes,
    qt_meta_data_StartDialog,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_StartDialog_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<StartDialog, std::true_type>,
        // method 'countsFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int *, std::false_type>,
        // method 'algorithmsFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getResourceCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getAlgorithm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_openGithubButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void StartDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StartDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->countsFinished((*reinterpret_cast< std::add_pointer_t<int*>>(_a[1]))); break;
        case 1: _t->algorithmsFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->getResourceCount(); break;
        case 3: _t->getAlgorithm(); break;
        case 4: _t->on_openGithubButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StartDialog::*)(int * );
            if (_t _q_method = &StartDialog::countsFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StartDialog::*)(int );
            if (_t _q_method = &StartDialog::algorithmsFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *StartDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StartDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StartDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int StartDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void StartDialog::countsFinished(int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StartDialog::algorithmsFinished(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
