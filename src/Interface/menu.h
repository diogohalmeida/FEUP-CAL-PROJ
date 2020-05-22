#ifndef EXPLOREIT_MENU_H
#define EXPLOREIT_MENU_H

#include <iostream>
#include "../src/Utils/verifications.h"
#include "../Graph/Graph.h"
#include "../Utils/readFileGraph.h"
#include "../Utils/tourHandling.h"
#include "GraphDisplay.h"
#include "../Client/Worker.h"

int tourMenu(vector<Graph<coordinates>> regions);

int displayMenu(vector<Graph<coordinates>> regions);

int mainMenu(vector<Graph<coordinates>> regions);



#endif //EXPLOREIT_MENU_H
