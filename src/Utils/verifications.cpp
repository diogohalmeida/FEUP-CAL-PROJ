#include "verifications.h"

void verifyMenuOptions(int &option, int omin, int nmax){
    cout << endl << "Choose an option from the menu (integer number): ";
    cin >> option;
    while (cin.fail() || option > nmax || option < omin) {
        if (cin.eof()) { //caso de ter sido introduzido o 'crtl-z'
            cin.clear();
            cout << "Invalid operation, please insert a valid one: ";
            cin >> option;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid operation, please insert a valid one: ";
            cin >> option;
        }
    }
}