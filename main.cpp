#include <cstdio>
#include "src/Interface/menu.h"

int main() {
    cout << "Hello There! Welcome to ExploreIT!" << endl << endl;
    Sleep(1000);
    while  (mainMenu() != 0);

    cout << "Thank you for using ExploreIT! Have a great tour!" << endl;

	return 0;
}
