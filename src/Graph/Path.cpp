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

void Path::setPath(vector<int> path) {this->path = path;}

Path Path::operator+(const Path &path1) {
    vector <int> temp;
    for (auto v: this->getPath())
        temp.push_back(v);
    for (auto v: path1.getPath())
        if (v != path1.getPath().at(0))
            temp.push_back(v);

    double new_distance = this->distance + path1.distance;
    int max_difficulty = max(this->max_difficulty, path1.max_difficulty);
    return Path(temp, new_distance, 1);
}
