import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item
{
    id: resultScreen
    width: 800
    height: 600

    Rectangle
    {
        anchors.fill: parent
        color: "#87ceeb"

        ColumnLayout
        {
            anchors.centerIn: parent
            width: parent.width * 0.8
            spacing: 30

            Text
            {
                text: resultManager.getScoreMessage()
                font.pixelSize: 28
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
                color: "#000000"
            }

            Button
            {
                text: "Try Another Topic"
                Layout.fillWidth: true
                font.pixelSize: 18
                onClicked: mainWindow.currentScreen = 1
            }

            Button
            {
                text: "Logout"
                Layout.fillWidth: true
                font.pixelSize: 18
                onClicked:
                {
                    authManager.logout()
                    mainWindow.currentScreen = 0
                }
            }
        }
    }
}
