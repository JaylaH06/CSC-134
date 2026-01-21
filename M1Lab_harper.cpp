// CSC 134
// M1Lab1 - We're sellinh something
// 01/21/26
// Jayla Harper

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declare my variables
    string item_name = "books";
    int item_count =2000;
    double item_cost = 1.39;
    double total_cost;

    cout << setprecision(2) << fixed;



    cout << "Welcome to the " << item_name << " store." << endl;
    cout << "We have " << item_count << " " << item_name << "." << endl;
    cout << "They cost $" << item_cost << " each." << endl;
    total_cost = item_count * item_cost;



    cout << "To buy all of them will cost $" << total_cost << endl;

    return 0;
}