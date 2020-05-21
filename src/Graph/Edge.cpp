#include "Edge.h"


/*
 * ================================================================================================
 * Class Edge
 * ================================================================================================
 */

Edge::Edge(int destID, double w, int difficulty) {
    this->destID = destID;
    this->weight = w;
    this->difficulty = difficulty;
}

int Edge::getDestID() const {return this->destID;}

double Edge::getWeight() const {return this->weight;}

void Edge::setID(int id) {this->destID = id;}

void Edge::setWeight(double w) {this->weight = w;}

int Edge::getDifficulty() const {
    return difficulty;
}

void Edge::setDifficulty(int difficulty) {
    this->difficulty = difficulty;
}
