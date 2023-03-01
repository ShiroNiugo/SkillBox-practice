import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

Window {
    id: window
    width: 900
    height: 480
    visible: true
    title: qsTr("video player")

    GridLayout{
        id: grid
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        Button{
            id: play
            text: "\u25B6"
        }
        Button{
            id: pause
            text: "\u23F8"
        }
        Button{
            id: stop
            text: "\u23F9"
        }
        Button{
            id: rewind
            text: "\u23EA"
        }
        Button{
            id: forward
            text: "\u23E9"
        }
    }
    ProgressBar{
        id: progressBar
        width: window.width
        anchors.bottom: grid.bottom
    }

}
