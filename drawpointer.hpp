#ifndef DRAWPOINTER_HPP
#define DRAWPOINTER_HPP

#include <QPoint>
class DrawPointer
{
public:
    DrawPointer(QPoint start=QPoint(0,0),QPoint end=QPoint(0,0));
    inline const QPoint& getPStart()const{
        return _point_start;
    };
    inline const QPoint& getPEnd()const{
        return _point_end;
    }
private:
    QPoint _point_start;
    QPoint _point_end;
};

#endif // DRAWPOINTER_HPP
