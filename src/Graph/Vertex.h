#ifndef EXPLOREIT_VERTEX_H
#define EXPLOREIT_VERTEX_H

#include <string>
#include <vector>
#include <cmath>
#include "Edge.h"


/*
* ================================================================================================
* Class Vertex
* ================================================================================================
*/
class Vertex{
private:
    int id;
    double x, y; //coordenadas
    string tag;
    vector<Edge> adj;

public:
    double distance(Vertex* v2);
    Vertex(int id, double x, double y);
    int getID() const;
    void setID(int id);
    double getX() const;
    double getY() const;
    string getTag() const;
    vector <Edge> getAdj() const;

    void setX(double x);
    void setY(double Y);
    void setTag(string tag);
    void addEdge(const int &dest, double w, int difficulty);

};



#endif //EXPLOREIT_VERTEX_H
