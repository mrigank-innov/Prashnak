#include "resultmanager.h"

ResultManager::ResultManager(QObject *parent) : QObject(parent), m_score(0)
{
}

int ResultManager::score() const
{
    return m_score;
}

void ResultManager::setScore(int score)
{
    if (m_score == score)
        return;

    m_score = score;
    emit scoreChanged();
}

QString ResultManager::getScoreMessage()
{
    if (m_score >= 25) {
        return QString("Bravo!! Your score is %1 out of 30").arg(m_score);
    } else if (m_score >= 20) {
        return QString("Well tried. Your score is %1 out of 30").arg(m_score);
    } else if (m_score >= 15) {
        return QString("Not bad. Your score is %1 out of 30").arg(m_score);
    } else {
        return QString("Your score is %1 out of 30").arg(m_score);
    }
}
