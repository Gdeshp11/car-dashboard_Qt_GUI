import QtQuick 2.12
import QtQuick.Window 2.12


Window {
    id:window
    width: 650
    height: 450
    visible: true
    title: qsTr("Vehicle Simulator")

    property var car_state: 0

    Rectangle
    {
        id:road_rect
        width:300
        height:450
        anchors.left:window.left
        anchors.top:window.top

        AnimatedImage {
            id: road_animation
            height: 450
            width: 300
            playing: true
            speed: 1.0
            source: "resources/road.gif"
        }

        Image {
            id: car
            height: 100
            width: 70
            x:165
            y:200
            source: "resources/car.png"
//            rotation: -6

        }
    }

//    Rectangle {
//        id:steer_left_rect
//        anchors.bottom: parent.bottom
//        height: 20
//        width: 55
//        x:320
//        color: "blue"
//    Text {
//        id: steer_left
//        text: qsTr("steer left")
//        color: "white"
//    }
//    MouseArea {
//        anchors.fill: parent
//        onClicked:
//        {
//            car.x-=20
////            road_animation.speed-=0.2
//        }
//    }
//    }

//    Rectangle {
//        id:steer_right_rect
//        anchors.bottom: parent.bottom
//        height: 20
//        width: 55
//        anchors.left:steer_left_rect.right
//        color: "blue"
//    Text {
//        id: steer_right
//        text: qsTr("steer right")
//        color: "white"
//    }
//    MouseArea {
//        anchors.fill: parent
//        onClicked:
//        {
//            car.x+=20
////            road_animation.speed+=0.2
//        }
//    }
//    }
    Text {
        id: speed_text
        color: "red"
        x: 350
        y: 50
        height: 50
        width:50
        font.pointSize: 20
        text: "speed:0"
    }
    Text {
        id: accl_text
        color: "red"
        anchors.top:speed_text.bottom
//        anchors.verticalCenter: speed_text.verticalCenter
        height: 50
        width:50
        x: 350
        y: 150
        font.pointSize: 20
        text: "acceleration:0"
    }
    Text {
        id: distance_text
        anchors.top:accl_text.bottom
//        anchors.verticalCenter: accl_text.verticalCenter
        color: "red"
        height: 50
        width:50
        font.pointSize: 20
        x: 350
        y: 250
        text: "distance:0"
    }
    Text {
        id: steer_text
        color: "red"
        anchors.top:distance_text.bottom
//        anchors.verticalCenter: distance_text.verticalCenter
        height: 50
        width:50
        font.pointSize: 20
        x: 350
        y: 350
        text: "steering angle:0"
    }

    Connections {
        target: vehicleInfo

        onSpeedUpdate:{
            console.log(speed)
            speed_text.text=speed
        }
        onDistanceUpdate:{
            console.log(distance)
            distance_text.text=distance
        }
        onAccelerationUpdate:{
            console.log(accl)
            accl_text.text=accl
        }
        onSteeringAngleUpdate:{
            console.log(steering_angle)
            steer_text.text=steering_angle
        }
    }

}





