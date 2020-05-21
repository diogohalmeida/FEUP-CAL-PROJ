#ifndef EXPLOREIT_PATH_H
#define EXPLOREIT_PATH_H

#include "Vertex.h"
#include <graphviewer.h>

class Path {
private:
    vector <Vertex*> path;
    double distance;
    int max_difficulty;
    int minY, minX, maxX, maxY;

public:
    Path();
    void addVertex(Vertex* vertex);
    void clear();
    void addDistance(double distance);
    double getDistance() const;
    vector<Vertex*> getPath() const;
    void verifyDifficulty(int max_difficulty);
    void display();


};


#endif //EXPLOREIT_PATH_H
