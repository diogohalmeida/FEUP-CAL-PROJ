#include "readFileGraph.h"


Graph readGraph(string city){
    Graph graph;
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
            graph.addEdge(node1, node2, 0);
        }
    }
    else{
        cerr << "Edges file could not be opened!" << endl;
    }
    edgeFile.close();
}


void readTags(Graph &graph, string city){
    string cityLowercase = toLower(city);
    string fileDir = "../resources/TagExamples/" + city + "/t03_tags_" + cityLowercase + ".txt";
    ifstream tagFile;
    tagFile.open(fileDir);
    if (tagFile.is_open()){
        string line;
        getline(tagFile, line);
        int numTags = stoi(line);
        for (int i = 0; i < numTags; i++){
            string tag;
            getline(tagFile, tag);
            tag.erase(0,8);
            getline(tagFile, line);
            int numNodes = stoi(line);
            for (int j = 0; j < numNodes; j++){
                getline(tagFile, line);
                Vertex* v = graph.findVertex(stoi(line));
                v->setTag(tag);
            }
        }
    }
    else{
        cerr << "Tags file could not be opened!" << endl;
    }
    tagFile.close();
}