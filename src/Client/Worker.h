#ifndef EXPLOREIT_WORKER_H
#define EXPLOREIT_WORKER_H

#include "../Graph/Graph.h"

class Worker {
private:
    string name;
    int skill;
    int max_duration;       //in minutes
    vector<Vertex*> tour;
public:
    Worker(string name, int skill, int max_duration);
    string getName() const;
    void setString(string name);
    int getSkill() const;
    void setSkill(int skill);
    int getMaxDuration() const;
    void setMaxDuration(int max_duration);
    vector<Vertex*> getTour() const;
    void setTour(vector<Vertex*> tour);
};


#endif //EXPLOREIT_WORKER_H
