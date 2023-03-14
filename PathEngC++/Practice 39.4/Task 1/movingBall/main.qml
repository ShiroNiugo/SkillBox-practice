import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Moving ball")

    Rectangle{
        id: scene
        anchors.fill: parent
        state: "leftState";

        Rectangle{
            id: leftRect
            x: 100
            y: 200
            color: "pink"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            MouseArea{
                anchors.fill: parent
                onClicked: if(ball.x+ball.width <= rightRect.x) {ball.x += 30; scene.state = "otherState"}
                           else {scene.state = "leftState"}
            }
            Text {
                id: nameMove
                anchors.centerIn: parent
                text: "move"
            }
        }

        Rectangle{
            id: rightRect
            x: 300
            y: 200
            color: "lightgreen"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            MouseArea{
                anchors.fill: parent
                onClicked: scene.state = "leftState"
            }
            Text {
                id: nameReturn
                anchors.centerIn: parent
                text: "return"
            }
        }

        Rectangle{
            id: ball
            x: leftRect.x+5
            y: leftRect.y+5
            color: "red"
            width: leftRect.width-10
            height: leftRect.height-10
            border.color: "black"
            border.width: 3
            radius: width/2
        }

        states:[
            State{
                name: "leftState"
                PropertyChanges{
                    target: ball
                    x: leftRect.x + 5
                }
            },
            State{
                name: "otherState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }

        ]

        transitions: [
            Transition {
                from: "otherState"
                to: "leftState"

                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            }
        ]
    }
}
