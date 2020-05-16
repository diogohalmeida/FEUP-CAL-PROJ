#include "src/Interface/menu.h"

int main() {
    cout << "Hello There! Welcome to ExploreIT!" << endl;
    cout << "Loading region maps..." << endl;
    vector<Graph> regions = readAllRegions();

    while (mainMenu(regions) != 0);

    cout << "Thank you for using ExploreIT! Have a great tour!" << endl;

	return 0;
}
