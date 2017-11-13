/****************************************************************************
** Meta object code from reading C++ file 'qwidgetcanvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Widgets/qwidgetcanvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwidgetcanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QWidgetCanvas_t {
    QByteArrayData data[14];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QWidgetCanvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QWidgetCanvas_t qt_meta_stringdata_QWidgetCanvas = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QWidgetCanvas"
QT_MOC_LITERAL(1, 14, 10), // "sendImages"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "QVector<QImage*>"
QT_MOC_LITERAL(4, 43, 11), // "ImageUpdate"
QT_MOC_LITERAL(5, 55, 7), // "QImage*"
QT_MOC_LITERAL(6, 63, 18), // "RequestCurrentTool"
QT_MOC_LITERAL(7, 82, 9), // "addCanvas"
QT_MOC_LITERAL(8, 92, 4), // "load"
QT_MOC_LITERAL(9, 97, 11), // "RecieveTool"
QT_MOC_LITERAL(10, 109, 14), // "BaseToolClass*"
QT_MOC_LITERAL(11, 124, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(12, 142, 12), // "QMouseEvent*"
QT_MOC_LITERAL(13, 155, 5) // "event"

    },
    "QWidgetCanvas\0sendImages\0\0QVector<QImage*>\0"
    "ImageUpdate\0QImage*\0RequestCurrentTool\0"
    "addCanvas\0load\0RecieveTool\0BaseToolClass*\0"
    "mouseReleaseEvent\0QMouseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QWidgetCanvas[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,
       6,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   58,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void QWidgetCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWidgetCanvas *_t = static_cast<QWidgetCanvas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendImages((*reinterpret_cast< QVector<QImage*>(*)>(_a[1]))); break;
        case 1: _t->ImageUpdate((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->RequestCurrentTool(); break;
        case 3: _t->addCanvas(); break;
        case 4: _t->load((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 5: _t->RecieveTool((*reinterpret_cast< BaseToolClass*(*)>(_a[1]))); break;
        case 6: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QWidgetCanvas::*_t)(QVector<QImage*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWidgetCanvas::sendImages)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QWidgetCanvas::*_t)(QImage * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWidgetCanvas::ImageUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QWidgetCanvas::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWidgetCanvas::RequestCurrentTool)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QWidgetCanvas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QWidgetCanvas.data,
      qt_meta_data_QWidgetCanvas,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QWidgetCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWidgetCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QWidgetCanvas.stringdata0))
        return static_cast<void*>(const_cast< QWidgetCanvas*>(this));
    return QWidget::qt_metacast(_clname);
}

int QWidgetCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QWidgetCanvas::sendImages(QVector<QImage*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QWidgetCanvas::ImageUpdate(QImage * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QWidgetCanvas::RequestCurrentTool()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
