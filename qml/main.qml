import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import io.qt.Prashnak 1.0

ApplicationWindow
{
    id: mainWindow
    visible: true
    width: 800
    height: 600
    title: "Prashnak Quiz Application"

    property int currentScreen: 0 // 0: Login, 1: Topic Selection, 2: Quiz, 3: Results

    Popup
    {
        id: lgnSccssPopup
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
        width: wrapContent
        height: 30
        modal: true
        background: Rectangle
        {
                color: "#00ffff"
        }
        contentItem: Text
        {
            text: "Login successful"
            color: "black"
            anchors.centerIn: parent
        }
    }

    Popup
    {
        id: rgstrtnSccssPopup
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
        width: wrapContent
        height: 30
        modal: true
        background: Rectangle
        {
                color: "#00ffff"
        }
        contentItem: Text
        {
            text: "Registration successful"
            color: "black"
            anchors.centerIn: parent
        }
    }

    Timer
    {
        id: closeRegisPopupTimer
        interval: 1000
        onTriggered: rgstrtnSccssPopup.close()
    }

    Timer
    {
        id: closeLoginPopupTimer
        interval: 1000
        onTriggered: lgnSccssPopup.close()
    }


    AuthManager
    {
        id: authManager
        onLoginSuccess:
        {
            lgnSccssPopup.open()
            closeLoginPopupTimer.start()
            currentScreen = 1;
        }
        onRegistrationSuccess:
        {
            rgstrtnSccssPopup.open()
            closeRegisPopupTimer.start()
            currentScreen = 0;
        }
    }

    QuizManager
    {
        id: quizManager
        onQuizCompleted:
        {
            resultManager.score = quizManager.score
            currentScreen = 3
        }
    }

    ResultManager
    {
        id: resultManager
    }

    Loader
    {
        id: screenLoader
        anchors.fill: parent

        source:
        {
            if (currentScreen === 0) return "LoginScreen.qml";
            else if (currentScreen === 1) return "TopicSelection.qml";
            else if (currentScreen === 2) return "QuizScreen.qml";
            else return "ResultScreen.qml";
        }
    }
}
