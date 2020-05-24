#include "tourHandling.h"

//Generate different paths from various starting points to lunch
vector <Path> toLunchPaths(Graph<coordinates> graph, vector<Worker> workers, int &lunch_point) {
    vector<Path> toLunchPaths;
    int starting_point = -1;
    lunch_point = -1;

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
            //Generate paths between 4000 and 5000 m
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
    cout << toLunchPaths.size() << endl;    //Print to console all paths generated from start to lunch
    return toLunchPaths;

}

//Get one single path from lunch to end for every worker
vector <Path> getSingleEndPath(Graph<coordinates> graph, vector<Worker> workers, const int lunch_point, vector <Path> toLunchPaths){
    vector<Path> toEndPaths;
    //Max duration overall
    int duration_left = workers.at(0).getMaxDuration() - 5;    //Tmax - (14-9)
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

//Join both paths (start-lunch|lunch-finish) to get the full tour
vector <Path> concatenatePathvectors(vector<Path> v1, vector <Path> v2){
    vector <Path> res;
    for (Path p1: v1) {
        for (Path p2: v2){
            Path temp(p1);
            temp = temp + p2;
            res.push_back(temp);
            break;
        }
    }
    return res;
}

//Get various paths from lunch to end for every worker
vector <Path> generateDifferentEndPaths(Graph<coordinates> graph, vector<Worker> workers, const int lunch_point, vector <Path> toLunchPaths){
    vector <Path> paths;
    int duration_left = workers.at(0).getMaxDuration() - 5;    //Tmax - (14-9)
    int distance_left = duration_left * 1000; //walking speed = 1km/h
    int end_point = -1;

    vector <int> possibleIntermediates;
    for (auto i: graph.getVertexSet()){
        if (graph.findVertex(i->getID()) != nullptr) possibleIntermediates.push_back(i->getID());
    }

    while (true){
        int intermediate_choice = rand() % (possibleIntermediates.size());
        end_point = rand() % (graph.getVertexSet().size());
        if (graph.findVertex(graph.getVertexSet().at(end_point)->getID())->getTag() == "meeting_point") {
            Path path = graph.dijkstraShortestPath(possibleIntermediates.at(intermediate_choice), graph.getVertexSet().at(end_point)->getID());
            end_point = graph.getVertexSet().at(end_point)->getID();
            if (path.getDistance()/3 < distance_left) break;
        }
    }

    for (int i = 0; i < 3000; i++) {
        int intermediate_choice = rand() % (possibleIntermediates.size());
        Path toAdd = graph.dijkstraShortestPath(lunch_point, possibleIntermediates.at(intermediate_choice));
        Path temp = graph.dijkstraShortestPath(possibleIntermediates.at(intermediate_choice), end_point);
        toAdd = toAdd + temp;
        if (toAdd.getDistance() < distance_left){
            paths.push_back(toAdd);
        }
    }

    if (paths.size() ==  0){
        return getSingleEndPath(graph, workers, lunch_point, toLunchPaths);
    }
    cout << paths.size() << endl;
    return concatenatePathvectors(toLunchPaths, paths);
}

//Generate Paths for workers
vector<Path> tourGenerator(Graph<coordinates> graph, vector<Worker> workers, int single){
    srand(time(NULL));
    int lunch_point;
    vector <Path> toLunch = toLunchPaths(graph, workers, lunch_point);
    vector<Path> final_paths;
    if (single == 0) {
         final_paths = generateDifferentEndPaths(graph, workers, lunch_point, toLunch);
    }
    else
        final_paths = getSingleEndPath(graph, workers, lunch_point, toLunch);

    return final_paths;
}


//Distribute paths to workers based on their skill
void givePathsToWorkers(vector<Worker> & workers, vector<Path> paths) {
    sort(workers.begin(), workers.end(), [](const Worker &w1, const Worker &w2) {
        return w1.getSkill() < w2.getSkill();
    });

    queue<Path> paths1;
    queue<Path> paths2;
    queue<Path> paths3;

    for (Path path: paths) {
        if (path.getMaxDifficulty() == 1) {
            paths1.push(path);
            continue;
        }
        if (path.getMaxDifficulty() == 2) {
            paths2.push(path);
            continue;
        }
        if (path.getMaxDifficulty() == 3) {
            paths3.push(path);
            continue;
        }
    }

    cout << "Paths with difficulty 3 size: " << paths3.size() << endl;
    cout << "Paths with difficulty 2 size: " << paths2.size() << endl;
    cout << "Paths with difficulty 1 size: " << paths1.size() << endl;

    //Mudar para iteradores
    for (Worker& worker: workers){
        if (worker.getSkill() == 3){
            Path temp = paths3.front();
            worker.setPath(temp);
            paths3.pop();
            paths3.push(temp);
        }

        if (worker.getSkill() == 2){
            if (paths2.size() == 0) {
                cout << "No possible paths generated with difficulty = 2\n";
                Path temp = paths3.front();
                worker.setPath(temp);
                paths3.pop();
                paths3.push(temp);
            }
            else {
                Path temp = paths2.front();
                worker.setPath(temp);
                paths2.pop();
                paths2.push(temp);
            }
        }

        if (worker.getSkill() == 1){
            if (paths1.size() == 0){
                cout << "No possible paths generated with difficulty = 1\n";
                if (paths2.size() == 0) {
                    Path temp = paths3.front();
                    worker.setPath(temp);
                    paths3.pop();
                    paths3.push(temp);
                }
                else{
                    Path temp = paths2.front();
                    worker.setPath(temp);
                    paths2.pop();
                    paths2.push(temp);
                }
            }
            else {
                Path temp = paths1.front();
                worker.setPath(temp);
                paths1.pop();
                paths1.push(temp);
            }
        }
  }

}