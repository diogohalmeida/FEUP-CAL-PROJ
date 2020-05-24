#include "readFileGraph.h"


vector<Graph<coordinates>> readAllRegions(){
    vector<Graph<coordinates>> result;

    Graph<coordinates> graph = readGraph("penafiel_full");
    result.push_back(graph);

    graph = readGraph("penafiel_strong");
    result.push_back(graph);


    return result;
}


Graph<coordinates> readGraph(string city){
    Graph<coordinates> graph;
    readNodes(graph, city);
    readEdges(graph, city);
    //readTags(graph,city);
    return graph;
}

void readNodes(Graph<coordinates> &graph, string city){
    string cityLowercase = toLower(city);
    string fileDir = "../resources/Maps/Penafiel/" + city + "_nodes_xy.txt";
    ifstream nodeFile;
    nodeFile.open(fileDir);
    if (nodeFile.is_open()){
        string line;
        getline(nodeFile, line);
        int numNodes = stoi(line);
        for (int i = 0; i < numNodes; i++){
            getline(nodeFile, line);
            vector<int> data = stringToDataVector(line);
            int choice = rand() % 10 + 1;
            string tag;
            if (choice == 5){
                tag = "meeting_point";
            }
            else
                tag = "";
            graph.addVertex(data.at(0),make_pair(data.at(1), data.at(2)), tag);

        }
    }
    else{
        cerr << "Nodes file could not be opened!" << endl;
    }
    nodeFile.close();

}

void readEdges(Graph<coordinates> &graph, string city){
    string cityLowercase = toLower(city);
    string fileDir = "../resources/Maps/Penafiel/" + city + "_edges.txt";
    ifstream edgeFile;
    edgeFile.open(fileDir);
    if (edgeFile.is_open()){
        string line;
        getline(edgeFile, line);
        int numEdges = stoi(line);
        for (int i = 0; i < numEdges; i++){
            getline(edgeFile, line);
            vector<int> data = stringToDataVector(line);
            int choice = rand() % 200 + 1;
            int difficulty;
            if (choice > 199){
                difficulty = 3;
            }
            else if (choice < 3){
                difficulty = 2;
            }
            else{
                difficulty = 1;
            }
            graph.addBiDirEdge(data.at(0), data.at(1), difficulty);
        }
    }
    else{
        cerr << "Edges file could not be opened!" << endl;
    }
    edgeFile.close();
}

