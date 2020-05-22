#include "src/Interface/menu.h"




int main() {
    cout << "Hello There! Welcome to ExploreIT!" << endl;
    cout << "Loading region maps..." << endl;
    vector<Graph<coordinates>> regions = readAllRegions();
    Graph<coordinates> region = regions.at(1);

    while (mainMenu(regions) != 0);

    /*
    for (int i: regions.at(1).dijkstraShortestPath(8116, 1).getPath()){
        cout << i << endl;
    }
     */
    cout << "Thank you for using ExploreIT! Have a great tour!" << endl;

    // 8116 - 9074


    getchar();

	return 0;
}
