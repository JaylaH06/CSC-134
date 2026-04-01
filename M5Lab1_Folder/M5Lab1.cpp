// M5LAb1
// CSC 134 - M5LAB1 Choose Your Own Adventure
// Galactic Grab-N-Go: A Sci-Fi Convenience Store
// Jayla Harper
// 04/01/26

#include <iostream>
#include "M5Lab1.h"
using namespace std;

// ──────────────────────────────────────────────────────────────
//  HELPER: clears bad input and re-prompts
// ──────────────────────────────────────────────────────────────
static void bad_choice() {
    cout << ">> Invalid choice. Try again." << endl;
    cin.clear();
    cin.ignore(1000, '\n');
}

// ──────────────────────────────────────────────────────────────
//  MAIN MENU
// ──────────────────────────────────────────────────────────────
void main_menu() {
    cout << "You currently reside in the Andromeda Galaxy. 2.5 million light years away from your old home in the Milky Way." << endl; 
    cout << "Moving away for college was a difficult choice, but you don't regret it." << endl;
    cout << "But reminiscing isn't your concern right now it's the grumbling of your stomach that poses a problem. So with a virtually empty stomach you get up from your desk and make your way downstairs and out the door." << endl;
    cout << "The night air is cool and the sky is clear filled to the brim with beautiful stars of all shapes and sizes. It makes for a great mind cleanser after hours of studying for your latest test." << endl; 
    cout << "Before you realize it you come up to a convenience store it reads: " << endl;
    cout << "\n========================================" << endl;
    cout << " GALACTIC GRAB-N-GO  *  Est. 2347 CE" << endl;
    cout << "========================================" << endl;
    cout << "You enter " << "Galatic Grab-N-Go." << "The store is teeming with items from all over the galaxy. Bright colors swarm your vision, basically calling your attention." << endl; 
    cout << "What should you do?" << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Browse the shelves" << endl;
    cout << "  2. Talk to the alien clerk" << endl;
    cout << "  3. Leave the store" << endl;
    cout << "  4. [Quit]" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { choice_browse(); }
    else if (2 == choice) { choice_clerk();  }
    else if (3 == choice) { choice_leave();  }
    else if (4 == choice) { cout << "\n>> Powering down terminal. Goodbye." << endl; return; }
    else                  { bad_choice(); main_menu(); }
}

// ──────────────────────────────────────────────────────────────
//  LEVEL 1
// ──────────────────────────────────────────────────────────────
void choice_browse() {
    cout << "\n-- SHELVES --" << endl;
    cout << "You decide to browse the store. It's covered in a wide range of items. From the latest gadgets to the most popular snacks." << endl; 
    cout << "Seeing all that the store has to offer makes you momentarily forget about your stomach. So much to see and so little time." << endl; 
    cout << "What should you take a look at first?" << endl;
    cout << "\nDo you head to the:" << endl;
    cout << "  1. Snack aisle (lots of unlabeled pouches)" << endl;
    cout << "  2. Gadget display case" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { choice_snacks();  }
    else if (2 == choice) { choice_gadgets(); }
    else                  { bad_choice(); choice_browse(); }
}

void choice_clerk() {
    cout << "\n-- THE CLERK --" << endl;
    cout << "The clerk is a six-armed Veluvian. She's reading" << endl;
    cout << "four datapads simultaneously and ignores you." << endl;
    cout << "You clear your throat." << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Ask if they're hiring" << endl;
    cout << "  2. Ask about the strange noises from the back room" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { choice_job();   }
    else if (2 == choice) { choice_rumor(); }
    else                  { bad_choice(); choice_clerk(); }
}

void choice_leave() {
    cout << "\n-- OUTSIDE --" << endl;
    cout << "You push through the door into the acid rain." << endl;
    cout << "Your jacket hisses. Across the street, a narrow" << endl;
    cout << "alley glows faintly orange." << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Investigate the glowing alley" << endl;
    cout << "  2. Forget it and take shelter back inside" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { choice_alley(); }
    else if (2 == choice) { main_menu();    }   // loops back
    else                  { bad_choice(); choice_leave(); }
}

// ──────────────────────────────────────────────────────────────
//  LEVEL 2 – BROWSE PATH
// ──────────────────────────────────────────────────────────────
void choice_snacks() {
    cout << "\n-- SNACK AISLE --" << endl;
    cout << "Hundreds of unlabeled foil pouches line the shelf." << endl;
    cout << "One smells incredible. Another pulses with a faint light." << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Grab the incredible-smelling one and eat it now" << endl;
    cout << "  2. Take the glowing one to examine it more carefully" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { end_poisoned();   }
    else if (2 == choice) { end_snack_rich();  }
    else                  { bad_choice(); choice_snacks(); }
}

void choice_gadgets() {
    cout << "\n-- GADGET CASE --" << endl;
    cout << "Under scratched glass sits a device the size of" << endl;
    cout << "a deck of cards. The tag reads: PHASE SHIFTER - 4,200 CR." << endl;
    cout << "You have 12 credits." << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Attempt to slip it into your pocket" << endl;
    cout << "  2. Walk away -- it's not worth the risk" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { choice_steal(); }
    else if (2 == choice) {
        cout << "\nSmart call. You go back to browsing." << endl;
        choice_browse();
    }
    else { bad_choice(); choice_gadgets(); }
}

void choice_steal() {
    cout << "\n-- THE THEFT --" << endl;
    cout << "Your hand slides under the case lid..." << endl;
    cout << "A proximity sensor SCREAMS. A security drone" << endl;
    cout << "drops from the ceiling. Time slows." << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Run for the door" << endl;
    cout << "  2. Hit the activation button on the device -- whatever it does" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { end_caught_stealing(); }
    else if (2 == choice) { end_gadget_works();    }
    else                  { bad_choice(); choice_steal(); }
}

// ──────────────────────────────────────────────────────────────
//  LEVEL 2 – CLERK PATH
// ──────────────────────────────────────────────────────────────
void choice_job() {
    cout << "\n-- ASKING ABOUT WORK --" << endl;
    cout << "The clerk puts down two datapads. That's progress." << endl;
    cout << "She looks you over with three of her four eyes." << endl;
    cout << "\n\"You know how to run a plasma mop?\"" << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Lie and say yes" << endl;
    cout << "  2. Admit you have no idea but are a fast learner" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { end_arrested(); }   // plasma mop disaster
    else if (2 == choice) { end_hired();    }
    else                  { bad_choice(); choice_job(); }
}

void choice_rumor() {
    cout << "\n-- THE RUMORS --" << endl;
    cout << "The clerk's four eyes dart to the back door." << endl;
    cout << "\"Keep your voice down,\" she hisses." << endl;
    cout << "\"There's a smuggler ring using our stockroom." << endl;
    cout << " If you tell anyone, you're in danger.\"" << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Promise to keep quiet and leave quickly" << endl;
    cout << "  2. Tell her you'll help her report them" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { end_arrested(); }   // smugglers saw you listening
    else if (2 == choice) { end_hero();     }
    else                  { bad_choice(); choice_rumor(); }
}

// ──────────────────────────────────────────────────────────────
//  LEVEL 2 – LEAVE PATH
// ──────────────────────────────────────────────────────────────
void choice_alley() {
    cout << "\n-- THE ALLEY --" << endl;
    cout << "The orange glow comes from a crashed courier drone." << endl;
    cout << "Its cargo container is cracked open." << endl;
    cout << "Inside: medical supplies tagged for a refugee shelter." << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Take what you can carry -- finders keepers" << endl;
    cout << "  2. Call the shelter's emergency line on your comms" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { end_arrested(); }   // surveillance cameras everywhere
    else if (2 == choice) { end_hero();     }
    else                  { bad_choice(); choice_alley(); }
}

// ──────────────────────────────────────────────────────────────
//  ENDINGS
// ──────────────────────────────────────────────────────────────
void end_poisoned() {
    cout << "\n*** ENDING: WRONG SNACK ***" << endl;
    cout << "The pouch contains Grelthuun fermented paste." << endl;
    cout << "It's a delicacy on three moons and lethal to" << endl;
    cout << "your exact species. You wake up in a med-bay" << endl;
    cout << "three days later, 800 credits poorer." << endl;
    cout << "\n[GAME OVER - Bad Ending]" << endl;
}

void end_snack_rich() {
    cout << "\n*** ENDING: RARE FIND ***" << endl;
    cout << "The glowing pouch turns out to be Starbloom Pollen --" << endl;
    cout << "banned in six systems, worth 50,000 credits to a" << endl;
    cout << "collector. You quietly buy it for 3 credits and" << endl;
    cout << "never have to work again." << endl;
    cout << "\n[GAME OVER - Good Ending]" << endl;
}

void end_hired() {
    cout << "\n*** ENDING: NEW LIFE ***" << endl;
    cout << "The clerk -- her name is Zyveth -- respects honesty." << endl;
    cout << "You spend the next year learning every weird item" << endl;
    cout << "in the store. Eventually, she makes you assistant manager." << endl;
    cout << "\n[GAME OVER - Good Ending]" << endl;
}

void end_arrested() {
    cout << "\n*** ENDING: ARRESTED ***" << endl;
    cout << "Galactic Enforcement Officers materialize from" << endl;
    cout << "nowhere. Your record now includes a mark you'll" << endl;
    cout << "be explaining for decades." << endl;
    cout << "\n[GAME OVER - Bad Ending]" << endl;
}

void end_hero() {
    cout << "\n*** ENDING: UNLIKELY HERO ***" << endl;
    cout << "Your tip leads to the bust of a major smuggling ring." << endl;
    cout << "The reward covers your shuttle fare to the next" << endl;
    cout << "system -- and Zyveth gives you a lifetime discount." << endl;
    cout << "\n[GAME OVER - Good Ending]" << endl;
}

void end_caught_stealing() {
    cout << "\n*** ENDING: CAUGHT ***" << endl;
    cout << "The drone is faster than you. A stun field drops you" << endl;
    cout << "before you reach the door. You explain yourself to" << endl;
    cout << "Galactic Enforcement for the next six hours." << endl;
    cout << "\n[GAME OVER - Bad Ending]" << endl;
}

void end_gadget_works() {
    cout << "\n*** ENDING: PHASE SHIFT ***" << endl;
    cout << "You flicker out of phase for 0.3 seconds." << endl;
    cout << "The drone passes through you harmlessly." << endl;
    cout << "You re-materialize, set the device on the counter," << endl;
    cout << "and walk out. The clerk saw everything and says nothing." << endl;
    cout << "\n[GAME OVER - Neutral Ending]" << endl;
}