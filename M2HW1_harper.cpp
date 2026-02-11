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





    return 0;
}