import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Controls.Basic
import QtQuick.Layouts 1.12
import io.qt.Prashnak 1.0

Item
{
    id: topicSelection
    width: wrapContent
    height: wrapContent

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
                text: "Welcome, " + authManager.username
                font.pixelSize: 24
                Layout.alignment: Qt.AlignHCenter
                color: "#2c3e50"
            }

            Text
            {
                text: "Select a Topic"
                font.pixelSize: 28
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
                color: "#2c3e50"
                Layout.topMargin: 20
            }

            Grid
            {
                id: topcChoicGrid
                columns: 2
                rows:2
                rowSpacing: parent.height/4
                columnSpacing: parent.width/4
                width: parent.width
                height: parent.height
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                Repeater
                {
                    model: ["History", "Geography", "General Science", "Miscellaneous"]

                    delegate: Button
                    {
                        contentItem: Text
                        {

                            text: modelData
                            anchors.centerIn: parent
                            font.pixelSize: 18
                            color: "black"
                            font.bold: true
                            id: buttonIndex
                        }

                        background: Rectangle
                        {
                            width: 200
                            implicitHeight: parent.height
                            opacity: enabled ? 1 : 0.3
                            color: "cyan"
                            border.width: 1
                            radius: 2
                        }

                        width: parent.width/4
                        height: 50

                        onClicked:
                        {
                            quizManager.setCurrentTopic(modelData)
                            var userProgress= authManager.userData.progress
                            //userProgress[modelData]= (userProgress[modelData]+1)%3
                            mainWindow.currentScreen = 2;
                        }
                    }
                }
            }
        }
    }
}
