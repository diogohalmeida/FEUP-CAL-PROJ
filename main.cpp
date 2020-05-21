#include "src/Interface/menu.h"

//For testing
Graph read(){
    Graph graph;

    string fileDir = "../resources/Maps/Penafiel/penafiel_strong_nodes_xy.txt";
    ifstream nodeFile;
    nodeFile.open(fileDir);
    if (nodeFile.is_open()){
        string line;
        getline(nodeFile, line);
        int numNodes = stoi(line);
        for (int i = 0; i < numNodes; i++){
            getline(nodeFile, line);
            vector<int> data = stringToDataVector(line);
            graph.addVertex(data.at(0),data.at(1),data.at(2));
        }
    }
    else{
        cerr << "Nodes file could not be opened!" << endl;
    }
    nodeFile.close();


    fileDir = "../resources/Maps/Penafiel/penafiel_strong_edges.txt";
    ifstream edgeFile;
    edgeFile.open(fileDir);
    srand (time(NULL));
    if (edgeFile.is_open()){
        string line;
        getline(edgeFile, line);
        int numEdges = stoi(line);
        for (int i = 0; i < numEdges; i++){
            getline(edgeFile, line);
            vector<int> data = stringToDataVector(line);
            int choice = rand() % 20 + 1;
            int difficulty;
            if (choice == 1){
                int max = 4;
                int min = 3;
                difficulty = rand()%(max-min+1)+min;
            }
            else{
                int max = 2;
                int min = 1;
                difficulty = rand()%(max-min+1)+min;
            }
            graph.addEdge(data.at(0), data.at(1), difficulty);
        }
    }
    else{
        cerr << "Edges file could not be opened!" << endl;
    }
    edgeFile.close();

    return graph;
}




int main() {
    cout << "Hello There! Welcome to ExploreIT!" << endl;
    cout << "Loading region maps..." << endl;
    vector<Graph> regions = readAllRegions();

    while (mainMenu(regions) != 0);

    /*
    Graph graph = read();
    vector<Path> paths = graph.getAllPaths(6271,8298);

    paths.at(0).display();
    */


    //graph.getAllPaths(0, 2);



    cout << "Thank you for using ExploreIT! Have a great tour!" << endl;

    getchar();

	return 0;
}
