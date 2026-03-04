/*
CSC 134
M3HW1 - Gold
Jayla Harper
03/04/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // Question 1
    cout << "Question 1" << endl;

    string input;

    cout << "Hello, I'm a C++ program!";
    cout << "Do you like me?";
    cout << "\nPlease type yes or no: ";
    getline(cin, input);
    
    if (input == "yes") {
        cout << "That's great! I'm sure we'll get along." << endl;
    } else if (input == "no") {
        cout << "Well, maybe you'll learn to like me later." << endl;
    } else {
        cout << "If you're not sure... that's OK." << endl;
    }

    // Question 2
    cout << "Question 2" << endl;

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
    cout << "What is the price of this meal?" << endl;
    getline(cin, meal_price);

    if (meal_price == 5.99) {
        cout << "Perfect! Is this order Dine in or take away?" << endl;
    }   else {
        cout << "I'm not sure if this is the right price?" << endl;
    }
    cout << "How many would you like? ";
    cin >> num_meals;
    cout << "Tip amount? (min 0)? ";
    cin >> tip_amount;

    // Do the calculations
    sub_total = meal_price * num_meals;
    tax_amount = sub_total * tax_rate;
    total_price = sub_total + tip_amount + tax_amount;

    // Present the output
    cout << setprecision(2) << fixed;
    cout << endl;
    cout << "YOUR ORDER" << endl << "--------------------" << endl;
    cout << num_meals << " x " << meal_name << "\t$" << meal_price << endl;
    cout << "Subtotal: \t\t$" << sub_total << endl;
    cout << "Tip: \t\t$" << tip_amount << endl;
    cout << "Tax: \t\t$" << tax_amount << endl;
    cout << "--------------------" << endl;
    cout << "Total: \t\t$" << total_price << endl;
    cout << "THANK YOU COME AGAIN <3" << endl;

}