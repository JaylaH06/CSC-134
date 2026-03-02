/*
Jayla Harper
CSC 134
M3BONUS
03/02/26
*/

#include <iostream>
#include <string>
using namespace std;

// Function Declarations

void showWelcome();
void showResult(int score);
bool askQuestion(string question, string correctAnswer);

// Main

int main() {
    int score = 0;

    showWelcome();

    if (askQuestion("What is the name of Luffy's signature attack?","gum gum pistol")) score++;
    if (askQuestion("What fruit did Luffy eat to get his powers?","gum gum fruit")) score++;
    if (askQuestion("Who is the cook of the StrawHat crew?","sanji")) score++;
    if (askQuestion("What is Zoro's goal?","greatest swordsman")) score++;
    if (askQuestion("What is the name of the StrawHat's ship?","going merry")) score++;

    showResult(score);
    return 0;
}

// Function defintions

void showWelcome() {
    cout << "=======================================" << endl;
    cout << " ONE PIECE TRIVIA - Set Sail! 🏴‍☠️ " << endl;
    cout << "=======================================" << endl;
    cout << "Type your answers in lowercase." << endl;
    cout << "Let's see if you're worthy of the Grand Line!\n" << endl;
}

bool askQuestion(string question, string correctAnswer) {
    string playerAnswer;

    cout << "❓ " << question << endl;
    cout << "Your answer: ";
    getline(cin, playerAnswer);

    if (playerAnswer == correctAnswer) {
        cout << "✅ Correct! Bink's Sake for you!\n" << endl;
        return true;
    } else{
        cout << "❌ Wrong! The answer was: " << correctAnswer << "\n" << endl;
        return false;
    }
}

void showResult(int score) {
    cout << "=======================================" << endl;
    cout << " Results" << endl;
    cout << "=======================================" << endl;
    cout << "You got " << score << " out of 5!" << endl;

    if(score == 5) {
        cout << "PERFECT! You're the King of the Pirates! 👑" << endl;
    } else if (score >= 3) {
        cout << "Nice! You're a true StrawHat! ⚓" << endl;
    } else if (score >= 1) {
        cout << "Keep watching! The Grand Line awaits...🌊" << endl;
    } else {
        cout << "Did you even watch One Piece? 😅" << endl;
    }
}
