/* CSC 134
M3T1 - Program Specifications
Jayla Harper
2/11/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // As a user, I want to measure rectangles to find out how big they are.

    // Set up variables
    double length1, width1, area1;
    double length2, width2, area2;

    // Ask user for info
    cout << "What is the rectangle's length? ";
    cin >> length1;
    cout << "What is the rectangle's width? ";
    cin >> width1;
    cout << "What is the second rectangle's length? ";
    cin >> length2;
    cout << "What is the second rectangle's width? ";
    cin >> width2;

    // Do calculations
    area1 = length1 * width1;
    area2 = length2 * width2;

    // Print the answer
    cout << setprecision(2) << fixed;
    cout << "The area is: " << area1 << " Feet " << endl;
    cout << "The area is: " << area2 << " Feet " << endl;
}