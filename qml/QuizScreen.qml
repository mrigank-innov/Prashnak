import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item
{
    id: quizScreen
    width: 800
    height: 600

    property int currentQuestion: 0

    Component.onCompleted:
    {
        // Load user progress for the selected topic
        var progress = quizManager.getUserProgress(authManager.username)
        if (progress && progress.hasOwnProperty(quizManager.currentTopic))
        {
            quizManager.topicAttemptCount = progress[quizManager.currentTopic]
            quizManager.setTopicAttemptCount(progress[quizManager.currentTopic])
        }
        else
        {
            progress[quizManager.currentTopic]=1

        }
        quizManager.resetQuiz()
        currentQuestion = 0
    }

    Rectangle
    {
        anchors.fill: parent
        color: "#87ceeb"

        ColumnLayout
        {
            anchors.fill: parent
            anchors.margins: 20

            Text
            {
                text: quizManager.currentTopic + " - Question " + (currentQuestion + 1) + " of 10"
                font.pixelSize: 20
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
                color: "#2c3e50"
            }

            Text
            {
                text: "Score: " + quizManager.score
                font.pixelSize: 18
                Layout.alignment: Qt.AlignRight
                color: "#2c3e50"
            }            
            Text
            {
                id: curTopic
                text: qsTr(quizManager.currentTopic)
            }
            Rectangle
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                color: "white"
                radius: 10
                border.color: "#ddd"

                Text
                {
                    id: questionText
                    text: quizManager.getQuestion(currentQuestion).question || "Loading question..."
                    anchors.centerIn: parent
                    width: parent.width - 40
                    wrapMode: Text.Wrap
                    font.pixelSize: 18
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            ColumnLayout
            {
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: 10

                Repeater
                {
                    model: 4
                    delegate: Button
                    {
                        text: quizManager.getQuestion(currentQuestion).options[index]
                        Layout.fillWidth: true
                        Layout.preferredHeight: 60
                        font.pixelSize: 16
                        onClicked:
                        {
                            quizManager.submitAnswer(currentQuestion, index)
                            if (currentQuestion < 9)
                            {
                                currentQuestion++
                            }
                            else
                            {
                                // Update user progress when quiz is completed
                                quizManager.updateUserProgress(authManager.username, authManager.userData)
                            }
                        }
                    }
                }
            }

            ProgressBar
            {
                Layout.fillWidth: true
                value: currentQuestion + 1
                from: 0
                to: 10
            }

            Button
            {
                text: "Back to Topics"
                Layout.alignment: Qt.AlignLeft
                onClicked:
                {
                    mainWindow.currentScreen = 1;
                }
            }
        }
    }

    Connections
    {
        target: quizManager
        onQuizCompleted:
        {
            console.log("Quiz completed, showing results");
        }
    }
}
