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
    cout << "The clerk at the front seems like they'd rather be anywhere but here so, you figure a little bit of conversation wouldn't hurt." << endl; 
    cout << "You walk up to them their six eyes immediately lock on your figure." << endl;
    cout << " 'Welcome to Galatic Grab-N-Go The best pitstop on this side of the galaxy. How may I help you?' They drawl out boredly." << endl;
    cout << "What do you ask them?" << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Ask if they're hiring" << endl;
    cout << "  2. Ask about the strange noises from the back room" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { end_job();   }
    else if (2 == choice) { end_rumor(); }
    else                  { bad_choice(); choice_clerk(); }
}

void choice_leave() {
    cout << "\n-- OUTSIDE --" << endl;
    cout << "Looking around the store the colors begin to blur your vision." << endl; 
    cout << "It's honestly really overwhelming and after being in a dark room for hours it's way too much." << endl; 
    cout << "So you turn back around and leave the store needing to take a second to breathe." << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Investigate the alley" << endl;
    cout << "  2. Forget it and take shelter back inside" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { end_alley(); }
    else if (2 == choice) { main_menu();    }   // loops back
    else                  { bad_choice(); choice_leave(); }
}

// ──────────────────────────────────────────────────────────────
//  LEVEL 2 – BROWSE PATH
// ──────────────────────────────────────────────────────────────
void choice_snacks() {
    cout << "\n-- SNACK AISLE --" << endl;
    cout << "You decide to head towards the snack aisle. It's why you went on this little excursion in the first place." << endl; 
    cout << "Everything looks so good on an empty stomach so you aren't sure what to get at first. Suddenly your eyes lock on two food items." << endl;
    cout << "One is a neon green hot dog with... TOOTHPASTE FLAVORED CONDIMENTS!?! And the second one is an unassuming can of Corn Crisps." << endl; 
    cout << "It's a little dented and the drawing on the front is faded around the edges." << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Grab the neon green hot dog" << endl;
    cout << "  2. Take the unassuming can of Corn Crisps" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { end_poisoned();   }
    else if (2 == choice) { end_snack_rich();  }
    else                  { bad_choice(); choice_snacks(); }
}

void choice_gadgets() {
    cout << "\n-- GADGET CASE --" << endl;
    cout << "You decide to head towards the gadgets setion of the store. A little pit stop wouldn't hurt before you get back to your work." << endl;
    cout << "There is all types of toys and elctronics around this aisle but your eyes immediately land on a sword that looked like it was carved out of a lava lamp." << endl; 
    cout << "There's liquid floating all around the inside of the blade and the hilt is a gleaming gold." << endl;
    cout << "Looking at the price you can see it would be a bit out of your budget if you get a snack on top of this." << endl;
    cout << "\nDo you:" << endl;
    cout << "  1. Attempt to slip it into your pants" << endl;
    cout << "  2. Walk away -- it's not worth the risk" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if      (1 == choice) { end_steal(); }
    else if (2 == choice) {
        cout << "\nSmart call. You go back to browsing." << endl;
        choice_browse();
    }
    else { bad_choice(); choice_gadgets(); }
}

void end_steal() {
    cout << "\n-- THE THEFT --" << endl;
    cout << "The clerk isn't paying any attention to you so you do one last check around and stuff the sword in the leg of your pants." << endl; 
    cout << "It's an uncomfortable fit but you got your sword and all you have to do is walk out. " << endl;
    cout << "Doing an awkward shuffle towards the front door you feel the sword slip towards your ankle and you panic grabbing at your pants leg when the blade slide out and hits the ground with a TWANG." << endl; 
    cout << "Immediately a bright portal opens up under you and you fall striaght through." << endl;
    cout << "\n[GAME OVER - Bad Ending]" << endl;
    cout << "(You are stuck falling through the eternal universe" << endl;
    cout << " with no way out. You didn't even get your snack..." << endl;
    cout << " Good going, klutz.)" << endl;
}

// ──────────────────────────────────────────────────────────────
//  LEVEL 2 – CLERK PATH
// ──────────────────────────────────────────────────────────────
void end_job() {
    cout << "\n-- ASKING ABOUT WORK --" << endl;
    cout << "You ask about the job posting that was taped on the front window of the store." << endl;
    cout << "'Oh that old thing? The old manager actually put it up before he left three years ago but nobody really pays it any mind.'" << endl; 
    cout << "'Which is kind of a drag because this place has great benefits. A flexible schedule, dental, health, pet dragon, and car insurance. A 401k and PTO.'" << endl; 
    cout << "'Were you interested in the job or just asking?'" << endl;
    cout << "You decide that you want the job after hearing all the job has to offer. The clerk holds out his hand to seal the deal and get your paper work started." << endl; 
    cout << "As soon as your hands make contact his head combusts into flame and a demonic voice calls from somwhere in the flames." << endl;
    cout << "KEHAHAHAHA YOU FOOL YOU HAVE DAMNED YOURSELF TO ETERNAL SERVITUDE TO THIS CONVENIENCE STORE KEHAHAHA *cough* *cough* would you like your paychecks in a stub or direct deposit?" << endl;
    cout << "\n[GAME OVER - Bad Ending]" << endl;
    cout << "(Eternal servitude. Not the worst gig -- great dental." << endl;
    cout << " But you're not allowed to eat from the store..." << endl;
    cout << " So you didn't get your snack.)" << endl;

}

void end_rumor() {
    cout << "\n-- THE RUMORS --" << endl;
    cout << "You ask about a fight club that you've heard was held here. The clerk gives you a mean glare and comes from around the corner to get face to face." << endl; 
    cout << "You didn't realize it because he was sitting but he's at least three heads taller than you are with a mean glare on his face." << endl;
    cout << "'What did you say? Repeat what you just said.'" << endl; 
    cout << "He practically yells at you. Before you can get out the statement again he hits you with a flying uppercut and it's light out almost immediately." << endl;
    cout << "\n[GAME OVER - Bad Ending]" << endl;
    cout << "(We've been over this -- what's the first rule of" << endl;
    cout << " fight club? You didn't even get a chance to" << endl;
    cout << " get your snack.)" << endl;
}

// ──────────────────────────────────────────────────────────────
//  LEVEL 2 – LEAVE PATH
// ──────────────────────────────────────────────────────────────
void end_alley() {
    cout << "\n-- THE ALLEY --" << endl;
    cout << "Walking out of the store and heading into a dim alley you put your hands on your knees and take a second to catch your breath." << endl; 
    cout << "Suddenly you hear mumbling to your right and being the noisy person you are you peak around the corner to cyborg trying to rob a fellow robot for a pack of ratchets." << endl;
    cout << "'GIVE IT TO ME MAN MY BOLTS NEED TIGHTENING ITS BEEN TO LONG AND YOU TOOK THE LAST PACK!'" << endl; 
    cout << "Knowing this could be the difference between artificial life or the scrapyard you jump into the fray knocking the cybord against the head with a spare tire you found on the ground." << endl; 
    cout << "He crumples to the ground and the other robot takes that chance to thank you and run for his life clanking away for the scene." << endl;
    cout << "The clerk chose this time to reveal himself from the side of the store. He adits that he was hiding hoping someone would come to the robots aid." << endl; 
    cout << "He gives you a soda and a bag of chips for your bravery." << endl;
    cout << "\n[GAME OVER - Good Ending]" << endl;
    cout << "(You're practically a hero -- the 'Rust Buster' if you" << endl;
    cout << " will. And hey, look at that, you got your snack!)" << endl;
}

// ──────────────────────────────────────────────────────────────
//  ENDINGS
// ──────────────────────────────────────────────────────────────
void end_poisoned() {
    cout << "You decide to go with the neon green hotdog. Going up to the counter you get the clerk at the front to ring up your order and he gives you an odd look as he does." << endl; 
    cout << "Walking out the store you take a bite of the hotdog. It's overly moist and minty in all the wrong ways and you regret your choice almost immediately." << endl;
    cout << "Suddenly your eyes start to water, your stomach flips, and you pass out on the second bite." << endl;
    cout << "\n*** ENDING: WRONG SNACK ***" << endl;
    cout << "(You were posioned. You were pushing your luck with the second bite...)" << endl;
    cout << "\n[GAME OVER - Bad Ending]" << endl;
}

void end_snack_rich() {
    cout << "You decide to go with the can of Corn Crisps. You grab your purchase and go up to the clerk to get rung up." << endl; 
    cout << "When you get to the counter there is another customer there speaking to the clerk. He has a monocle on with a long and majestic purple beard." << endl; 
    cout << "His one eye tracks your hand as you place the can on the counter and widens significantly when the entire can is shown completely." << endl;
    cout << "'MADAM I DARE SAY MADAM DO YOU REALIZE WHAT THAT IS?'" << endl; 
    cout << "He practially spits out towards you. You wipe your face off with a napkin the clerk hands you and shake your head." << endl;
    cout << "'THAT THERE I DARE SAY IS A RARE YEAR 1834 CAN OF CRISPS HAILING FROM THE UNIVERSE OF CRISPCANNINESS! IT'S WORTH MILLIONS AND I JUST HAPPEN TO HAVE A MILLION DOLLARS ON MY PERSON IN EXACT CHANGE.'" << endl; 
    cout << "'COULD I BUY THAT RARE YEAR 1865 CAN OF CRISPS HAILING FROM THE UNIVERSE OF CRISPCANNINESS FROM YOU?'" << endl;
    cout << "Ignoring his strange verbiage you agree to his deal and trade him for the crisps for a the money he convenietly had." << endl;
    cout << "\n*** ENDING: RARE FIND ***" << endl;
    cout << "You went out for a late night snack and becaame a millionare...Good for you I guess. You're still kinda hungry though." << endl;
    cout << "\n[GAME OVER - Decent Ending]" << endl;
}

void end_dont_steal() {
    cout << "You decide to suck it up and go for the sword forgoing your snack. You go up to the clerk prepared to spend money that you have on an item you really don't need." << endl; 
    cout << "By the time you get to the counter you're honestly questioning whether or not you really want the sword." << endl;
    cout << "The clerk stares at you then the sword and back again a few times with a strange look in his eyes." << endl; 
    cout << "'Are you sure you want this sword?'" << endl;
    cout << "You nod your ead relunctantly. You're already up here might as well buy the thing." << endl; 
    cout << "When you nod your head at him a bright light shines from his thrid eye temporarily blinding you." << endl; 
    cout << "When your eyesight clears you see that the clerk has turned into...A GLOWING CASH REGISTER???" << endl;
    cout << "'THE SWORD HAS CHOSEN YOU IN DEBT STUDENT...I have no reason why BUT NEEDLESS THE FATE OF THE GALAXY AND THIS STORE NOW LIES IN YOUR HANDS.'" << endl; 
    cout << "'USE THIS SWORD AND YOUR STRENGTH AND KEEP OUR UNIVERSE SAFE FOR THE FORSEEABLE FUTURE!'" << endl;
    cout << "\n*** ENDING: REALITY SHIFT ***" << endl;
    cout << "(You were entrusted the universe and ownership of the store. You never actually agreed to any of it but it's okay...You never got your snack though.)" << endl;
}