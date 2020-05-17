#ifndef EXPLOREIT_MENU_H
#define EXPLOREIT_MENU_H

#include <iostream>
#include "../src/Utils/verifications.h"
#include "../Graph/Graph.h"
#include "../Utils/readFileGraph.h"
#include "GraphDisplay.h"
#include "../Client/Worker.h"

using namespace std;

int tourMenu(vector<Graph> regions);

int displayMenu(vector<Graph> regions);

int mainMenu(vector<Graph> regions);



#endif //EXPLOREIT_MENU_H
