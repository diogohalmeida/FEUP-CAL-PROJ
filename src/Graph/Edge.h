#ifndef EXPLOREIT_EDGE_H
#define EXPLOREIT_EDGE_H


using namespace std;

/*
 * ================================================================================================
 * Class Edge
 * ================================================================================================
 */
class Edge{
private:
    int destID;
    double weight;
    int difficulty;

public:
    Edge(int destID, double w, int difficulty);
    int getDestID() const;
    double getWeight() const;
    void setID(int id);
    void setWeight(double w);
    int getDifficulty() const;
    void setDifficulty(int difficulty);
};


#endif //EXPLOREIT_EDGE_H
