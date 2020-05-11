#include "startscene.hpp"
#include "ui_startscene.h"

StartScene::StartScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartScene),_status(StartScene::MainScene){

//    setMinimumSize(QSize(600,600));
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
    _line_edit_w.push_back(QPair<QLineEdit*,QLineEdit*>(new QLineEdit(this),new QLineEdit(this)));
    _line_edit_w[0].first->setFont(f);
    _line_edit_w[0].first->resize(140,30);
    _line_edit_w[0].second->setFont(f);
    _line_edit_w[0].second->resize(140,30);
    _line_edit_w[0].first->setValidator(new QIntValidator(0, 1000, this));
    _line_edit_w[0].second->setValidator(new QIntValidator(0, 1000, this));
    _line_edit_w.push_back(QPair<QLineEdit*,QLineEdit*>(new QLineEdit(this),new QLineEdit(this)));
    _line_edit_w[1].first->setFont(f);
    _line_edit_w[1].first->resize(140,30);
    _line_edit_w[1].second->setFont(f);
    _line_edit_w[1].second->resize(140,30);
    _line_edit_w[1].first->setValidator(new QIntValidator(0, 1000, this));
    _line_edit_w[1].second->setValidator(new QIntValidator(0, 1000, this));


    //init _btn_more
    _btn_more[0] = new MyPushButton(this,30,30);_btn_more[1] = new MyPushButton(this,30,30);
    _btn_more[0]->setText("+");_btn_more[1]->setText("-");
    _btn_more[0]->setFont(f);_btn_more[1]->setFont(f);

    connect(_btn_more[0],&MyPushButton::clicked,[=](){
        qDebug() << "At fun connect _btn_more";
        if(_line_edit_w.size()==8){
            QMessageBox::critical(this,"错误","不能更多，当前子片最多数量为7！");
            return;
        }
        _line_edit_w.push_back(QPair<QLineEdit*,QLineEdit*>(new QLineEdit(this),new QLineEdit(this)));
        _line_edit_w[_line_edit_w.size()-1].first->setFont(f);
        _line_edit_w[_line_edit_w.size()-1].first->resize(140,30);
        _line_edit_w[_line_edit_w.size()-1].second->setFont(f);
        _line_edit_w[_line_edit_w.size()-1].second->resize(140,30);
        _line_edit_w[_line_edit_w.size()-1].first->move(width()*.2+_label_super->width()+10,height()*(0.25+((_line_edit_w.size()-2)*0.1))+22);
        _line_edit_w[_line_edit_w.size()-1].second->move(width()*.2+_label_super->width()+10+_line_edit_w[1].first->width()+10
                ,height()*(0.25+((_line_edit_w.size()-2)*0.1))+22);
        _line_edit_w[_line_edit_w.size()-1].first->show();
        _line_edit_w[_line_edit_w.size()-1].second->show();
        _line_edit_w[_line_edit_w.size()-1].first->setValidator(new QIntValidator(0, 1000, this));
        _line_edit_w[_line_edit_w.size()-1].second->setValidator(new QIntValidator(0, 1000, this));
    });
    connect(_btn_more[1],&MyPushButton::clicked,[=](){
        if(_line_edit_w.size()==2){
            QMessageBox::critical(this,"错误","至少需要一块子片！");
            return;
        }
        _line_edit_w[_line_edit_w.size()-1].first->hide();
        _line_edit_w[_line_edit_w.size()-1].second->hide();
        _line_edit_w.remove(_line_edit_w.size()-1);
    });


    connect(_btn_again,&QPushButton::clicked,[=](){
        if(_status==StartScene::MainScene){
            _sup_w = _line_edit_w[0].first->text().toInt();
            _sup_h = _line_edit_w[0].second->text().toInt();
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
            for(int i=1;i<_line_edit_w.size();++i){
                _squares.push_back(Square(_line_edit_w[i].first->text().toInt(),
                                          _line_edit_w[i].second->text().toInt(),Square::colorInfo(i-1)));
            }

            _btn_more[0]->hide();
            _btn_more[1]->hide();
            _label_son->hide();_label_super->hide();
            for(int i=0;i<_line_edit_w.size();++i){
                _line_edit_w[i].first->hide();
                _line_edit_w[i].second->hide();
                _line_edit_w[i].first->setText("");
                _line_edit_w[i].second->setText("");
            }

            //draw the dividing line
            pen.setWidth(1);
            pen.setColor(QColor(95,108,175));
            pen.setStyle(Qt::DashLine);//Qt::SolidLine
            painter.setPen(pen);
            painter.drawLine(QPoint(0,height()*.5),QPoint(width(),height()*.5));
            painter.drawLine(QPoint(width()*.5,0),QPoint(width()*.5,height()));

            //draw the base square
            pen.setWidth(3);
            pen.setColor(QColor(95,108,175));
            pen.setStyle(Qt::SolidLine);//Qt::SolidLine
            painter.setPen(pen);
            painter.drawRect(QRect(QPoint(0,0),QPoint(_sup_w*(height()*.5/(_sup_h>_sup_w?_sup_h:_sup_w))
                                                      ,_sup_h*(height()*.5/(_sup_h>_sup_w?_sup_h:_sup_w)))));
            _btn_again->setText("再来一次");
        break;
        case StartScene::MainScene:
            if(_label_son->isHidden()){
                _btn_more[0]->show();
                _btn_more[1]->show();
                _label_son->show();_label_super->show();
                for(int i=0;i<_line_edit_w.size();++i){
                    _line_edit_w[i].first->show();
                    _line_edit_w[i].second->show();
                }
            }

            _btn_again->setText("即刻生成");
        break;
    }
}
void StartScene::resizeEvent(QResizeEvent*){
     qDebug() << "At fun resize;width:"<<width()<<";height::"<<height();
    _btn_again->move(width()-_btn_again->width(),height()-_btn_again->height());
    _label_super->move(width()*.2,height()*.15);
    _label_son->move(width()*.2,height()*.25);

    _line_edit_w[0].first->move(width()*.2+_label_super->width()+10,height()*.15+22);
    _line_edit_w[0].second->move(width()*.2+_label_super->width()+10+_line_edit_w[0].first->width()+10
            ,height()*.15+22);
    _line_edit_w[1].first->move(width()*.2+_label_super->width()+10,height()*.25+22);
    _line_edit_w[1].second->move(width()*.2+_label_super->width()+10+_line_edit_w[1].first->width()+10
            ,height()*.25+22);
    for(int i=2;i<_line_edit_w.size();++i){
        _line_edit_w[i].first->move(width()*.2+_label_super->width()+10,height()*(0.25+((i-1)*0.1))+22);
        _line_edit_w[i].second->move(width()*.2+_label_super->width()+10+_line_edit_w[1].first->width()+10
                ,height()*(0.25+((i-1)*0.1))+22);
    }

    _btn_more[0]->move(width()*.2+_label_super->width()+10+_line_edit_w[1].first->width()+10
            +_line_edit_w[1].second->width()+10
            ,height()*.25+22);
    _btn_more[1]->move(width()*.2+_label_super->width()+10+_line_edit_w[1].first->width()+10
            +_line_edit_w[1].second->width()+10+_btn_more[0]->width()+10
            ,height()*.25+22);

}
StartScene::~StartScene(){
    delete ui;
}
const QVector<DrawPointer>& StartScene::calcPoints(const QVector<Square>& squares){
    //将squ的每个设为第一个进行尝试
    for(int i=0;i<squares.size();++i){
        //交换squ的w和h
        for(int j=0;i<2;++j){

        }
    }























}


