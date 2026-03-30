// CSC 134
// 03/30/26
// Jayla Harper
// M5Lab2 Area of a Reactangle

#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here.

    double getLength();
    double getWidth();
    double getArea(double length, double width);
    void displayData(double length, double width, double area);


int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;

}

     //***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************

    double getLength() {
    double length;
    cout << "Enter the rectangle length: " << endl;
    cin >> length;
    return length;
    }
    double getWidth(){
    double width;
    cout << "Enter the rectangle width: " << endl;
    cin >> width;
    return width;
    }
    
double getArea(double length, double width){
     double area;
    area = length * width;
    return area;


}
    void displayData(double length, double width, double area){
        cout << "The length is " << length << endl;
        cout << "The width is " << width << endl;
        cout << "The area is: " << area << endl;
    }

   
    
