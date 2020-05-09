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

    //init labels
    QFont f;
    f.setFamily("楷体");
    f.setBold(true);
    f.setPixelSize(20);
    _label_super=new QLabel(this);_label_son = new QLabel(this);
    _label_son->setText("设置子片大小:");_label_super->setText("设置母片大小:");
    _label_son->show();_label_super->show();
    _label_super->resize(140,70);_label_son->resize(140,70);
    _label_super->setFont(f);_label_son->setFont(f);

    //init lineedit
    _line_edit_w[0]=new QLineEdit(this);
    _line_edit_w[0]->setFont(f);
    _line_edit_w[0]->resize(140,30);
    _line_edit_w[1]=new QLineEdit(this);
    _line_edit_w[1]->setFont(f);
    _line_edit_w[1]->resize(140,30);


    connect(_btn_again,&QPushButton::clicked,[=](){
        if(_status==StartScene::MainScene){
            _status = StartScene::DrawBoard;
        }else{
            _status = StartScene::MainScene;
        }
        update();
//        QMessageBox::critical(this,"错误","当前子片面积已大于母板!");

    });
}
void StartScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPen pen;
    switch (_status) {
        case StartScene::DrawBoard:
            _label_son->hide();_label_super->hide();
            _line_edit_w[0]->hide();
            _line_edit_w[1]->hide();
            pen.setWidth(3);
            pen.setColor(QColor(95,108,175));
            painter.setPen(pen);
            painter.drawLine(QPoint(0,height()*.5),QPoint(width(),height()*.5));
            painter.drawLine(QPoint(width()*.5,0),QPoint(width()*.5,height()));
            _btn_again->setText("再来一次");
        break;
        case StartScene::MainScene:
            if(_label_son->isHidden()){
                _label_son->show();_label_super->show();
                _line_edit_w[0]->show();
                _line_edit_w[1]->show();
            }

            _btn_again->setText("即刻生成");
        break;
    }

}
void StartScene::resizeEvent(QResizeEvent*){
    _btn_again->move(width()-_btn_again->width(),height()-_btn_again->height());
    _label_super->move(width()*.2,height()*.15);
    _label_son->move(width()*.2,height()*.25);

    _line_edit_w[0]->move(width()*.2+_label_super->width()+10,height()*.15+22);
    _line_edit_w[1]->move(width()*.2+_label_super->width()+10,height()*.25+22);
}
StartScene::~StartScene()
{
    delete ui;
}

