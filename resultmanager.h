#ifndef RESULTMANAGER_H
#define RESULTMANAGER_H

#include <QObject>
#include <QString>

class ResultManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)

public:
    explicit ResultManager(QObject *parent = nullptr);

    int score() const;
    void setScore(int score);

    Q_INVOKABLE QString getScoreMessage();

signals:
    void scoreChanged();

private:
    int m_score;
};

#endif // RESULTMANAGER_H
