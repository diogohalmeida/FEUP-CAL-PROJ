#include "Path.h"


Path::Path(vector<int> path){
    this->path = path;
    this->max_difficulty = 0;
    this->distance = 1;
}


Path::Path(vector<int> path, double distance, int max_difficulty) {
    this->path = path;
    this->max_difficulty = max_difficulty;
    this->distance = distance;
}

vector<int> Path::getPath() const {
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