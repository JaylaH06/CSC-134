/*
CSC 134
M3HW1 - Gold
Jayla Harper
03/04/26
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {

    // Question 1
    cout << "Question 1" << endl;

    string input;

    cout << "Hello, I'm a C++ program!";
    cout << " Do you like me?";
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

    // Declare all variables
    string meal_name = "Salmon Platter";
    int num_meals;
    double meal_price;
    double sub_total;
    double tax_rate = 0.08;
    double tip_amount = 0.0;
    double tip_rate = 0.15;
    double tax_amount;
    double total_price;
    int order_type;

    // Get user input
    cout << "Welcome to the CSC 134 Grill." << endl;
    cout << "Today's Special: " << meal_name << endl;
    cout << endl;

    cout << "What is the price of the meal? $";
    cin >> meal_price;

    cout << "How many would you like? ";
    cin >> num_meals;

    cout << "Please enter 1 if the order is dine in, 2 if it is to go: ";
    cin >> order_type;

    // Do the calculations
    sub_total = meal_price * num_meals;
    tax_amount = sub_total * tax_rate;

    if (order_type == 1) {
        tip_amount = sub_total * tip_rate;
    }

    total_price = sub_total + tip_amount + tax_amount;

    // Present the output
    cout << setprecision(2) << fixed;
    cout << endl;
    cout << "YOUR ORDER" << endl;
    cout << "--------------------" << endl;
    cout << num_meals << " x " << meal_name << "\t$" << meal_price << endl;
    cout << "Subtotal: \t\t$" << sub_total << endl;
    cout << "Tax (7%): \t\t$" << tax_amount << endl;

    if (order_type == 1) {
        cout << "Tip (15%): \t\t$" << tip_amount << endl;
    }

    cout << "--------------------" << endl;
    cout << "Order Type: \t\t" << (order_type == 1 ? "Dine In" : "To Go") << endl;
    cout << "Total: \t\t\t$" << total_price << endl;
    cout << "THANK YOU COME AGAIN <3" << endl;

    // Question 3
    cout << "Quetion 3" << endl;

    string name;
    int choice;
    int gryffindor = 0, slytherin = 0, ravenclaw = 0, hufflepuff = 0;

    cout << "========================================" << endl;
    cout << "   Welcome to the Hogwarts Sorting Quiz  " << endl;
    cout << "========================================" << endl;
    cout << "What is your name? ";
    cin >> name;
    cout << endl;
    cout << "Hello, " << name << "! The Sorting Hat will now ask you" << endl;
    cout << "5 questions to determine your house." << endl;
    cout << endl;

    cout << "Question 1: What do you value most?" << endl;
    cout << "1. Courage and Bravery" << endl;
    cout << "2. Ambition and Cunning" << endl;
    cout << "3. Wisdom and Knowledge" << endl;
    cout << "4. Loyalty and Hardwork" << endl;
    cout << "Your choice (1-4): ";
    cin >> choice;
    
    if (choice == 1) gryffindor++;
    else if (choice == 2) slytherin++;
    else if (choice == 3) ravenclaw++;
    else if (choice == 4) hufflepuff++;
    cout << endl;

    cout << "Question 2: You find a wallet full of money on the ground." << endl;
    cout << " What do you do?" << endl;
    cout << "1. Turn it in immediately -- it's the right thing to do!" << endl;
    cout << "2. Keep it, Finders keepers." << endl;
    cout << "3. Research the best way to find the owner." << endl;
    cout << "4. Ask around and try to return it to someone nearby." << endl;
    cout << "Your choice (1-4): ";
    cin >> choice;
    if (choice == 1) gryffindor++;
    else if (choice == 2) slytherin++;
    else if (choice == 3) ravenclaw++;
    else if (choice == 4) hufflepuff++;
    cout << endl;

    cout << "Question 3: Which class would you enjoy most at Hogwarts?" << endl;
    cout << "1. Defense against The Dark Arts." << endl;
    cout << "2. Potions" << endl;
    cout << "3. Charms or Arthimancy" << endl;
    cout << "4. Herbology or Care of Magical Creatures." << endl;
    cout << "Your choice (1-4): ";
    cin >> choice;
    if (choice == 1) gryffindor++;
    else if (choice == 2) slytherin++;
    else if (choice == 3) ravenclaw++;
    else if (choice == 4) hufflepuff++;
    cout << endl;

    cout << "Question 4: How do your friends describe you?" << endl;
    cout << "1. Bold and Daring" << endl;
    cout << "2. Determined and Resourceful" << endl;
    cout << "3. Thoughtful and Curious" << endl;
    cout << "4. Kind and Dependable" << endl;
    cout << "Your choice (1-4): ";
    cin >> choice;
    if (choice == 1) gryffindor++;
    else if (choice == 2) slytherin++;
    else if (choice == 3) ravenclaw++;
    else if (choice == 4) hufflepuff++;
    cout << endl;

    cout << "Question 5: What is your greatest fear?" << endl;
    cout << "1. Being seen as a coward" << endl;
    cout << "2. Failure or losing power" << endl;
    cout << "3. Being seen as ignorant" << endl;
    cout << "4. Letting down those you love" << endl;
    cout << "Your choice (1-4): ";
    cin >> choice;
    if (choice == 1) gryffindor++;
    else if (choice == 2) slytherin++;
    else if (choice == 3) ravenclaw++;
    else if (choice == 4) hufflepuff++;
    cout << endl;

    string house, description, members;
    int maxScore = gryffindor;

    if (slytherin > maxScore) maxScore = slytherin;
    if (ravenclaw > maxScore)  maxScore = ravenclaw;
    if (hufflepuff > maxScore) maxScore = hufflepuff;

    if (maxScore == gryffindor) {
        house       = "GRYFFINDOR";
        description = "You are brave, daring, and full of nerve.\n"
                      "You face challenges head-on and inspire others.";
        members     = "Harry Potter, Hermione Granger, Ron Weasley";
    } else if (maxScore == slytherin) {
        house       = "SLYTHERIN";
        description = "You are ambitious, shrewd, and determined.\n"
                      "You know what you want and how to get it.";
        members     = "Draco Malfoy, Severus Snape, Merlin";
    } else if (maxScore == ravenclaw) {
        house       = "RAVENCLAW";
        description = "You are wise, creative, and love learning.\n"
                      "Your sharp mind is your greatest asset.";
        members     = "Luna Lovegood, Cho Chang, Filius Flitwick";
    } else {
        house       = "HUFFLEPUFF";
        description = "You are loyal, patient, and hardworking.\n"
                      "You value fairness and care deeply for others.";
        members     = "Cedric Diggory, Nymphadora Tonks, Newt Scamander";
}

cout << "========================================" << endl;
    cout << "   THE SORTING HAT HAS DECIDED..." << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << name << ", you belong in..." << endl;
    cout << endl;
    cout << "*** " << house << " ***" << endl;
    cout << endl;
    cout << description << endl;
    cout << endl;
    cout << "Notable alumni: " << members << endl;
    cout << endl;
    cout << "========================================" << endl;
    cout << "  Welcome to your new home, " << name << "!" << endl;
    cout << "========================================" << endl;

    // Question 4
    cout << "Question 4" << endl;

     int answer;
    int first, second, total;

    // Seed the random number generator
    srand(time(0));

    // Generate two random single-digit numbers (0-9)
    first  = rand() % 10;
    second = rand() % 10;
    total  = first + second;

    // Ask the question
    cout << "What is " << first << " plus " << second << "? " << endl;
    cin >> answer;

    // Check the answer
    if (answer == total) {
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect. The answer was " << total << "." << endl;
    }

    return 0;
}