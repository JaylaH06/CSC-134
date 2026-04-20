/*
CSC 134
Jayla Harper
M6Lab1 - Arrays
04/20/26
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms
enum Room {
    BASEMENT = 0,
    KITCHEN = 1,
    LIVING_ROOM = 2,
    MASTER_BEDROOM = 3,
    BATHROOM = 4,
    ATTIC = 5,
    FRONT_DOOR = 6,
    NUM_ROOMS = 7
};

int main() {
    // Room names array
    string roomNames[NUM_ROOMS] = {
        "Basement",
        "Kitchen",
        "Living Room",
        "Master Bedroom",
        "Bathroom",
        "Attic",
        "Front Door"
    };

    // Room descriptions array
    string roomDescriptions[NUM_ROOMS] = {
        "A dark and damp basement. You can hear the sound of rats surrying.",
        "A kitchen with the putrid smell of old meat.",
        "A rather dull looking room with a fireplace... Are those bones inside the fireplace?",
        "A spacious master bedroom with a king-sized bed.",
        "A clean bathroom with a shower.",
        "A dusty attic filled with old boxes.",
        "The front door leading outside."
    };
}