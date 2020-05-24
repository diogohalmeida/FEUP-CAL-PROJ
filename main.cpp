#include "src/Interface/menu.h"




int main() {
    cout << "Hello There! Welcome to ExploreIT!" << endl;
    cout << "Loading region maps..." << endl;
    //Read region data from files
    vector<Graph<coordinates>> regions = readAllRegions();
    Graph<coordinates> region = regions.at(1);


    //Main menu call
    while (mainMenu(regions) != 0);


    cout << "Thank you for using ExploreIT! Have a great tour!" << endl;


	return 0;
}
