// CSC 134
// M3Lab1
// Jayla Harper
// 02/23/26

#include <iostream>
using namespace std;

// List prtotypes of all choices up here
void Bubbly_woowoo_1();
void Sparkly_Wallbanger_2();
void Fuzzy_Navel_3();
void Snake_wine_4();

// main() goes here
int main() {

    int choice;
    // main() starts the game
    cout << "Spell-Check The Brewing Game 🧙" << endl << endl;
    cout << " You're a lonesome witch that lives in the woods. A 'Coven of One' if you will.";
    cout << " But like any witch you need to make a living, newt tails aren't cheap.";
    cout << " So you make potions for the creatures of the forest to fund your lifestyle.";
    cout << " Todays customer is an Nidhogg who wantss to visit his grandma in the Netherlands.";
    cout << " The only problem is that Mr. Nidhogg has horrible seasonal allergies and needs something to make the journey there a bit easier on his sinuses.";
    cout << " I have everything else set up. But for somme reason I can't remember the last ingredient.";
    cout << " So, I need and I need your help!";
    cout << " There's four different bottles here which one should we use?";

    cout << "Do you: " << endl;
    cout << "1. Bubbly WooWoo" << endl;
    cout << "2. Sparkly WallBanger" << endl;
    cout << "3. Fuzzy Navel" << endl;
    cout << "4. Snake Wine" << endl;

    cout << "> "; // Give them a prompt to type
    cin >> choice;

    if (1 == choice) {
        Bubbly_woowoo_1();
        cout << " He turns into a butterfly and gets eaten by a crow...You avoid any calls from his grandma for the next 100 years.";
    }
    else if (2 == choice) {
        Sparkly_Wallbanger_2();
        cout << " His allergies are cured for the entire duration of his visit! You did fantastic!";
    }
    else if (3 == choice) {
         Fuzzy_Navel_3();
         cout << " He shrinks 6 sizes down...He now wants to sue you for everything you own.";
    }
    else if (4 == choice) {
        Snake_wine_4();
        cout << " He starts speaking another language! I don't know what he's saying but he sounds mad.";
    }
    else {
        cout << "We couldn't pick up that ingredient...They raised the prices of Spider Eyes." << endl;
    }
    cout << "*Game Over*" << endl << endl;

    return 0; // End of Game
}

// List full functions of all the choices at  the bottom
void Bubbly_woowoo_1() {
    cout << " AHA Lets go with the first potion then!" << endl;
    cout << " We mix in the potion and give it to Mr. Nidhogg..."; // You finissh it!

}
void Sparkly_Wallbanger_2() {
    cout << " AHA Lets go with the second potion then!" << endl;
    cout << " We mix in the potion and give it to Mr. Nidhogg...";

}
void Fuzzy_Navel_3() {
    cout << " AHA Lets go with the third potion then!" << endl;
    cout << " We mix in the potion and give it to Mr. Nidhogg...";  

}
void Snake_wine_4() {
    cout << " AHA Lets go with the fourth potion then!" << endl;
    cout << " We mix in the potion and give it to Mr. Nidhogg...";
}