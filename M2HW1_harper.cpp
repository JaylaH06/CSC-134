/*
CSC 134
M2HW1 - Gold Grading Tiers
Jayla Harper
2/11/26
*/

#include <iostream>
#include <iomanip>
using namespace std;


int main() {

    cout << "QUESTION 1" << endl;

    // First Question

    // Declare all variables
    double start_balance;
    double deposit_amount;
    double withdrawl_amount;
    double final_balance;
    int account_num;

    // Get User Input
    cout << "Welcome to The Diamond Galore Bank." << endl;
    string name;
    cout << "What's your User? ";
    cin >> name;
    cout << "Welcome back, " << name << "!" << " Happy to see you using our services again. What would you like to do today? " << endl;
    cout << endl;
    cout << "What is the Starting Account Balance? ";
    cin >> start_balance;
    cout << "What is the amount that you wish to deposit? ";
    cin >> deposit_amount;
    cout << "What is the amount you wish to withdraw? ";
    cin >> withdrawl_amount;

    // Do the calculations
    final_balance = start_balance + deposit_amount - withdrawl_amount;

    // Present the output
    cout << setprecision(2) << fixed;
    cout << endl;
    cout << "------------------" << endl;
    cout << "TICKET NUMBER " << endl << "0000000000001" << endl;
    cout << "User " << "-----> " << name << endl;
    cout << "Account Number " << "345678994 " << endl;
    cout << "Routing Number " << "*****4567 " << endl;
    cout << "New Account Balance: " << final_balance << endl;


    cout << "QUESTION 2" << endl;

    // Second Question

    // Part 1 -- Declare Variables
    // Constant Variables (Don't change unless the market changes)
    const double COST_PER_CUBIC_FOOT = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;

    // Crate variables 
    double length, width, height, volume; // all  in feet
    // Money variables
    double cost, customer_price, profit; // all in $

    // Part 2 -- Get the Input
    cout << "Welcome to the Crate Program." << endl;
    cout << "Enter the crate dimensions." << endl;

    cout << "Crate Length? ";
    cin >> length;
    cout << "Crate Width? ";
    cin >> width;
    cout << "Crate Height? ";
    cin>> height;

    // Part 3 --  Do the Calculations
    volume = length * width * height;
    // Find the cost and the customer_price
    cost= volume * COST_PER_CUBIC_FOOT;
    customer_price = volume * CHARGE_PER_CUBIC_FOOT;
    profit = customer_price - cost;

    // Part 4 -- Print the Output
    cout << setprecision(2) << fixed;
    cout << "==== CRATE INFO ====" << endl;
    cout << "Volume is " << volume << "cubic feet " << endl;
    cout << "Wholesale price is $" << cost << endl;
    cout << "Customer price is $" << customer_price << endl;
    cout << "Profit per crate: $" << profit << endl;

    cout << "QUESTION 3" << endl;

    // Third Question

    // Variables
    int pizza_num;
    int pizza_slices;
    int people_coming;
    int slices_left;
    int slices_total;

    // Get input
    cout << "How many pizza's did you want to order? " << endl;
    cin >> pizza_num;
    cout << "How many slices did you want per pizza? " << endl;
    cin >> pizza_slices;
    cout << "How many people are coming to the party? " << endl;
    cin >> people_coming;

    // Do the calculations
    slices_left = pizza_num * pizza_slices - people_coming;
    slices_total = pizza_num * pizza_slices;
    if (slices_total < people_coming) {
        cout << "You may want to increase your amount of pizza's you don't have enough to feed everyone." << endl;
    }
    // Print output

    cout << "If you were to get " <<  pizza_num << " pizza's with " << pizza_slices << " slices in each and have " << people_coming << " people coming you would have " << slices_left << " slices of pizza left over." << endl;

    cout << "QUESTION 4 " << endl;

    // Fourth Question
    string school_name = " FTCC";
    string team_name =  " Trojans ";

    //Output
    cout << " Let's go " << school_name << endl;
    cout << " Let's go " << school_name << endl;
    cout << " Let's go " << school_name << endl;
    cout << " Let's go " << team_name << endl;


    return 0;
}