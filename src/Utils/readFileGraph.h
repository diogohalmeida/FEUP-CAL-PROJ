#ifndef EXPLOREIT_READFILEGRAPH_H
#define EXPLOREIT_READFILEGRAPH_H

#include <string>
#include <fstream>
#include "utils.h"
#include "../Graph/Graph.h"

using namespace std;

Graph readGraph(string city);

void readNodes(Graph &graph, string city);

void readEdges(Graph &graph, string city);

void readTags(Graph &graph, string city);


#endif //EXPLOREIT_READFILEGRAPH_H
