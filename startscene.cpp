#include "startscene.hpp"
#include "ui_startscene.h"

StartScene::StartScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartScene),_status(StartScene::MainScene)
{

    setMinimumSize(QSize(500,500));
    ui->setupUi(this);
    setStyleSheet("background:#edf7fa;");
    _btn_again = new MyPushButton(this,100,50);


    connect(_btn_again,&QPushButton::clicked,[=](){
         qDebug() << "At btn clicked!!!";
        if(_status==StartScene::MainScene){
            qDebug() << "At status changed!!!";
            _status = StartScene::DrawBoard;
        }else{
            _status = StartScene::MainScene;
        }
        update();
    });
}
void StartScene::paintEvent(QPaintEvent *event){
    qDebug() << "At fun Paint!!!";
    QPainter painter(this);
    QPen pen;
    switch (_status) {
        case StartScene::DrawBoard:
            pen.setWidth(3);
            pen.setColor(QColor(95,108,175));
            painter.setPen(pen);
            painter.drawLine(QPoint(0,height()*.5),QPoint(width(),height()*.5));
            painter.drawLine(QPoint(width()*.5,0),QPoint(width()*.5,height()));
            _btn_again->setText("再来一次");
        break;
        case StartScene::MainScene:
            _btn_again->setText("即刻生成");
        break;
    }

}
void StartScene::resizeEvent(QResizeEvent*){
    _btn_again->move(width()-_btn_again->width(),height()-_btn_again->height());
}
StartScene::~StartScene()
{
    delete ui;
}

