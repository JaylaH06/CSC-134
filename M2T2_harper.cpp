// M2T2 - Receipt Caculator
// CSC 134
// Jayla Harper
// 01-28-26

#include <iostream>
using namespace std;

int main() {
    // Declare all variables
    string meal_name = "Salmon Platter";
    int num_meals;
    double meal_price = 5.99;
    double sub_total;
    double tax_rate = 0.08;
    double tip_amount;
    double tax_amount;
    double total_price;

    // Get user input
    cout << "Welcome to the CSC 134 Grill." << endl;
    cout << "Today's Special: " << meal_name << endl;
    cout << endl;
    cout << "How many would you like? ";
    cin >> num_meals;

    // Do the calculations
    sub_total = meal_price * num_meals;

    // Present the output
    cout << endl;
    cout << "YOUR ORDER" << endl << "--------------------" << endl;
    cout << num_meals << " x " << meal_name << "\t$" << meal_price << endl;
    cout << "Subtotal: \t$" << sub_total << endl;

    return 0;
}