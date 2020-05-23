#ifndef EXPLOREIT_WORKER_H
#define EXPLOREIT_WORKER_H

#include <string>
#include "../Graph/Path.h"

using namespace std;

class Worker {
private:
    string name;
    int skill;
    int max_duration;       //in hours
    Path path;


public:
    Worker(string name, int skill, int max_duration, Path path);
    string getName() const;
    void setString(string name);
    int getSkill() const;
    void setSkill(int skill);
    int getMaxDuration() const;
    void setMaxDuration(int max_duration);
    Path getPath() const;
    void setPath(Path path);
};


#endif //EXPLOREIT_WORKER_H
