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
    cout << "Tip amount? (min 0)? ";
    cin >> tip_amount;

    // Do the calculations
    sub_total = meal_price * num_meals;
    tax_amount = sub_total * tax_rate;
    total_price = sub_total + tip_amount + tax_amount;

    // Present the output
    cout << endl;
    cout << "YOUR ORDER" << endl << "--------------------" << endl;
    cout << num_meals << " x " << meal_name << "\t$" << meal_price << endl;
    cout << "Subtotal: \t\t$" << sub_total << endl;
    cout << "Tip: \t\t$" << tip_amount << endl;
    cout << "Tax: \t\t$" << tax_amount << endl;
    cout << "--------------------" << endl;
    cout << "Total: \t\t$" << total_price << endl;
    cout << "THANK YOU COME AGAIN <3" << endl;

    return 0;
}