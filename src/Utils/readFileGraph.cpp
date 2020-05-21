#include "readFileGraph.h"


vector<Graph> readAllRegions(){
    vector<Graph> result;

    Graph graph = readGraph("penafiel_full");
    result.push_back(graph);

    graph = readGraph("penafiel_strong");
    result.push_back(graph);


    return result;
}


Graph readGraph(string city){
    Graph graph;
    graph.setRegion(city);
    readNodes(graph, city);
    readEdges(graph, city);
    //readTags(graph,city);
    return graph;
}

void readNodes(Graph &graph, string city){
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
            graph.addVertex(data.at(0),data.at(1),data.at(2));
        }
    }
    else{
        cerr << "Nodes file could not be opened!" << endl;
    }
    nodeFile.close();

}

void readEdges(Graph &graph, string city){
    string cityLowercase = toLower(city);
    string fileDir = "../resources/Maps/Penafiel/" + city + "_edges.txt";
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
            if (choice > 19){
                int max = 4;
                int min = 3;
                difficulty = rand()%(max-min+1)+min;
            }
            else if (choice < 5){
                difficulty = 2;
            }
            else{
                difficulty = 1;
            }
            graph.addEdge(data.at(0), data.at(1), difficulty);
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