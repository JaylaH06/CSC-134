/*
CSC 134
Jayla Harper
05/04/26
M7T2
*/

#include <iostream>
#include "Rectangle.h"
using namespace std;
 
int main() {
    Rectangle box;
    double rectWidth;
    double rectLength;
 
    cout << "This program will calculate the area of a rectangle.\n";
 
    // Input validation for width
    cout << "What is the width? ";
    cin >> rectWidth;
    while (rectWidth <= 0) {
        cout << "Error: Width must be greater than zero.\n";
        cout << "What is the width? ";
        cin >> rectWidth;
    }
 
    // Input validation for length
    cout << "What is the length? ";
    cin >> rectLength;
    while (rectLength <= 0) {
        cout << "Error: Length must be greater than zero.\n";
        cout << "What is the length? ";
        cin >> rectLength;
    }
 
    box.setWidth(rectWidth);
    box.setLength(rectLength);
 
    cout << "\nHere is the rectangle's data:\n";
    cout << "Width:  " << box.getWidth()  << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area:   " << box.getArea()   << endl;
 
    return 0;
}