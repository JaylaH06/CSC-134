/*
CSC 134
Jayla Harper
05/04/26
M7T2
*/

#include <iostream>
using namespace std;

// Rectangle class declaration
class Rectangle {
    private:
    double width;
    double length;
    public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};

void Rectangle::setWidth(double w) {
    width =w;
}

void Rectangle ::setLength(double len) {
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

int main() {
    Rectangle box;
    double rectwidth;
    double rectLength;

    cout << "This program will calculate the area of a rectangle."
    cout << "What is the width?";
    cin >> rectWidth;
    cout << "What is the length?";
    cin >> rectLength;

    box.setWidth(rectWidth);
    box.setLength(rectLength);

    cout 
}