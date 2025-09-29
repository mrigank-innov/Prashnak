#include "authmanager.h"
#include <QDebug>
#include<QVariantMap>
#include<QDir>
#include <QRegularExpression>

AuthManager::AuthManager(QObject *parent) : QObject(parent), m_username("")
{
    loadUserData();
}

QString AuthManager::username() const
{
    return m_username;
}

void AuthManager::setUsername(const QString &username)
{
    if (m_username == username)
        return;

    m_username = username;
    emit usernameChanged();
}

QVariantMap AuthManager::userData()
{
    return m_userData.toVariantMap();
}

bool AuthManager::validateLogin(const QString &email, const QString &password)
{
    if (m_userData.contains(email))
    {
        QJsonObject user = m_userData[email].toObject();
        if (user["password"].toString() == password)
        {
            setUsername(user["username"].toString());
            emit loginSuccess();
            return true;
        }
    }
    emit loginFailed();
    return false;
}

bool AuthManager::registerUser(const QString &email, const QString &password, const QString &username)
{
    if (m_userData.contains(email))
    {
        emit registrationFailed();
        return false;
    }

    QJsonObject newUser;
    newUser["password"] = password;
    newUser["username"] = username;
    newUser["progress"] = QJsonObject();
    QJsonObject userProgress = newUser["progress"].toObject();
    userProgress["History"] = 0;
    userProgress["Geography"] = 0;
    userProgress["General Science"] = 0;
    userProgress["Miscellaneous"] = 0;

    m_userData[email] = newUser;
    saveUserData();
    emit userDataChanged();

    setUsername(username);
    emit registrationSuccess();
    return true;
}

void AuthManager::logout()
{
    setUsername("");
}

void AuthManager::loadUserData()
{
    QFile file("../../data/userdata.json");
    if (!file.open(QIODevice::ReadOnly))
    {
        // Create empty user data if file doesn't exist
        m_userData = QJsonObject();
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    m_userData = doc.object();
    file.close();
}

void AuthManager::saveUserData()
{
    QFile file("../../data/userdata.json");
    if (!file.open(QIODevice::WriteOnly))
    {
        qWarning() << "Could not open user data file for writing";
        return;
    }

    QJsonDocument doc(m_userData);
    file.write(doc.toJson());
    file.close();
    emit userDataChanged();
}

int AuthManager::validatePassword(QString passwd)
{
    if(passwd.length()<8)
        return 0;
    int k=0;
    for(QChar &ch: passwd)
    {
        if(ch.isLetter())
        {
            k++;
        }
        if(ch.isDigit())
        {
            k++;
        }
        if(k==2)
            return 1;
    }
    return 0;
}

int AuthManager::validateEmail(QString email)
{
    if(email.length()<6)
        return 0;
    int atIndex = email.indexOf('@');
    if (atIndex <= 0 || atIndex >= email.length() - 1)
    {
        return 0;
    }
    if (!email.endsWith(".com"))
    {
        return 0;
    }
    return 1;
}
