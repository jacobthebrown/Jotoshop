/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[440];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "addCanvas"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "addToStrip"
QT_MOC_LITERAL(4, 33, 7), // "QImage*"
QT_MOC_LITERAL(5, 41, 9), // "loadImage"
QT_MOC_LITERAL(6, 51, 11), // "exportToGIF"
QT_MOC_LITERAL(7, 63, 16), // "QVector<QImage*>"
QT_MOC_LITERAL(8, 80, 21), // "GetcurrentToolFromBar"
QT_MOC_LITERAL(9, 102, 21), // "SendCanvasCurrentTool"
QT_MOC_LITERAL(10, 124, 14), // "BaseToolClass*"
QT_MOC_LITERAL(11, 139, 17), // "sendPreviewImages"
QT_MOC_LITERAL(12, 157, 6), // "images"
QT_MOC_LITERAL(13, 164, 25), // "updatePreviewButtonStatus"
QT_MOC_LITERAL(14, 190, 8), // "isActive"
QT_MOC_LITERAL(15, 199, 19), // "onCanvasIconClicked"
QT_MOC_LITERAL(16, 219, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(17, 236, 4), // "item"
QT_MOC_LITERAL(18, 241, 9), // "exportGIF"
QT_MOC_LITERAL(19, 251, 26), // "on_addCanvasButton_clicked"
QT_MOC_LITERAL(20, 278, 30), // "on_fpsSpeedSlider_valueChanged"
QT_MOC_LITERAL(21, 309, 5), // "value"
QT_MOC_LITERAL(22, 315, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(23, 339, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(24, 363, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(25, 386, 24), // "on_previewButton_clicked"
QT_MOC_LITERAL(26, 411, 28) // "on_fullPreviewButton_clicked"

    },
    "MainWindow\0addCanvas\0\0addToStrip\0"
    "QImage*\0loadImage\0exportToGIF\0"
    "QVector<QImage*>\0GetcurrentToolFromBar\0"
    "SendCanvasCurrentTool\0BaseToolClass*\0"
    "sendPreviewImages\0images\0"
    "updatePreviewButtonStatus\0isActive\0"
    "onCanvasIconClicked\0QListWidgetItem*\0"
    "item\0exportGIF\0on_addCanvasButton_clicked\0"
    "on_fpsSpeedSlider_valueChanged\0value\0"
    "on_actionSave_triggered\0on_actionLoad_triggered\0"
    "on_actionNew_triggered\0on_previewButton_clicked\0"
    "on_fullPreviewButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    1,  100,    2, 0x06 /* Public */,
       5,    1,  103,    2, 0x06 /* Public */,
       6,    4,  106,    2, 0x06 /* Public */,
       8,    0,  115,    2, 0x06 /* Public */,
       9,    1,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  119,    2, 0x08 /* Private */,
      13,    1,  122,    2, 0x08 /* Private */,
      15,    1,  125,    2, 0x08 /* Private */,
      18,    0,  128,    2, 0x08 /* Private */,
      19,    0,  129,    2, 0x08 /* Private */,
      20,    1,  130,    2, 0x08 /* Private */,
      22,    0,  133,    2, 0x08 /* Private */,
      23,    0,  134,    2, 0x08 /* Private */,
      24,    0,  135,    2, 0x08 /* Private */,
      25,    0,  136,    2, 0x08 /* Private */,
      26,    0,  137,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addCanvas(); break;
        case 1: _t->addToStrip((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 2: _t->loadImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 3: _t->exportToGIF((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVector<QImage*>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->GetcurrentToolFromBar(); break;
        case 5: _t->SendCanvasCurrentTool((*reinterpret_cast< BaseToolClass*(*)>(_a[1]))); break;
        case 6: _t->sendPreviewImages((*reinterpret_cast< QVector<QImage*>(*)>(_a[1]))); break;
        case 7: _t->updatePreviewButtonStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onCanvasIconClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->exportGIF(); break;
        case 10: _t->on_addCanvasButton_clicked(); break;
        case 11: _t->on_fpsSpeedSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_actionSave_triggered(); break;
        case 13: _t->on_actionLoad_triggered(); break;
        case 14: _t->on_actionNew_triggered(); break;
        case 15: _t->on_previewButton_clicked(); break;
        case 16: _t->on_fullPreviewButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::addCanvas)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::addToStrip)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::loadImage)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(const QString & , const QVector<QImage*> & , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::exportToGIF)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::GetcurrentToolFromBar)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(BaseToolClass * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SendCanvasCurrentTool)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addCanvas()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::addToStrip(QImage * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::loadImage(QImage * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::exportToGIF(const QString & _t1, const QVector<QImage*> & _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::GetcurrentToolFromBar()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::SendCanvasCurrentTool(BaseToolClass * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
