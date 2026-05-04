/*
CSC 134
Jayla Harper
M2T1
04/27/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
     // Declare variables without hard-coded values
    string name;
    int num_apples;
    double cost_each;

    // Get user input
    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter the number of apples: ";
    cin >> num_apples;

    cout << "Please enter the price per apple: ";
    cin >> cost_each;

    // Output — same as before, but now using user-entered values
    cout << "\nWelcome to the " << name << " apple farm!" << endl;
    cout << "There are " << num_apples << " apples in stock." << endl;
    cout << "They cost $" << cost_each << " each." << endl;

    // Calculate and display total
    double total_cost = num_apples * cost_each;
    cout << "The price for all of them is: $" << total_cost << endl;

    cout << endl;
    return 0; // no errors
}
