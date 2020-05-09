#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "mypushbutton.hpp"
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
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

    QLabel * _label_super;
    QLabel * _label_son;

    QLineEdit* _line_edit_w[8];
};
#endif // STARTSCENE_HPP
