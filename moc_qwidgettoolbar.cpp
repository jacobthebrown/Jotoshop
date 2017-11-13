/****************************************************************************
** Meta object code from reading C++ file 'qwidgettoolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Widgets/qwidgettoolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwidgettoolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QWidgetToolbar_t {
    QByteArrayData data[13];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QWidgetToolbar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QWidgetToolbar_t qt_meta_stringdata_QWidgetToolbar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QWidgetToolbar"
QT_MOC_LITERAL(1, 15, 15), // "SendCurrentTool"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "BaseToolClass*"
QT_MOC_LITERAL(4, 47, 24), // "RegisterPaintBrushButton"
QT_MOC_LITERAL(5, 72, 24), // "RegisterBroadBrushButton"
QT_MOC_LITERAL(6, 97, 21), // "RegisterDropperButton"
QT_MOC_LITERAL(7, 119, 20), // "RegisterEraserButton"
QT_MOC_LITERAL(8, 140, 15), // "UpdateToolWidth"
QT_MOC_LITERAL(9, 156, 23), // "UpdatePrimaryColorImage"
QT_MOC_LITERAL(10, 180, 25), // "UpdateSecondaryColorImage"
QT_MOC_LITERAL(11, 206, 20), // "CurrentToolRequested"
QT_MOC_LITERAL(12, 227, 19) // "UpdateDropperReturn"

    },
    "QWidgetToolbar\0SendCurrentTool\0\0"
    "BaseToolClass*\0RegisterPaintBrushButton\0"
    "RegisterBroadBrushButton\0RegisterDropperButton\0"
    "RegisterEraserButton\0UpdateToolWidth\0"
    "UpdatePrimaryColorImage\0"
    "UpdateSecondaryColorImage\0"
    "CurrentToolRequested\0UpdateDropperReturn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QWidgetToolbar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   67,    2, 0x0a /* Public */,
       5,    0,   68,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    1,   71,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    2,

       0        // eod
};

void QWidgetToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWidgetToolbar *_t = static_cast<QWidgetToolbar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendCurrentTool((*reinterpret_cast< BaseToolClass*(*)>(_a[1]))); break;
        case 1: _t->RegisterPaintBrushButton(); break;
        case 2: _t->RegisterBroadBrushButton(); break;
        case 3: _t->RegisterDropperButton(); break;
        case 4: _t->RegisterEraserButton(); break;
        case 5: _t->UpdateToolWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->UpdatePrimaryColorImage(); break;
        case 7: _t->UpdateSecondaryColorImage(); break;
        case 8: _t->CurrentToolRequested(); break;
        case 9: _t->UpdateDropperReturn((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QWidgetToolbar::*_t)(BaseToolClass * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWidgetToolbar::SendCurrentTool)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QWidgetToolbar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QWidgetToolbar.data,
      qt_meta_data_QWidgetToolbar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QWidgetToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWidgetToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QWidgetToolbar.stringdata0))
        return static_cast<void*>(const_cast< QWidgetToolbar*>(this));
    return QWidget::qt_metacast(_clname);
}

int QWidgetToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QWidgetToolbar::SendCurrentTool(BaseToolClass * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
