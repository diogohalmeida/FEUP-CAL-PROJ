#ifndef EXPLOREIT_WORKER_H
#define EXPLOREIT_WORKER_H

#include <string>

using namespace std;

class Worker {
private:
    string name;
    int skill;
    int max_duration;       //in hours
public:
    Worker(string name, int skill, int max_duration);
    string getName() const;
    void setString(string name);
    int getSkill() const;
    void setSkill(int skill);
    int getMaxDuration() const;
    void setMaxDuration(int max_duration);
};


#endif //EXPLOREIT_WORKER_H
