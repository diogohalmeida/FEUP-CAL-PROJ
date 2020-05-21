#include "Vertex.h"

/*
* ================================================================================================
* Class Vertex
* ================================================================================================
*/
Vertex::Vertex(int id, double x, double y) {
    this->x = x;
    this->y = y;
    this->id = id;
    this->tag = "";
}

int Vertex::getID() const {return this->id;}

double Vertex::getX() const {return this->x;}

double Vertex::getY() const {return this->y;}

vector <Edge> Vertex::getAdj() const {return this->adj;}

void Vertex::setX(double x) {this->x = x;}

void Vertex::setY(double Y) {this->y = y;}


string Vertex::getTag() const {return this->tag;}

void Vertex::setTag(string tag) {this->tag = tag;}

void Vertex::addEdge(const int &dest, double w, int difficulty) {
    Edge ed(dest, w, difficulty);
    adj.push_back(ed);
}

void Vertex::setID(int id) {
    this->id = id;
}

double Vertex::distance(Vertex *v2) {
    double x = this->getX() - v2->getX();
    double y = this->getY() - v2->getY();
    double result = sqrt(pow(x,2) + pow(y,2));
    return result;
}