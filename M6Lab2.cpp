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
        "A dark and damp basement. You can hear the sound of rats scurrying. Your head feels heavy and you can't remeber how you got here. You just know that you need to get out.",
        "A kitchen with the putrid smell of raw meat. The counters are covered in blood and there are strange symbols on the walls.",
        "A rather dull looking room with a fireplace... And is that bones inside the fireplace?",
        "A spacious master bedroom with a king-sized bed. Pictures of smiling people are hung up all over the walls.There's a closet in the corner but it's locked.",
        "A relatively clean bathroom with a shower. There's a multitude of cleaning supplies on the shelves, none that you recognize but they should come in handy.",
        "A dusty attic filled with old boxes. Cobwebs cover the corner's and the floor creaks with every step. You can see a faint light coming from one of the boxes.",
        "The front door leading outside. It's bolted shut with three heavy duty locks and a chain. You can see sunlight peeking through the crracks in the door."
    };


    // Adjacency list using a 2D array
    // Connections[from_room][direction] = to_room or -1 if no connections
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // Initialize all connections to -1 (no connection)
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }
}