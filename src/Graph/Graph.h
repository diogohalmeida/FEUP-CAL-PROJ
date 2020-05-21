#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Path.h"

/*
 * ================================================================================================
 * Class Graph
 * ================================================================================================
 */
class Graph{
    vector <Vertex*> vertexSet;
    string region;
    double maxX;
    double minX;
    double maxY;
    double minY;

public:
    vector <Vertex*> getVertexSet() const;
    bool addVertex(const int &id, const double &x, const double &y);
    bool addEdge(const int &sourc, const int &dest, int difficulty);
    Vertex * findVertex(const int &id) const;
    double getMaxX();
    double getMinX();
    double getMaxY();
    double getMinY();
    string getRegion() const;
    void setRegion(string region);
    vector<Path> getAllPaths(int source, int destination);
    void dfsVisit(int u, int d, bool visited[], int sequence[], int &index, vector<Path> & result);
};


#endif //GRAPH_H_