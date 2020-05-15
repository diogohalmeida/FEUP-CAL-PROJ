#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
 * ================================================================================================
 * Class Edge
 * ================================================================================================
 */
class Edge{
private:
    int destID;
    double weight;

public:
    Edge(int destID, double w);
    int getDestID() const;
    double getWeight() const;
    void setID(int id);
    void setWeight(double w);
};


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
    bool visited;

public:
    double distance(Vertex* v2);
    Vertex(int id, double x, double y);
    int getID() const;
    void setID(int id);
    double getX() const;
    double getY() const;
    string getTag() const;
    vector <Edge> getAdj() const;
    bool getVisited() const;

    void setX(double x);
    void setY(double Y);
    void setTag(string tag);
    void setVisited(bool visited);
    void addEdge(const int &dest, double w);

};


/*
 * ================================================================================================
 * Class Graph
 * ================================================================================================
 */
class Graph{
    vector <Vertex*> vertexSet;
    double maxX;
    double minX;
    double maxY;
    double minY;

public:
    vector <Vertex*> getVertexSet() const;
    bool addVertex(const int &id, const double &x, const double &y);
    bool addEdge(const int &sourc, const int &dest, double w);
    Vertex * findVertex(const int &id) const;
    double getMaxX();
    double getMinX();
    double getMaxY();
    double getMinY();
};


#endif //GRAPH_H_