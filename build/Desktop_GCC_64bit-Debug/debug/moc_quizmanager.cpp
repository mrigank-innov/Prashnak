/****************************************************************************
** Meta object code from reading C++ file 'quizmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../quizmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quizmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11QuizManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto QuizManager::qt_create_metaobjectdata<qt_meta_tag_ZN11QuizManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QuizManager",
        "scoreChanged",
        "",
        "currentQuestionIndexChanged",
        "currentTopicChanged",
        "topicAttemptCountChanged",
        "quizCompleted",
        "setCurrentTopic",
        "currentTopic",
        "loadQuestions",
        "getQuestion",
        "QVariantMap",
        "index",
        "submitAnswer",
        "questionIndex",
        "answerIndex",
        "resetQuiz",
        "updateUserProgress",
        "username",
        "userData",
        "getUserProgress",
        "score",
        "currentQuestionIndex",
        "topicAttemptCount"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'scoreChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentQuestionIndexChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentTopicChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'topicAttemptCountChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'quizCompleted'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'setCurrentTopic'
        QtMocHelpers::MethodData<void(const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Method 'loadQuestions'
        QtMocHelpers::MethodData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getQuestion'
        QtMocHelpers::MethodData<QVariantMap(int)>(10, 2, QMC::AccessPublic, 0x80000000 | 11, {{
            { QMetaType::Int, 12 },
        }}),
        // Method 'submitAnswer'
        QtMocHelpers::MethodData<void(int, int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 }, { QMetaType::Int, 15 },
        }}),
        // Method 'resetQuiz'
        QtMocHelpers::MethodData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'updateUserProgress'
        QtMocHelpers::MethodData<void(const QString &, QJsonObject)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 18 }, { QMetaType::QJsonObject, 19 },
        }}),
        // Method 'getUserProgress'
        QtMocHelpers::MethodData<QJsonObject(const QString &)>(20, 2, QMC::AccessPublic, QMetaType::QJsonObject, {{
            { QMetaType::QString, 18 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'score'
        QtMocHelpers::PropertyData<int>(21, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'currentQuestionIndex'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'currentTopic'
        QtMocHelpers::PropertyData<QString>(8, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'topicAttemptCount'
        QtMocHelpers::PropertyData<int>(23, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QuizManager, qt_meta_tag_ZN11QuizManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QuizManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QuizManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QuizManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QuizManagerE_t>.metaTypes,
    nullptr
} };

void QuizManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QuizManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->scoreChanged(); break;
        case 1: _t->currentQuestionIndexChanged(); break;
        case 2: _t->currentTopicChanged(); break;
        case 3: _t->topicAttemptCountChanged(); break;
        case 4: _t->quizCompleted(); break;
        case 5: _t->setCurrentTopic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->loadQuestions(); break;
        case 7: { QVariantMap _r = _t->getQuestion((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->submitAnswer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->resetQuiz(); break;
        case 10: _t->updateUserProgress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 11: { QJsonObject _r = _t->getUserProgress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QuizManager::*)()>(_a, &QuizManager::scoreChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuizManager::*)()>(_a, &QuizManager::currentQuestionIndexChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuizManager::*)()>(_a, &QuizManager::currentTopicChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuizManager::*)()>(_a, &QuizManager::topicAttemptCountChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuizManager::*)()>(_a, &QuizManager::quizCompleted, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->score(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->currentQuestionIndex(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->currentTopic(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->topicAttemptCount(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setScore(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setCurrentQuestionIndex(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setCurrentTopic(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setTopicAttemptCount(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QuizManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuizManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QuizManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QuizManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QuizManager::scoreChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QuizManager::currentQuestionIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QuizManager::currentTopicChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QuizManager::topicAttemptCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QuizManager::quizCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
