/****************************************************************************
** Meta object code from reading C++ file 'qwidgetanimationstrip.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Widgets/qwidgetanimationstrip.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwidgetanimationstrip.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QWidgetAnimationStrip_t {
    QByteArrayData data[10];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QWidgetAnimationStrip_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QWidgetAnimationStrip_t qt_meta_stringdata_QWidgetAnimationStrip = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QWidgetAnimationStrip"
QT_MOC_LITERAL(1, 22, 17), // "sendClickedCanvas"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 58, 9), // "addQImage"
QT_MOC_LITERAL(5, 68, 3), // "pix"
QT_MOC_LITERAL(6, 72, 8), // "framePos"
QT_MOC_LITERAL(7, 81, 13), // "canvasClicked"
QT_MOC_LITERAL(8, 95, 12), // "refreshImage"
QT_MOC_LITERAL(9, 108, 7) // "QImage*"

    },
    "QWidgetAnimationStrip\0sendClickedCanvas\0"
    "\0QListWidgetItem*\0addQImage\0pix\0"
    "framePos\0canvasClicked\0refreshImage\0"
    "QImage*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QWidgetAnimationStrip[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   37,    2, 0x0a /* Public */,
       7,    1,   42,    2, 0x0a /* Public */,
       8,    2,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPixmap, QMetaType::Int,    5,    6,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,

       0        // eod
};

void QWidgetAnimationStrip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWidgetAnimationStrip *_t = static_cast<QWidgetAnimationStrip *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendClickedCanvas((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->addQImage((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->canvasClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->refreshImage((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QWidgetAnimationStrip::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWidgetAnimationStrip::sendClickedCanvas)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QWidgetAnimationStrip::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QWidgetAnimationStrip.data,
      qt_meta_data_QWidgetAnimationStrip,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QWidgetAnimationStrip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWidgetAnimationStrip::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QWidgetAnimationStrip.stringdata0))
        return static_cast<void*>(const_cast< QWidgetAnimationStrip*>(this));
    return QWidget::qt_metacast(_clname);
}

int QWidgetAnimationStrip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QWidgetAnimationStrip::sendClickedCanvas(QListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
