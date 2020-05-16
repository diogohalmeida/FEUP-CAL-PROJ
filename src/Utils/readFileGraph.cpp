#include "readFileGraph.h"


vector<Graph> readAllRegions(){
    vector<Graph> result;
    for (int i = 0; i < 7; i++) {
        string city;
        switch (i) {
            case 0:
                city = "Aveiro";
                break;
            case 1:
                city = "Ermesinde";
                break;
            case 2:
                city = "Fafe";
                break;
            case 3:
                city = "Gondomar";
                break;
            case 4:
                city = "Maia";
                break;
            case 5:
                city = "Porto";
                break;
            case 6:
                city = "Viseu";
                break;
        }
        Graph graph = readGraph(city);
        result.push_back(graph);
    }
    return result;
}




Graph readGraph(string city){
    Graph graph;
    graph.setRegion(city);
    readNodes(graph, city);
    readEdges(graph, city);
    readTags(graph,city);
    return graph;
}

void readNodes(Graph &graph, string city){
    string cityLowercase = toLower(city);
    string fileDir = "../resources/PortugalMaps/" + city + "/nodes_x_y_" + cityLowercase + ".txt";
    ifstream nodeFile;
    nodeFile.open(fileDir);
    if (nodeFile.is_open()){
        string line;
        getline(nodeFile, line);
        int numNodes = stoi(line);
        for (int i = 0; i < numNodes; i++){
            getline(nodeFile, line);
            int id, x, y;
            size_t pos = line.find(',');
            id = stoi(line.substr(1, pos));
            line.erase(0, pos + 2);
            pos = line.find(',');
            x = stof(line.substr(0, pos));
            line.erase(0, pos + 2);
            pos = line.find(')');
            y = stof(line.substr(0, pos));
            graph.addVertex(id, x, y);
        }
    }
    else{
        cerr << "Nodes file could not be opened!" << endl;
    }
    nodeFile.close();

}

void readEdges(Graph &graph, string city){
    string cityLowercase = toLower(city);
    string fileDir = "../resources/PortugalMaps/" + city + "/edges_" + cityLowercase + ".txt";
    ifstream edgeFile;
    edgeFile.open(fileDir);
    srand (time(NULL));
    if (edgeFile.is_open()){
        string line;
        getline(edgeFile, line);
        int numEdges = stoi(line);
        for (int i = 0; i < numEdges; i++){
            getline(edgeFile, line);
            int node1, node2;
            size_t pos = line.find(',');
            node1 = stoi(line.substr(1, pos));
            line.erase(0, pos + 2);
            pos = line.find(')');
            node2 = stoi(line.substr(0, pos));
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
            graph.addEdge(node1, node2, difficulty);
        }
    }
    else{
        cerr << "Edges file could not be opened!" << endl;
    }
    edgeFile.close();
}


void readTags(Graph &graph, string city){
    //Tags 1
    string cityLowercase = toLower(city);
    string fileDir1 = "../resources/TagExamples/" + city + "/t03_tags_" + cityLowercase + ".txt";
    ifstream tagFile1, tagFile2;
    tagFile1.open(fileDir1);
    if (tagFile1.is_open()){
        string line;
        getline(tagFile1, line);
        int numTags = stoi(line);
        for (int i = 0; i < numTags; i++){
            string tag;
            getline(tagFile1, tag);
            tag.erase(0,8);
            getline(tagFile1, line);
            int numNodes = stoi(line);
            for (int j = 0; j < numNodes; j++){
                getline(tagFile1, line);
                Vertex* v = graph.findVertex(stoi(line));
                v->setTag(tag);
            }
        }
    }
    else{
        cerr << "Tags file could not be opened!" << endl;
    }
    tagFile1.close();

    //Tags 2
    string fileDir2 = "../resources/TagExamples/" + city + "/t10_tags_" + cityLowercase + ".txt";
    tagFile2.open(fileDir2);
    if (tagFile2.is_open()){
        string line;
        getline(tagFile2, line);
        int numTags = stoi(line);
        for (int i = 0; i < numTags; i++){
            string tag;
            getline(tagFile2, tag);
            tag.erase(0,8);
            getline(tagFile2, line);
            int numNodes = stoi(line);
            for (int j = 0; j < numNodes; j++){
                getline(tagFile2, line);
                Vertex* v = graph.findVertex(stoi(line));
                v->setTag(tag);
            }
        }
    }
    else{
        cerr << "Tags file could not be opened!" << endl;
    }
}