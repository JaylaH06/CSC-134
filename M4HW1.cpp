/*
Jayla Harper
CSC 134
05/04/26
M4HW1
Gold Level
*/

#include <iostream>
using namespace std;

int main() {
    int number;

    // --- Input Validation Loop ---
    // This loop will NOT exit until the user enters a valid number
    cout << "Enter a number from 1 to 12: ";
    cin >> number;

    while (number < 1 || number > 12) {
        cout << "Invalid input. Please enter a number between 1 and 12: ";
        cin >> number;
    }

    // --- Times Table Loop ---
    // Only reaches here once a valid number has been entered
    cout << endl;

    int counter = 1;
    while (counter <= 12) {
        cout << number << " times " << counter << " is " << number * counter << "." << endl;
        counter++;
    }

    cout << endl;
    return 0; // no errors
}