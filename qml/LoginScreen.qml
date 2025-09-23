import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import io.qt.Prashnak 1.0

Item
{
    id: loginScreen
    width: 800
    height: 600

    Rectangle
    {
        anchors.fill: parent
        color: "#87ceeb"

        ColumnLayout
        {
            anchors.centerIn: parent
            width: parent.width * 0.6
            spacing: 20

            Text
            {
                text: "Prashnak Quiz"
                font.pixelSize:  32
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
                color: "#2c3e50"
            }

            TabBar
            {
                id: tabBar
                Layout.fillWidth: true
                currentIndex: 0

                TabButton
                {
                    text: "Login"
                }
                TabButton
                {
                    text: "Register"
                }
            }

            StackLayout
            {
                id: stackLayout
                Layout.fillWidth: true
                currentIndex: tabBar.currentIndex

                // Login Form
                ColumnLayout
                {
                    spacing: 15

                    TextField
                    {
                        id: loginEmail
                        placeholderText: "Email"
                        Layout.fillWidth: true
                        font.pixelSize: 16
                    }

                    TextField
                    {
                        id: loginPassword
                        placeholderText: "Password"
                        Layout.fillWidth: true
                        echoMode: TextInput.Password
                        font.pixelSize: 16
                    }

                    Button
                    {
                        text: "Login"
                        Layout.fillWidth: true
                        font.pixelSize: 16
                        onClicked:
                        {
                            if (authManager.validateLogin(loginEmail.text, loginPassword.text))
                            {
                                console.log("Login initiated");
                            }
                        }
                    }

                    Text
                    {
                        id: loginError
                        text : "Invalid email or password"
                        visible: false
                        color: "red"
                        Layout.alignment: Qt.AlignHCenter
                    }

                }

                // Registration Form
                ColumnLayout
                {
                    spacing: 15

                    TextField
                    {
                        id: regEmail
                        placeholderText: "Email"
                        Layout.fillWidth: true
                        font.pixelSize: 16
                    }

                    TextField
                    {
                        id: regUsername
                        placeholderText: "Username"
                        Layout.fillWidth: true
                        font.pixelSize: 16
                    }

                    TextField
                    {
                        id: regPassword
                        placeholderText: "Password(length should be min 8, and should be alphanumeric)"
                        Layout.fillWidth: true
                        echoMode: TextInput.Password
                        font.pixelSize: 16
                    }

                    TextField
                    {
                        id: regConfirmPassword
                        placeholderText: "Confirm Password"
                        Layout.fillWidth: true
                        echoMode: TextInput.Password
                        font.pixelSize: 16
                    }

                    Button
                    {
                        text: "Register"
                        Layout.fillWidth: true
                        font.pixelSize: 16
                        onClicked:
                        {
                            noPasswdMatch.visible = false
                            invalidEmail.visible = false
                            invalidPassword.visible = false
                            if(authManager.validateEmail(regEmail.text) === 0)
                            {
                                invalidEmail.visible = true
                            }
                            else if(authManager.validatePassword(regPassword.text) === 0)
                            {
                                invalidPassword.visible = true
                            }
                            else
                            {
                                if (regPassword.text === regConfirmPassword.text)
                                {
                                    if (authManager.registerUser(regEmail.text, regPassword.text, regUsername.text))
                                    {
                                        console.log("Registration initiated")
                                    }
                                }
                                else
                                {
                                    noPasswdMatch.visible = true
                                }
                            }
                        }
                    }
                    Text
                    {
                        id: regError
                        text:"Email already exists"
                        visible: false
                        color: "red"
                        Layout.alignment: Qt.AlignHCenter
                    }
                    Text
                    {
                        id: noPasswdMatch
                        text:"Passwords don't match"
                        visible: false
                        color: "red"
                        Layout.alignment: Qt.AlignHCenter
                    }
                    Text
                    {
                        id: invalidEmail
                        text:"Invalid email id"
                        visible: false
                        color: "red"
                        Layout.alignment: Qt.AlignHCenter
                    }
                    Text
                    {
                        id: invalidPassword
                        text:"Invalid password"
                        visible: false
                        color: "red"
                        Layout.alignment: Qt.AlignHCenter
                    }

                }
            }
        }
    }

    Connections
    {
        target: authManager
        onLoginFailed:
        {
            loginError.visible = true;
        }
        onRegistrationFailed:
        {
            regError.visible = true;
        }
    }
}
