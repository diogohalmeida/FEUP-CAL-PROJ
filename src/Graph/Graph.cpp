#include "Graph.h"





/*
 * ================================================================================================
 * Class Graph
 * ================================================================================================
 */
Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getID() == id)
            return v;
    return nullptr;
}

bool Graph::addVertex(const int &id, const double &x, const double &y) {
    if (findVertex(id) != nullptr)
        return false;
    Vertex* toAdd = new Vertex(id, x, y);
    if (vertexSet.empty()) {
        this->minY = toAdd->getY();
        this->minX = toAdd->getX();
        this->maxX = toAdd->getX();
        this->maxY = toAdd->getY();
    }
    else {
        if(toAdd->getX() > maxX)
            maxX = toAdd->getX();
        else if(toAdd->getX() < minX)
            minX = toAdd->getX();
        if(toAdd->getY() > maxY)
            maxY = toAdd->getY();
        else if (toAdd->getY() < minY)
            minY = toAdd->getY();
    }
    vertexSet.push_back(toAdd);
    return true;
}



bool Graph::addEdge(const int &sourc, const int &dest, int difficulty) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    int w = v1->distance(v2);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(dest,w, difficulty);
    return true;
}

vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

double Graph::getMaxX() {
    return this->maxX;
}

double Graph::getMinX() {
    return this->minX;
}

double Graph::getMaxY() {
    return this->maxY;
}

double Graph::getMinY() {
    return this->minY;
}

string Graph::getRegion() const {
    return this->region;
}

void Graph::setRegion(string region) {
    this->region = region;
}

/*
vector<Path> Graph::getAllPaths(const int &sourc, const int &dest, const double &max_distance) {
    vector<Path> result;
    int recursive_calls = 0;

    Path path;

    for (auto vertex: vertexSet) {
        vertex->setVisited(false);
    }

    dfsVisit(sourc, dest, result, path, max_distance, recursive_calls);

    return result;
}


void Graph::dfsVisit(int curr, const int& dest, vector<Path> & result, Path & path, const double& max_distance, int & recursive_calls){
    Vertex* current = findVertex(curr);
    current->setVisited(true);
    path.addVertex(findVertex(curr));

    if (result.size() > 10 || recursive_calls > 200000){
        return;
    }

    if (curr == dest){
        if (path.getDistance() < max_distance)
            for (Vertex* v: path.getPath()){
                cout << v->getID() << " ";
            }
        cout << endl;
        result.push_back(path);
    }
    else{
        for (auto & vertex : path.getPath()){
            vector<Edge> adj = vertex->getAdj();

            for (auto & adj_edge: adj) {
                Vertex *adj_vertex = findVertex(adj_edge.getDestID());
                if (!adj_vertex->getVisited()) {
                    path.addDistance(adj_edge.getWeight());
                    path.verifyDifficulty(adj_edge.getDifficulty());
                    recursive_calls++;
                    dfsVisit(adj_vertex->getID(), dest, result, path, max_distance, recursive_calls);
                }
            }
        }
    }

    path.popLastVertex();
    current->setVisited(false);

}

 */


// Prints all paths from 's' to 'd'
vector<Path> Graph::getAllPaths(int source, int destination){

    vector<Path> result;
    // Mark all the vertices as not visited
    bool *visited = new bool[vertexSet.size()];

    // Create an array to store paths
    int *sequence = new int[vertexSet.size()];
    int index = 0; // Initialize sequence[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < vertexSet.size(); i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    dfsVisit(source, destination, visited, sequence, index, result);

    return result;
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]

void Graph::dfsVisit(int u, int d, bool visited[], int sequence[], int &index, vector<Path> & result)
{
    // Mark the current node and store it in sequence[]
    visited[u] = true;
    sequence[index] = u;
    index++;

    // If the current vertex is the same as destination, then create a Path object and push it to the result vector

    if (u == d){
        Path path;
        for (int i = 0; i < index; i++) {
            cout << sequence[i] << " ";
            Vertex *toAdd = findVertex(sequence[i]);
            path.addVertex(toAdd);
        }
        cout << endl;
        result.push_back(path);
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        Vertex* vertex = findVertex(u);
        auto adj = vertex->getAdj();
        for (auto i = adj.begin(); i != adj.end(); i++)
            if (!visited[i->getDestID()])
                dfsVisit(i->getDestID(), d, visited, sequence, index, result);
    }

    // Remove current vertex from sequence[] and mark it as unvisited
    index--;
    visited[u] = false;
}