/****************************************************************************
** Meta object code from reading C++ file 'clickedcolorresponse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Models/clickedcolorresponse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clickedcolorresponse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_clickedColorResponse_t {
    QByteArrayData data[3];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_clickedColorResponse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_clickedColorResponse_t qt_meta_stringdata_clickedColorResponse = {
    {
QT_MOC_LITERAL(0, 0, 20), // "clickedColorResponse"
QT_MOC_LITERAL(1, 21, 17), // "sendColorSelected"
QT_MOC_LITERAL(2, 39, 0) // ""

    },
    "clickedColorResponse\0sendColorSelected\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_clickedColorResponse[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,

       0        // eod
};

void clickedColorResponse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        clickedColorResponse *_t = static_cast<clickedColorResponse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendColorSelected((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (clickedColorResponse::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clickedColorResponse::sendColorSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject clickedColorResponse::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_clickedColorResponse.data,
      qt_meta_data_clickedColorResponse,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *clickedColorResponse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *clickedColorResponse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_clickedColorResponse.stringdata0))
        return static_cast<void*>(const_cast< clickedColorResponse*>(this));
    return QLabel::qt_metacast(_clname);
}

int clickedColorResponse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void clickedColorResponse::sendColorSelected(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
