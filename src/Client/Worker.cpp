#include "Worker.h"

int Worker::getSkill() const {
    return this->skill;
}

void Worker::setSkill(int skill) {
    this->skill = skill;
}

int Worker::getMaxDuration() const {
    return this->max_duration;
}

void Worker::setMaxDuration(int max_duration) {
    this->max_duration = max_duration;
}

vector<Vertex *> Worker::getTour() const {
    return this->tour;
}

void Worker::setTour(vector<Vertex *> tour) {
    this->tour = tour;
}