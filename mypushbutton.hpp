#ifndef MYPUSHBUTTON_HPP
#define MYPUSHBUTTON_HPP

#include <QPushButton>
#include <QMouseEvent>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr,int w=100,int h=100);

signals:
private:
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setColorMain(bool);

    QString _color_main;
    QString _color_secondary;
};

#endif // MYPUSHBUTTON_HPP
