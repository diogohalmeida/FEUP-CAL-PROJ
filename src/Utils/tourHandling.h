#ifndef EXPLOREIT_TOURHANDLING_H
#define EXPLOREIT_TOURHANDLING_H

#include "../Graph/Graph.h"
#include <time.h>
#include "../Client/Worker.h"

vector<Path> tourGenerator(Graph<coordinates> graph, vector<Worker> workers);



#endif //EXPLOREIT_TOURHANDLING_H
