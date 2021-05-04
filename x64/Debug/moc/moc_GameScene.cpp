/****************************************************************************
** Meta object code from reading C++ file 'GameScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GameScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameScene_t {
    QByteArrayData data[14];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameScene_t qt_meta_stringdata_GameScene = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GameScene"
QT_MOC_LITERAL(1, 10, 9), // "mouseMove"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 25), // "QGraphicsSceneMouseEvent*"
QT_MOC_LITERAL(4, 47, 10), // "mouseEvent"
QT_MOC_LITERAL(5, 58, 10), // "mousePress"
QT_MOC_LITERAL(6, 69, 12), // "mouseRelease"
QT_MOC_LITERAL(7, 82, 10), // "gameattack"
QT_MOC_LITERAL(8, 93, 8), // "gamemove"
QT_MOC_LITERAL(9, 102, 18), // "produceFirstZombie"
QT_MOC_LITERAL(10, 121, 14), // "produceZombies"
QT_MOC_LITERAL(11, 136, 9), // "countdown"
QT_MOC_LITERAL(12, 146, 15), // "produceSunshine"
QT_MOC_LITERAL(13, 162, 7) // "peashoo"

    },
    "GameScene\0mouseMove\0\0QGraphicsSceneMouseEvent*\0"
    "mouseEvent\0mousePress\0mouseRelease\0"
    "gameattack\0gamemove\0produceFirstZombie\0"
    "produceZombies\0countdown\0produceSunshine\0"
    "peashoo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   73,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    0,   75,    2, 0x0a /* Public */,
      10,    0,   76,    2, 0x0a /* Public */,
      11,    0,   77,    2, 0x0a /* Public */,
      12,    0,   78,    2, 0x0a /* Public */,
      13,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameScene *_t = static_cast<GameScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseMove((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->mousePress((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseRelease((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->gameattack(); break;
        case 4: _t->gamemove(); break;
        case 5: _t->produceFirstZombie(); break;
        case 6: _t->produceZombies(); break;
        case 7: _t->countdown(); break;
        case 8: _t->produceSunshine(); break;
        case 9: _t->peashoo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameScene::*_t)(QGraphicsSceneMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameScene::mouseMove)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GameScene::*_t)(QGraphicsSceneMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameScene::mousePress)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GameScene::*_t)(QGraphicsSceneMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameScene::mouseRelease)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject GameScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_GameScene.data,
      qt_meta_data_GameScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameScene.stringdata0))
        return static_cast<void*>(const_cast< GameScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int GameScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
void GameScene::mouseMove(QGraphicsSceneMouseEvent * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameScene::mousePress(QGraphicsSceneMouseEvent * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameScene::mouseRelease(QGraphicsSceneMouseEvent * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
