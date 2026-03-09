/*
CSC 134
M4HW1
Jayla Harper
03/09/26
*/

#include <iostream>
using namespace std;

int main() {

    // Declare variables
    int firstNum, secondNum, answer, sum;
    firstNum = 3;
    //secondNum = 7;
    //sum = firstNum * secondNum;

    // A sample message, with variables
    // cout << "2 times 1 is 2\n";
    for (int i=1; i <= 5; i++) {
        sum = firstNum * i;
        cout << "What is " << firstNum << " times " << i << "\n";
    cin >> answer;
    if (answer == sum) {
        cout << "Great Job!" << endl;
    } else {
        cout << "Uhh that isn't right" << "\n" << "It's actually " << sum << endl;
    }
    cout << firstNum << " times " << i << " is " << sum << endl;
    }
    
}