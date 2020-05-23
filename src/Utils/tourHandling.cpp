#include "tourHandling.h"



vector<Path> tourGenerator(Graph<coordinates> graph, vector<Worker> workers){
    srand(time(NULL));
    vector<Path> toLunchPaths;
    int starting_point = -1;
    int lunch_point = -1;

    //Choose meeting point
    while (toLunchPaths.size() < workers.size()) {
        if (lunch_point == -1 && starting_point == -1) {
            while (true){
                int choice = rand()% (graph.getVertexSet().size());
                Vertex<coordinates>* vertex = graph.getVertexSet().at(choice);
                if (vertex->getTag() == "meeting_point") {
                    lunch_point = vertex->getID();
                    vertex->setTag("lunch_point");
                    break;
                }
            }
        }

        vector<int> starting = {};
        for (Vertex<coordinates> *vertex: graph.getVertexSet()){
                Path path = graph.dijkstraShortestPath(vertex->getID(), lunch_point);
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
            lunch_point = -1;
        }

    }
    cout << toLunchPaths.size() << endl;

    /*
    cout << "\nPath 1: " << toLunchPaths[0].getDistance() << endl;
    cout << "Path 2: " << toLunchPaths[1].getDistance() << endl;
    cout << "result: " << (toLunchPaths[0] + toLunchPaths[1]).getDistance();
    cout << endl;
     */

    //Path path = toLunchPaths[0] + toLunchPaths[1];

    //return toLunchPaths;

    vector<Path> toEndPaths;
    //Max duration overall
    int duration_left = workers.at(0).getMaxDuration() - 5;    //Tmax - (14-9)
    int middle_point = -1;
    int ending_point = -1;


    //Choose ending point
    while (true){
        int choice = rand()% (graph.getVertexSet().size());
        Vertex<coordinates>* vertex = graph.getVertexSet().at(choice);
        if (vertex->getTag() == "meeting_point"){
            Path path = graph.dijkstraShortestPath(lunch_point, vertex->getID());
            if (path.getDistance() < duration_left * 1000 && path.getDistance() > duration_left * 900) { //Assuming the workers will do 1km/h
                vertex->setTag("end_of_tour");
                ending_point = vertex->getID();
                break;
            }
        }
    }

    Path ending_path = graph.dijkstraShortestPath(lunch_point, ending_point);
    vector<Path> final;
    for (Path path: toLunchPaths){
        final.push_back(path+ending_path);
    }

    return final;
}

