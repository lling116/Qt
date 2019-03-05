/****************************************************************************
** Meta object code from reading C++ file 'info.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../untitled/info.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'info.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_info_t {
    QByteArrayData data[11];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_info_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_info_t qt_meta_stringdata_info = {
    {
QT_MOC_LITERAL(0, 0, 4), // "info"
QT_MOC_LITERAL(1, 5, 8), // "insertSN"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 5), // "snInf"
QT_MOC_LITERAL(4, 21, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 43, 16), // "on_onBtn_clicked"
QT_MOC_LITERAL(6, 60, 20), // "on_cancelBtn_clicked"
QT_MOC_LITERAL(7, 81, 17), // "on_delBtn_clicked"
QT_MOC_LITERAL(8, 99, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(9, 123, 23), // "on_lineEdit_textChanged"
QT_MOC_LITERAL(10, 147, 4) // "arg1"

    },
    "info\0insertSN\0\0snInf\0on_pushButton_clicked\0"
    "on_onBtn_clicked\0on_cancelBtn_clicked\0"
    "on_delBtn_clicked\0on_pushButton_2_clicked\0"
    "on_lineEdit_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_info[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void info::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        info *_t = static_cast<info *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insertSN((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_onBtn_clicked(); break;
        case 3: _t->on_cancelBtn_clicked(); break;
        case 4: _t->on_delBtn_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject info::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_info.data,
      qt_meta_data_info,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *info::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *info::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_info.stringdata0))
        return static_cast<void*>(const_cast< info*>(this));
    return QWidget::qt_metacast(_clname);
}

int info::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
