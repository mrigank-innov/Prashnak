#include "quizmanager.h"
#include <QDebug>
#include<QJsonArray>

QuizManager::QuizManager(QObject *parent) : QObject(parent),
    m_score(0),
    m_currentQuestionIndex(0),
    m_currentTopic(""),
    m_topicAttemptCount(0)
{
    loadQuestions();
}

int QuizManager::score() const
{
    return m_score;
}

void QuizManager::setScore(int score)
{
    if (m_score == score)
        return;

    m_score = score;
    emit scoreChanged();
}

int QuizManager::currentQuestionIndex() const
{
    return m_currentQuestionIndex;
}

void QuizManager::setCurrentQuestionIndex(int currentQuestionIndex)
{
    if (m_currentQuestionIndex == currentQuestionIndex)
        return;

    m_currentQuestionIndex = currentQuestionIndex;
    emit currentQuestionIndexChanged();
}

QString QuizManager::currentTopic() const
{
    return m_currentTopic;
}

void QuizManager::setCurrentTopic(const QString &currentTopic)
{
    if (m_currentTopic == currentTopic)
        return;

    m_currentTopic = currentTopic;
    qDebug()<< "Printing current topic in the setCurrentTopic function"<<m_currentTopic;
    emit currentTopicChanged();
}

int QuizManager::topicAttemptCount() const
{
    return m_topicAttemptCount;
}

void QuizManager::setTopicAttemptCount(int topicAttemptCount)
{
    if (m_topicAttemptCount == topicAttemptCount)
        return;

    m_topicAttemptCount = topicAttemptCount;
    emit topicAttemptCountChanged();
}

void QuizManager::loadQuestions()
{
    QString dataFileLctn = "C:/Users/DELL/Documents/Prashnak/data/questions.json";
    QFile file(dataFileLctn);
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning() << "Could not open questions file";
        return;
    }

    QByteArray data = file.readAll();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data,&parseError);
    if (parseError.error != QJsonParseError::NoError)
    {
        qWarning() << "JSON Parse Error:" << parseError.errorString();
        return;
    }
    m_questions = doc.object();
    file.close();
}

QVariantMap QuizManager::getQuestion(int index)
{
    QVariantMap questionData;

    // Check if we have any questions loaded
    if (m_questions.isEmpty())
    {
        qWarning() << "No questions loaded!";
        return questionData;
    }

    if (index < 0 || index > 10) // Only 10 questions per quiz
        return questionData;

    // Calculate which set of questions to use based on attempt count
    int startIndex = (m_topicAttemptCount  * 10 -1)<0? (m_topicAttemptCount  * 10):(m_topicAttemptCount  * 10 -1);
    int questionIndex = startIndex + index;

    QJsonArray arrayQuestion = m_questions[m_currentTopic].toArray();
    QJsonObject questionObj = arrayQuestion[questionIndex].toObject();
    questionData["question"] = questionObj["question"].toString();
    questionData["options"] = questionObj["options"].toArray().toVariantList();
    questionData["correct_option"] = questionObj["correct_option"].toInt()-1;
    questionData["value"] = calculateQuestionValue(index);

    return questionData;
}

void QuizManager::submitAnswer(int questionIndex, int answerIndex)
{
    QVariantMap question = getQuestion(questionIndex);
    int correctAnswer = (question["correct_option"].toInt());
    int marks = question["value"].toInt();

    if (answerIndex == correctAnswer)
    {
        setScore(m_score + marks);
        qDebug() << "The m_score is"<< m_score;
    }

    // Store the answer for later review if needed
    QJsonObject answer;
    answer["questionIndex"] = questionIndex;
    answer["selectedAnswer"] = answerIndex;
    answer["correctAnswer"] = correctAnswer;
    answer["isCorrect"] = (answerIndex == correctAnswer);

    m_userAnswers.append(answer);

    // Check if quiz is completed
    if (questionIndex == 9)
    {
        emit quizCompleted();
    }
}

void QuizManager::resetQuiz()
{
    setScore(0);
    setCurrentQuestionIndex(0);
    m_userAnswers = QJsonArray();
}

void QuizManager::updateUserProgress(const QString &username, QJsonObject userData)
{
    if (userData.contains(username))
    {
        QJsonObject user = userData[username].toObject();
        QJsonObject progress;

        if (user.contains("progress"))
        {
            progress = user["progress"].toObject();
        }

        progress[m_currentTopic] = (m_topicAttemptCount + 1)%3;
        user["progress"] = progress;
        userData[username] = user;

        // Save the updated user data
        QFile file("userdata.json");
        if (file.open(QIODevice::WriteOnly))
        {
            QJsonDocument doc(userData);
            file.write(doc.toJson());
            file.close();
        }
    }
}

QJsonObject QuizManager::getUserProgress(const QString &username)
{
    QFile file("C:/Users/DELL/Documents/Prashnak/data/userdata.json");
    if (!file.open(QIODevice::ReadOnly))
    {
        return QJsonObject();
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject userData = doc.object();
    file.close();

    if (userData.contains(username))
    {
        QJsonObject user = userData[username].toObject();
        if (user.contains("progress"))
        {
            return user["progress"].toObject();
        }
    }

    return QJsonObject();
}

int QuizManager::calculateQuestionValue(int index)
{
    if (index < 4) return 2;    // Easy questions: 2 marks
    if (index < 8) return 3;    // Medium questions: 3 marks
    return 5;                   // Hard questions: 5 marks
}
