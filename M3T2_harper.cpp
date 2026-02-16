// CSC 134
// M3T2 - Random Numbers
// Jayla Harper
// 02/16/26
// Start the game of craps.
#include <iostream>
using namespace std;

// Function declarations
// (Tell the program what functions will be.)
int roll();

// Main() goes here
int main() {
    int number = roll();
    cout << "You rolled a " << number << endl;
    return 0;
}

// Function definitions
// (Actually write the entire function.)
int roll() {
    return 1; // These dice are loaded.
}
