#include "verifications.h"

//Used to check valid names
void verifyAllLetters(string &aux) {
    string alphabet = "abcdefghijklmnopqrstuvwxyzãáàâçéêíõóôúüÃÁÀÂÇÉÊÍÕÓÔÚÜ";
    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            isValid = true;
            stringFormatting(aux);
            for (int i = 0; i < aux.size(); i++) {
                if (!isLetter(aux[i]) && (aux[i] != ' ')) {
                    isValid = false;
                    break;
                }
            }
        }

        if (!isValid) {
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }

}

//Used to check menu inputs
void verifyMenuOptions(int &option, int omin, int nmax){
    cin >> option;
    while (cin.fail() || option > nmax || option < omin) {
        if (cin.eof()) { //caso de ter sido introduzido o 'crtl-z'
            cin.clear();
            cout << "Invalid input, please insert a valid one: ";
            cin >> option;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, please insert a valid one: ";
            cin >> option;
        }
    }
}