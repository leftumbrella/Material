#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "mypushbutton.hpp"
#include <QWidget>
#include <QPainter>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class StartScene; }
QT_END_NAMESPACE

class StartScene : public QWidget
{
    Q_OBJECT

public:
    enum Status{
      MainScene,DrawBoard
    };

    StartScene(QWidget *parent = nullptr);
    ~StartScene();

private:
    MyPushButton* _btn_again;
    Ui::StartScene *ui;
    virtual void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent*);

    StartScene::Status _status;
};
#endif // STARTSCENE_HPP
