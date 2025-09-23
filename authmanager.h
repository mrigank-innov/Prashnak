#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include<QVariantMap>

class AuthManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QVariantMap userData READ userData NOTIFY userDataChanged)

public:
    explicit AuthManager(QObject *parent = nullptr);

    QString username() const;
    void setUsername(const QString &username);

    QVariantMap userData() ;

    Q_INVOKABLE bool validateLogin(const QString &email, const QString &password);
    Q_INVOKABLE bool registerUser(const QString &email, const QString &password, const QString &username);
    Q_INVOKABLE void logout();
    Q_INVOKABLE int validatePassword(QString psswd);
    Q_INVOKABLE int validateEmail(QString email);

signals:
    void usernameChanged();
    void userDataChanged();
    void loginSuccess();
    void loginFailed();
    void registrationSuccess();
    void registrationFailed();

private:
    QString m_username;
    QJsonObject m_userData;

    void loadUserData();
    void saveUserData();
};

#endif // AUTHMANAGER_H
