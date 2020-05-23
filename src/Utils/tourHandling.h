#ifndef EXPLOREIT_TOURHANDLING_H
#define EXPLOREIT_TOURHANDLING_H

#include "../Graph/Graph.h"
#include <time.h>
#include "../Client/Worker.h"

vector<Path> tourGenerator(Graph<coordinates> graph, vector<Worker> workers, int single);
void givePathsToWorkers(vector<Worker> & workers, vector<Path> paths);


#endif //EXPLOREIT_TOURHANDLING_H
