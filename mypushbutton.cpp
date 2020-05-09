#include "mypushbutton.hpp"

MyPushButton::MyPushButton(QWidget *parent,int w,int h)
    : QPushButton(parent),_color_main("#5f6caf"),_color_secondary("#edf7fa"){
    resize(w,h);
    setColorMain(false);

    QFont f;
    f.setFamily("楷体");
    f.setBold(true);
    f.setPixelSize(20);
    setFont(f);

}
void MyPushButton::enterEvent(QEvent *){
    setColorMain(true);
}
void MyPushButton::leaveEvent(QEvent *){
    setColorMain(false);
}
void MyPushButton::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        setColorMain(false);
    }
    QPushButton::mousePressEvent(event);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *event){
    setColorMain(true);
    QPushButton::mouseReleaseEvent(event);
}
void MyPushButton::setColorMain(bool isBgMain){
    QString style_str;
    if(isBgMain){
        style_str = QString("background:%1;border:3px solid %2;color:%3;")
                    .arg(_color_main).arg(_color_secondary).arg(_color_secondary);
    }else{
        style_str = QString("background:%1;border:3px solid %2;color:%3;")
                    .arg(_color_secondary).arg(_color_main).arg(_color_main);
    }
    setStyleSheet(style_str);
}
