#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

class QuizManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(int currentQuestionIndex READ currentQuestionIndex WRITE setCurrentQuestionIndex NOTIFY currentQuestionIndexChanged)
    Q_PROPERTY(QString currentTopic READ currentTopic WRITE setCurrentTopic NOTIFY currentTopicChanged)
    Q_PROPERTY(int topicAttemptCount READ topicAttemptCount WRITE setTopicAttemptCount NOTIFY topicAttemptCountChanged)

public:
    explicit QuizManager(QObject *parent = nullptr);

    int score() const;
    void setScore(int score);

    int currentQuestionIndex() const;
    void setCurrentQuestionIndex(int currentQuestionIndex);

    QString currentTopic() const;
    Q_INVOKABLE void setCurrentTopic(const QString &currentTopic);

    int topicAttemptCount() const;
    void setTopicAttemptCount(int topicAttemptCount);

    Q_INVOKABLE void loadQuestions();
    Q_INVOKABLE QVariantMap getQuestion(int index);
//    Q_INVOKABLE int getQuestionsCount();
    Q_INVOKABLE void submitAnswer(int questionIndex, int answerIndex);
    Q_INVOKABLE void resetQuiz();
    Q_INVOKABLE void updateUserProgress(const QString &username, QJsonObject userData);
    Q_INVOKABLE QJsonObject getUserProgress(const QString &username);

signals:
    void scoreChanged();
    void currentQuestionIndexChanged();
    void currentTopicChanged();
    void topicAttemptCountChanged();
    void quizCompleted();

private:
    int m_score;
    int m_currentQuestionIndex;
    QString m_currentTopic;
    int m_topicAttemptCount;

    QJsonObject m_questions;
    QJsonArray m_userAnswers;

    int calculateQuestionValue(int index);
};

#endif // QUIZMANAGER_H
