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
void showResult(int score, int total);
bool askQuestion(string question, string correctAnswer);
bool askQuestion(string question, string choiceA, string choiceB, string choiceC, string choiceD, string correctLetter);

// Main

int main() {
    int score = 0;
    int total = 8;

    showWelcome();

    if (askQuestion("What is the name of Luffy's signature attack?","gum gum pistol")) score++;
    if (askQuestion("What fruit did Luffy eat to get his powers?","gum gum fruit")) score++;
    if (askQuestion("Who is the cook of the StrawHat crew?","sanji")) score++;
    if (askQuestion("What is Zoro's goal?","greatest swordsman")) score++;
    if (askQuestion("What is the name of the StrawHat's ship?","going merry")) score++;

    // New multiple choice questions
    if (askQuestion(
        "What is the name of the sea Luffy grew up near?",
        "East Blue", "West Blue", "North Blue", "South Blue",
        "a")) score++;

     if (askQuestion(
        "Who taught Zoro his swordsmanship as a child?",
        "Shanks", "Mihawk", "Kuina", "Rayleigh",
        "c")) score++;

    if (askQuestion(
        "What is Nami's role on the Straw Hat crew?",
        "Doctor", "Navigator", "Sniper", "Archaeologist",
        "b")) score++;

    showResult(score, total);
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

bool askQuestion(string question, string choiceA, string choiceB, string choiceC, string choiceD, string correctLetter) {
    string playerAnswer;

    cout << "❓ " << question << endl;
    cout << "A) " << choiceA << endl;
    cout << "B) " << choiceB << endl;
    cout << "C) " << choiceC << endl;
    cout << "D) " << choiceD << endl;
    cout << "Your answer: (a/b/c/d) ";
    getline(cin, playerAnswer);

    for (char& c : playerAnswer) c = tolower(c); // Converts Uppercase to Lowercase

    if (playerAnswer == correctLetter) {
        cout << "✅ Correct! Bink's Sake for you!\n" << endl;
        return true;
    } else {
        cout << "❌ Wrong! The answer was: " << correctLetter << "-";
        if (correctLetter == "a") cout << choiceA << "\n" << endl;
        else if (correctLetter == "b") cout << choiceB << "\n" << endl;
        else if (correctLetter == "c") cout << choiceC << "\n" << endl;
        else cout << choiceD << "\n" << endl;
        return false;
    }
}

void showResult(int score, int total) {
    cout << "=======================================" << endl;
    cout << " Results" << endl;
    cout << "=======================================" << endl;
    cout << "You got " << score << " out of " << total << "!" << endl;

    if(score == total) {
        cout << "PERFECT! You're the King of the Pirates! 👑" << endl;
    } else if (total * 0.6) {
        cout << "Nice! You're a true StrawHat! ⚓" << endl;
    } else if (score >= 1) {
        cout << "Keep watching! The Grand Line awaits...🌊" << endl;
    } else {
        cout << "Did you even watch One Piece? 😅" << endl;
    }
}
