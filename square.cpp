#include "square.hpp"

Square::Square(int width,int height,QColor color)
    :_width(width),_height(height),_color(color){

}
QColor Square::COLOR[7] = {QColor(192,72,81),QColor(139,38,113),QColor(116,117,155)
                           ,QColor(22,97,171),QColor(16,174,194),QColor(31,161,98)
                           ,QColor(252,195,7)};
