#ifndef EXPLOREIT_WORKER_H
#define EXPLOREIT_WORKER_H

#include "../Graph/Graph.h"

class Worker {
private:
    int skill;
    int max_duration;       //in minutes
    vector<Vertex*> tour;
public:
    int getSkill() const;
    void setSkill(int skill);
    int getMaxDuration() const;
    void setMaxDuration(int max_duration);
    vector<Vertex*> getTour() const;
    void setTour(vector<Vertex*> tour);
};


#endif //EXPLOREIT_WORKER_H
