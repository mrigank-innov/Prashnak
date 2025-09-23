#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "authmanager.h"
#include "quizmanager.h"
#include "resultmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Register our backend classes with QML
    qmlRegisterType<AuthManager>("io.qt.Prashnak", 1, 0, "AuthManager");
    qmlRegisterType<QuizManager>("io.qt.Prashnak", 1, 0, "QuizManager");
    qmlRegisterType<ResultManager>("io.qt.Prashnak", 1, 0, "ResultManager");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
