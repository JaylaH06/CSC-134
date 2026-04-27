/* 
CSC 134
Jayla Harper
M7T1 - Restaurant Rating Program
04/27/26
*/

#include <iostream>
using namespace std;

class Restaurant {
    private:
    string name; // name of the place
    double rating; // 1-5 stars, including half stars

    public:
    Restaurant(string n, double r) {
        // Constructor -- makes new object
        name = n;
        rating = r;
    }
    // Getters and Setters
    void setName(string n) {
        name = n;
    }
    void setRating(double r) {
        rating = r;
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }

};

int main() {

    cout << "Restaurant Reviews" << endl;

    // Create one restaurant
    Restaurant rest1 = Restaurant("Mi Casita", 4.0);
    cout << rest1.getName() << endl;
    cout << rest1.getRating() << endl;
   

    // Make another using user input
    Restaurant rest2 = Restaurant("", 0.0);
    string n;
    double r;
    cout << "Enter Restaurant Name: ";
    cin >> n;
    cout << "Rating (1.0 - 5.0): ";
    cin >> r;
    rest2.setName(n);
    rest2.setRating(r);
    cout << rest2.getName() << endl;
    cout << rest2.getRating() << endl;

}