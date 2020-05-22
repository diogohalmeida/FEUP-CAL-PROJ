#include "tourHandling.h"



vector<Path> tourGenerator(Graph<coordinates> graph, vector<Worker> workers){
    srand(time(NULL));
    vector<Path> toLunchPaths;
    int starting_point = -1;
    int ending_point = -1;
    while (toLunchPaths.size() < workers.size()) {
        if (ending_point == -1 && starting_point == -1) {
            for (Vertex<coordinates> *vertex: graph.getVertexSet()) {
                int choice = rand() % 20 + 1;
                if (choice == 1) {
                    if (vertex->getTag() == "meeting_point") {
                        ending_point = vertex->getID();
                        break;
                    }
                }
            }
        }
        vector<int> starting = {};
        for (Vertex<coordinates> *vertex: graph.getVertexSet()){
            Path path = graph.dijkstraShortestPath(vertex->getID(), ending_point);
            if (path.getDistance() > 4000 && path.getDistance() < 5000){
                toLunchPaths.push_back(path);
                starting.push_back(vertex->getID());
            }
        }
        if (starting.size() > workers.size()){
            break;
        }
        else{
            starting_point = -1;
            ending_point = -1;
        }
    }
    cout << toLunchPaths.size();
    cout << endl;
    return toLunchPaths;
}
