#include "tourHandling.h"



vector<Path> tourGenerator(Graph<coordinates> graph, vector<Worker> workers){
    srand(time(NULL));
    vector<Path> toLunchPaths;
    int starting_point = -1;
    int ending_point = -1;

    //Choose meeting point
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
                //generate paths between 4000 and 5000 m
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

    cout << "\nPath 1: " << toLunchPaths[0].getDistance() << endl;
    cout << "Path 2: " << toLunchPaths[1].getDistance() << endl;
    cout << "result: " << (toLunchPaths[0] + toLunchPaths[1]).getDistance();
    cout << endl;
    return toLunchPaths;
}
