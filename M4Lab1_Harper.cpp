/*
CSC 134
M4Lab1
Jayla Harper
03/09/26
*/

#include <iostream>
using namespace std;

int main() {

    // Declare Variables
    int height, width;

    // Set size
    // To finish, use variable sizes, by asking the user
   // height = 5;
    // width = 5;
    cout << "How tall should the block be?" << endl;
    cin >> height;
    cout << "How wide should the block be?" << endl;
    cin >> width;
    // Make a row of astericks
    cout << "One row" << endl;
    for (int i=0; i < width; i++) {
        cout << "*" << " ";
    }
    cout << endl; // Finish the row

    // Make a column  of astericks
    cout << "One column" << endl;
    for (int j=0; j < height; j++) {
        cout << "*" << endl;
    }

    // Nested Loops
    cout << "The entire block" << endl;
    for (int j=0; j < height; j++) {
        // Print one row
        for ( int i=0; i < width; i++) {
            cout << "*" << " ";
        }
        cout << endl; // End the row with a new line
    }
}