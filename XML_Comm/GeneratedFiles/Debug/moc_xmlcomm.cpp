/****************************************************************************
** Meta object code from reading C++ file 'xmlcomm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../xmlcomm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmlcomm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XMLComm_t {
    QByteArrayData data[19];
    char stringdata0[411];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLComm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLComm_t qt_meta_stringdata_XMLComm = {
    {
QT_MOC_LITERAL(0, 0, 7), // "XMLComm"
QT_MOC_LITERAL(1, 8, 22), // "OnDeviceStatusReceived"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 25), // "MessageReceivedEventArgs&"
QT_MOC_LITERAL(4, 58, 29), // "OnDeviceConfigurationReceived"
QT_MOC_LITERAL(5, 88, 25), // "OnDeviceDetectionReceived"
QT_MOC_LITERAL(6, 114, 33), // "OnDeviceInitializationMsgRece..."
QT_MOC_LITERAL(7, 148, 27), // "OnGeometryReportMsgReceived"
QT_MOC_LITERAL(8, 176, 20), // "OnCommandMsgReceived"
QT_MOC_LITERAL(9, 197, 20), // "OnInvalidMsgReceived"
QT_MOC_LITERAL(10, 218, 36), // "OnPlatformDetectionReportMsgR..."
QT_MOC_LITERAL(11, 255, 33), // "OnPlatformStatusReportMsgRece..."
QT_MOC_LITERAL(12, 289, 38), // "OnSubscriptionConfigurationMs..."
QT_MOC_LITERAL(13, 328, 24), // "OnTrackReportMsgReceived"
QT_MOC_LITERAL(14, 353, 9), // "OnMsgSent"
QT_MOC_LITERAL(15, 363, 8), // "readData"
QT_MOC_LITERAL(16, 372, 9), // "onConnect"
QT_MOC_LITERAL(17, 382, 15), // "onNewConnection"
QT_MOC_LITERAL(18, 398, 12) // "onDisconnect"

    },
    "XMLComm\0OnDeviceStatusReceived\0\0"
    "MessageReceivedEventArgs&\0"
    "OnDeviceConfigurationReceived\0"
    "OnDeviceDetectionReceived\0"
    "OnDeviceInitializationMsgReceived\0"
    "OnGeometryReportMsgReceived\0"
    "OnCommandMsgReceived\0OnInvalidMsgReceived\0"
    "OnPlatformDetectionReportMsgReceived\0"
    "OnPlatformStatusReportMsgReceived\0"
    "OnSubscriptionConfigurationMsgReceived\0"
    "OnTrackReportMsgReceived\0OnMsgSent\0"
    "readData\0onConnect\0onNewConnection\0"
    "onDisconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLComm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       5,    1,  100,    2, 0x06 /* Public */,
       6,    1,  103,    2, 0x06 /* Public */,
       7,    1,  106,    2, 0x06 /* Public */,
       8,    1,  109,    2, 0x06 /* Public */,
       9,    1,  112,    2, 0x06 /* Public */,
      10,    1,  115,    2, 0x06 /* Public */,
      11,    1,  118,    2, 0x06 /* Public */,
      12,    1,  121,    2, 0x06 /* Public */,
      13,    1,  124,    2, 0x06 /* Public */,
      14,    1,  127,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  130,    2, 0x08 /* Private */,
      16,    0,  131,    2, 0x0a /* Public */,
      17,    0,  132,    2, 0x0a /* Public */,
      18,    0,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void XMLComm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<XMLComm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnDeviceStatusReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 1: _t->OnDeviceConfigurationReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 2: _t->OnDeviceDetectionReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 3: _t->OnDeviceInitializationMsgReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 4: _t->OnGeometryReportMsgReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 5: _t->OnCommandMsgReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 6: _t->OnInvalidMsgReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 7: _t->OnPlatformDetectionReportMsgReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 8: _t->OnPlatformStatusReportMsgReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 9: _t->OnSubscriptionConfigurationMsgReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 10: _t->OnTrackReportMsgReceived((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 11: _t->OnMsgSent((*reinterpret_cast< MessageReceivedEventArgs(*)>(_a[1]))); break;
        case 12: _t->readData(); break;
        case 13: _t->onConnect(); break;
        case 14: _t->onNewConnection(); break;
        case 15: _t->onDisconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnDeviceStatusReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnDeviceConfigurationReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnDeviceDetectionReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnDeviceInitializationMsgReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnGeometryReportMsgReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnCommandMsgReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnInvalidMsgReceived)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnPlatformDetectionReportMsgReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnPlatformStatusReportMsgReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnSubscriptionConfigurationMsgReceived)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnTrackReportMsgReceived)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (XMLComm::*)(MessageReceivedEventArgs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XMLComm::OnMsgSent)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject XMLComm::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_XMLComm.data,
    qt_meta_data_XMLComm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *XMLComm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLComm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XMLComm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int XMLComm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void XMLComm::OnDeviceStatusReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XMLComm::OnDeviceConfigurationReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XMLComm::OnDeviceDetectionReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void XMLComm::OnDeviceInitializationMsgReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void XMLComm::OnGeometryReportMsgReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void XMLComm::OnCommandMsgReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void XMLComm::OnInvalidMsgReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void XMLComm::OnPlatformDetectionReportMsgReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void XMLComm::OnPlatformStatusReportMsgReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void XMLComm::OnSubscriptionConfigurationMsgReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void XMLComm::OnTrackReportMsgReceived(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void XMLComm::OnMsgSent(MessageReceivedEventArgs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
