#ifndef EXPLOREIT_PATH_H
#define EXPLOREIT_PATH_H
#include <vector>
#include <graphviewer.h>

class Path {
private:
    vector <int> path;
    double distance;
    int max_difficulty;

public:
    Path(vector<int> path);
    Path(vector<int> path, double distance, int max_difficulty);
    void clear();
    void addDistance(double distance);
    double getDistance() const;
    vector<int> getPath() const;
    void verifyDifficulty(int max_difficulty);


};


#endif //EXPLOREIT_PATH_H
