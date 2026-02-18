// CSC 134
// M3T2 - Random Numbers
// Jayla Harper
// 02/16/26
// Start the game of craps.
#include <iostream>
#include <cstdlib> // For random
#include <ctime> // For time
using namespace std;

// Function declarations
// (Tell the program what functions will be.)
int roll();

// Main() goes here
int main() {
    // Seed the random number geerator
    int seed = time(0);
    srand(seed);

    // Roll two dice and show the results
    int first, second, total;
    string result; // Did we win or lose?
    first = roll();
    second = roll();
    total = first + second;
    cout << "You rolled 🎲 " << first << " + " << second << " = " << total << endl;

    // How did we do? 7 and 11 is win, 2, 3, 12 is lose, anything else is point.
    if (total == 7) {
        result = "win";
    }
    else if (total == 11) {
        result = "win";
    }
    else if (total == 3) {
        result = "lose";
    }
    else if (total == 12) {
        result = "lose";
    }
    else {
        // Must be a point roll
        result = "point";
    }
    cout << "ROLL results: " << result << endl;

    return 0;
}

// Function definitions
// (Actually write the entire function.)
int roll() {
    // Rand() gives a large random number
    // % 6 divides by six, and keeps the remainder
    // Finally add 1, so it's 1 to 6, not zero to five
    int my_roll = (rand() % 6) + 1;
    return my_roll;
}
