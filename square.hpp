#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <QColor>
class Square{
public:
    Square(int width =0,int height =0,QColor color = COLOR[0]);
    static QColor COLOR[7];
    inline int getWidth()const{
        return _width;
    };
    inline int getHeight()const{
      return _height;
    };
    inline QColor getColor()const{
        return _color;
    };
    inline Square& setColor(QColor color){
        _color = color;
        return *this;
    }
    inline static const QColor& colorInfo(int i){
        return COLOR[i];
    }
private:
    int _width;
    int _height;
    QColor _color;
};

#endif // SQUARE_HPP
