#ifndef EXPLOREIT_READFILEGRAPH_H
#define EXPLOREIT_READFILEGRAPH_H

#include <string>
#include <fstream>
#include "utils.h"
#include "../Graph/Graph.h"

vector<Graph<coordinates>> readAllRegions();

Graph<coordinates> readGraph(string city);

void readNodes(Graph<coordinates> &graph, string city);

void readEdges(Graph<coordinates> &graph, string city);



#endif //EXPLOREIT_READFILEGRAPH_H
