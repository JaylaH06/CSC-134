//CSC 134
//M1T1 (Module 1, Tutorial 1)
//Hello, World!

// magic words
#include <iostream>
using namespace std;

int main() {
    cout << "I want cheezburger" <<endl;
    cout << "Hello, New York!" << endl; // E N D L
    cout << endl; // another new line

   string name; // new "box" to hold a name in
   cout << "What's your name? ";
   cin >> name; // read in their answer
   // Finally, say hi to them
   cout << "Well Hi, " << name << "!" << endl;
    return 0; // no errors
}