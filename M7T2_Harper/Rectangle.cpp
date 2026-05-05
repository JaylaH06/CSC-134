#include "Rectangle.h"
 
void Rectangle::setWidth(double w) {
    width = w;
}
 
void Rectangle::setLength(double len) {
    length = len;
}
 
double Rectangle::getWidth() const {
    return width;
}
 
double Rectangle::getLength() const {
    return length;
}
 
double Rectangle::getArea() const {
    return width * length;
}