// CSC 13
// M1HW1- Movie Talk
// 01/21/26
// Jayla Harper

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string movie_name = "Ponyo";
    int movie_year = 2008;
    double movie_gross = 206.5;

    cout << "The movie I picked is called " << movie_name << endl;
    cout << "It was made in " << movie_year << endl;
    cout << "The total amount of money made was " << movie_gross << " billion" << endl;

    cout << setprecision(2) << fixed;
    
    cout << "My favorite quote from the movie is, 'I'll always love Ponyo whether she's a fish, a human... or in between.'" << endl;
    cout << "My favorite scene is when Ponyo runs up to Sosuke on the bridge and hugs him after changing into a human girl" << endl;
    cout << "One fun fact is that the movie was made with zero CGI usage" << endl;
    cout << "Another fun fact is that the seaside town that 'Ponyo' takes place in is based on an actual town called Tomonoura in Japan" << endl;

}
