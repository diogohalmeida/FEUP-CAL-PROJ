#include "Graph.h"

/*
 * ================================================================================================
 * Class Edge
 * ================================================================================================
 */

Edge::Edge(int destID, double w) {
    this->destID = destID;
    this->weight = w;
}

int Edge::getDestID() const {return this->destID;}

double Edge::getWeight() const {return this->weight;}

void Edge::setID(int id) {this->destID = id;}

void Edge::setWeight(double w) {this->weight = w;}


/*
* ================================================================================================
* Class Vertex
* ================================================================================================
*/
Vertex::Vertex(int id, double x, double y) {
    this->x = x;
    this->y = y;
    this->id = id;
}

int Vertex::getID() const {return this->id;}

double Vertex::getX() const {return this->x;}

double Vertex::getY() const {return this->y;}

vector <Edge> Vertex::getAdj() const {return this->adj;}

bool Vertex::getVisited() const {return this->visited;}

void Vertex::setX(double x) {this->x = x;}

void Vertex::setY(double Y) {this->y = y;}

void Vertex::setVisited(bool visited) {this->visited = visited;}

string Vertex::getType() const {return this->type;}

void Vertex::setType(string type) {this->type = type;}

void Vertex::addEdge(const int &dest, double w) {
    Edge ed(dest, w);
    adj.push_back(ed);
}

void Vertex::setID(int id) {
    this->id = id;
}


/*
 * ================================================================================================
 * Class Graph
 * ================================================================================================
 */
Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getID() == id)
            return v;
    return nullptr;
}

bool Graph::addVertex(const int &id, const double &x, const double &y) {
    if (findVertex(id) != nullptr)
        return false;
    Vertex* toAdd = new Vertex(id, x, y);
    if (vertexSet.empty()) {
        this->minY = toAdd->getY();
        this->minX = toAdd->getX();
        this->maxX = toAdd->getX();
        this->maxY = toAdd->getY();
    }
    else {
        if(toAdd->getX() > maxX)
            maxX = toAdd->getX();
        else if(toAdd->getX() < minX)
            minX = toAdd->getX();
        if(toAdd->getY() > maxY)
            maxY = toAdd->getY();
        else if (toAdd->getY() < minY)
            minY = toAdd->getY();
    }
    vertexSet.push_back(toAdd);
    return true;
}

bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(dest,w);
    return true;
}

bool Graph::addBiDirEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(dest,w);
    v2->addEdge(sourc, w);
    return true;
}

vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

double Graph::getMaxX() {
    return this->maxX;
}

double Graph::getMinX() {
    return this->minX;
}

double Graph::getMaxY() {
    return this->maxY;
}

double Graph::getMinY() {
    return this->minY;
}
