#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "mypushbutton.hpp"
#include "square.hpp"
#include "drawpointer.hpp"
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <QIntValidator>
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
    int _sup_w ;
    int _sup_h ;
    QLabel * _label_super;
    QLabel * _label_son;

    QVector<QPair<QLineEdit*,QLineEdit*>> _line_edit_w;

    MyPushButton* _btn_more[2];

    QVector<Square> _squares;

    const QVector<DrawPointer>& calcPoints(const QVector<Square>& squares);
};
#endif // STARTSCENE_HPP
