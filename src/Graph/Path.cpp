#include <algorithm>
#include "Path.h"

Path::Path() {
    this->path = {};
    this->max_difficulty = 0;
    this->distance = 0;
    this->maxX = 0;
    this->maxY = 0;
    this->minX = 0;
    this->minY = 0;

}

void Path::addVertex(Vertex *vertex) {
    if (path.empty()) {
        this->minY = vertex->getY();
        this->minX = vertex->getX();
        this->maxX = vertex->getX();
        this->maxY = vertex->getY();
    }
    else {
        if(vertex->getX() > maxX)
            maxX = vertex->getX();
        else if(vertex->getX() < minX)
            minX = vertex->getX();
        if(vertex->getY() > maxY)
            maxY = vertex->getY();
        else if (vertex->getY() < minY)
            minY = vertex->getY();
    }
    this->path.push_back(vertex);
}

vector<Vertex *> Path::getPath() const {
    return this->path;
}

void Path::clear() {
    path.clear();
}

void Path::addDistance(double distance) {
    this->distance += distance;
}

double Path::getDistance() const {
    return this->distance;
}

void Path::verifyDifficulty(int max_difficulty) {
    if (max_difficulty > this->max_difficulty){
        this->max_difficulty = max_difficulty;
    }
}


void Path::display() {
    int width = 1280;
    int height = 720;
    GraphViewer *gv = new GraphViewer(width, height, false);
    gv->createWindow(width, height);


    double yPercent, xPercent;

    for (Vertex *vertex: this->path) {
        if (maxY - minY != 0) {
            yPercent = 1.0 - ((vertex->getY() - this->minY) / (this->maxY - this->minY) * 0.9 + 0.05);
        }
        else{
            yPercent = 1;
        }
        if (maxX - minX != 0) {
            xPercent = (vertex->getX() - this->minX) / (this->maxX - this->minX) * 0.9 + 0.05;
        }
        else{
            xPercent = 1;
        }

        if (vertex->getTag() == "restaurant" || vertex->getTag() == "cafe" || vertex->getTag() == "pub" ||
            vertex->getTag() == "fast_food" || vertex->getTag() == "bar") {
            gv->setVertexColor(vertex->getID(), "red");
        }
        gv->addNode(vertex->getID(), (int) (xPercent * width), (int) (yPercent * height));
        //gv->setVertexLabel(vertex->getID(), vertex->getTag());
        gv->setVertexLabel(vertex->getID(), to_string(vertex->getID()));
    }


    vector<int> aux;
    for (Vertex *vertex: this->path) {
        aux.push_back(vertex->getID());
    }

    int id = 0;
    for (Vertex *vertex: this->path) {
        for (Edge edge: vertex->getAdj()) {
            if(find(aux.begin(), aux.end(), edge.getDestID()) == aux.end()) {
                continue;
            }
            gv->setEdgeThickness(id, 2);
            switch (edge.getDifficulty()) {
                case 1:
                    gv->setEdgeColor(id, "green");
                    break;
                case 2:
                    gv->setEdgeColor(id, "yellow");
                    break;
                case 3:
                    gv->setEdgeColor(id, "orange");
                    break;
                case 4:
                    gv->setEdgeColor(id, "red");
                    break;
                case 5:
                    break;
            }
            gv->addEdge(id, vertex->getID(), edge.getDestID(),  EdgeType::DIRECTED);
            //gv->setEdgeLabel(id, to_string(edge.getWeight()));
            id++;
        }
    }
}