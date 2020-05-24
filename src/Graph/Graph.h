/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <cmath>
#include <functional>
#include <unordered_map>
#include "Path.h"
#include "MutablePriorityQueue.h"


using namespace std;

template <class T> class Edge;
template <class T> class Graph;
typedef pair<double, double> coordinates;

constexpr auto INF = std::numeric_limits<double>::max();
//Graph class, algorithms used to generate shortest paths are implemented here

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template <class T>
class Vertex {
	int id;
	string tag;
	T info;
	vector<Edge<T> *> outgoing;
	vector<Edge<T>*> incoming;
    Edge<T>* addEdge(Vertex *dest, double w, int difficulty);
	Vertex(int id);
    Vertex(T info);

	bool visited;  // for path finding

    //Dijkstra
    double dist;
    Vertex<T> * path;

public:
    int queueIndex;

	int getID() const;
	string getTag() const;
	T getInfo() const;
	vector<Edge<T> *> getAdj() const;
    vector<Edge<T> *> getIncoming() const;
    double getCostTo(int dest_id, int & difficulty) const;
    double getDist() const;
    void setTag(string tag);
    double distance(Vertex<T>* destination);
    Edge<T>* removeEdgeTo(Vertex<T> *d);

    bool operator<(const Vertex &v2) const;
    bool operator>(const Vertex &v2) const;
    bool operator<=(const Vertex &v2) const;
    bool operator>=(const Vertex &v2) const;

	friend class Graph<T>;
};


/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template <class T>
class Edge {
	Vertex<T> * orig;
	Vertex<T> * dest;
	double weight;
	int difficulty;
	Edge(Vertex<T> *o, Vertex<T> *d, double w, int dif);

public:
	double getWeight() const;
	Vertex<T> *getDest() const;
	Vertex<T> * getOrig() const;
	int getDifficulty() const;

	friend class Graph<T>;
	friend class Vertex<T>;
};

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
	unordered_map<int, int> vertexMap;

	double maxX;
    double minX;
    double maxY;
    double minY;

    Vertex<T> * findVertex(const T &info) const;

    void dfsVisit(Vertex<T> *v, vector<int> & res) const;
public:

	vector<Vertex<T>*> getVertexSet() const;

    void addVertex(Vertex<T> *vertex);
    Vertex<T> * addVertex (const int & id, const T &info, const string &tag);
    Vertex<T> * findVertex (const int &id) const;

	Edge<T> * addEdge (const int &source, const int &dest, const int &difficulty);
    void addBiDirEdge(const int &source, const int &dest, const int &difficulty);

    double getMaxX() {return this->maxX;}
    double getMinX() {return this->minX;}
    double getMaxY() {return this->maxY;}
    double getMinY() {return this->minY;}


    vector<int> dfs(const int & source) const;
    vector<int> bfs(const int & source) const;

    void dijkstraShortestPath(const T &origin);
    Path dijkstraShortestPath(const int &origin, const int &destination);

    Path AstarShortestPath(const int id_src, const int id_dest, function<double (T, T)> h);
};

/* ================================================================================================
 * Class Vertex
 * ================================================================================================
 */

template<class T>
Vertex<T>::Vertex(int id): id(id) {}

template<class T>
Vertex<T>::Vertex(T info): info(info) {}

template<class T>
Edge<T>* Vertex<T>::addEdge(Vertex<T> *dest, double w, int difficulty) {
    Edge<T> * e = new Edge<T>(this, dest, w, difficulty);
    this->outgoing.push_back(e);
    dest->incoming.push_back(e);
    return e;
}

template<class T>
int Vertex<T>::getID() const {
    return this->id;
}

template<class T>
vector<Edge<T> *> Vertex<T>::getAdj() const {
    return this->outgoing;
}

template<class T>
vector<Edge<T> *> Vertex<T>::getIncoming() const {
    return this->incoming;
}

template<class T>
T Vertex<T>::getInfo() const {
    return this->info;
}

template<class T>
double Vertex<T>::getCostTo(int dest_id, int & difficulty) const {
    for (auto e : outgoing) {
        if (e->dest->getID() == dest_id) {
            difficulty = e->difficulty;
            return e->getWeight();
        }
    }
    return -1;
}

template<class T>
string Vertex<T>::getTag() const {
    return tag;
}

template<class T>
double Vertex<T>::getDist() const {
    return this->dist;
}

template<class T>
bool Vertex<T>::operator<(const Vertex &v2) const {
    return this->dist < v2.dist;
}

template<class T>
bool Vertex<T>::operator>(const Vertex &v2) const {
    return v2 < *this;
}

template<class T>
bool Vertex<T>::operator<=(const Vertex &v2) const {
    return !(v2 < *this);
}

template<class T>
bool Vertex<T>::operator>=(const Vertex &v2) const {
    return !(*this < v2);
}

template<class T>
void Vertex<T>::setTag(string tag) {
    this->tag = tag;
}

template<class T>
double Vertex<T>::distance(Vertex<T> *destination) {
    double x = this->getInfo().first - destination->getInfo().first;
    double y = this->getInfo().second - destination->getInfo().second;
    double result = sqrt(pow(x,2) + pow(y,2));
    return result;
}

template <class T>
Edge<T>* Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    for (auto it = incoming.begin(); it != incoming.end(); it){
        if (((*it)->orig)->id == d->id){
            it = incoming.erase(it);
            continue;
        }
        it++;
    }
    for (auto it = outgoing.begin(); it != outgoing.end(); it){
        if (((*it)->dest)->id == d->id){
            it = outgoing.erase(it);
            return (*it);
        }
        it++;
    }
    return NULL;

}

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */

template<class T>
Edge<T>::Edge(Vertex<T> *o, Vertex<T> *d, double w, int dif): orig(o), dest(d), weight(w), difficulty(dif){}

template<class T>
double Edge<T>::getWeight() const {
    return weight;
}

template<class T>
Vertex<T>* Edge<T>::getDest() const {
    return dest;
}

template<class T>
int Edge<T>::getDifficulty() const {
    return difficulty;
}

template<class T>
Vertex<T> *Edge<T>::getOrig() const {
    return this->orig;
}

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template<class T>
void Graph<T>::addVertex(Vertex<T>* vertex) {
    vertexSet.push_back(vertex);
}

template<class T>
Vertex<T> *Graph<T>::addVertex(const int &id, const T &info, const string &tag) {
    Vertex<T> *v = findVertex(id);
    if (v != nullptr)
        return v;
    v = new Vertex<T>(id);
    v->id=id;
    v->info=info;
    v->tag=tag;
    if (vertexSet.empty()) {
        this->minY = v->info.second;
        this->minX = v->info.first;
        this->maxX = v->info.first;
        this->maxY = v->info.second;
    }
    else {
        if(v->info.first > maxX) maxX = v->info.first;
        else if(v->info.first < minX) minX = v->info.first;
        if(v->info.second > maxY) maxY = v->info.second;
        else if (v->info.second < minY) minY = v->info.second;
    }
    vertexSet.push_back(v);
    vertexMap.insert(make_pair(id, vertexSet.size() - 1));
    return v;
}

template<class T>
Edge<T> * Graph<T>::addEdge(const int &source, const int &dest, const int &difficulty) {
    auto s = findVertex(source);
    auto d = findVertex(dest);
    double w = s->distance(d);
    if (s == nullptr || d == nullptr)
        return nullptr;
    else
        return s->addEdge(d, w, difficulty);
}

template<class T>
void Graph<T>::addBiDirEdge(const int &source, const int &dest, const int &difficulty) {
    auto s = findVertex(source);
    auto d = findVertex(dest);
    double w = s->distance(d);
    if (s == nullptr || d == nullptr)
        return;
    else {
        s->addEdge(d, w, difficulty);
        d->addEdge(s, w, difficulty);
    }
}

template<class T>
Vertex<T>* Graph<T>::findVertex(const int & id) const {
    auto i = vertexMap.find(id);
    if (i == vertexMap.end()) return nullptr;
    return vertexSet.at(i->second);
}

template<class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
    return vertexSet;
}

template<class T>
Vertex<T> *Graph<T>::findVertex(const T &info) const {
    for (auto v : vertexSet)
        if (v->info == info)
            return v;
    return nullptr;
}


/* ================================================================================================
 * Algorithms
 * ================================================================================================
 */

/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<int> Graph<T>::dfs(const int & source) const {
    vector<int> res;

    for(Vertex<T> *vertex:this->vertexSet){
        vertex->visited=false;
    }
    Vertex<T>*vertex1 = findVertex(source);
    dfsVisit(vertex1,res);

    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<int> & res) const {
    // DONE (7 lines)
    if(!v->visited){
        v->visited=true;
        res.push_back(v->id); //inserts the vertex
    }

    for(Edge<T> * edge:v->outgoing){
        if(!edge->dest->visited){
            dfsVisit(edge->dest,res);
        }
    }
}


/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<int> Graph<T>::bfs(const int & source) const {
    vector<int> res; queue<Vertex<T>*> aux;
    for(Vertex<T> *vertex:vertexSet){vertex->visited=false;} //no visited
    Vertex<T> *vertex= findVertex(source);  //Find Source Vertex
    aux.push(vertex);                       //Put in queue
    vertex->visited=true;                   //Mark as visited

    while(!aux.empty()){
        vertex=aux.front();                 //Get Vertex
        aux.pop();                          //Pop from auxiliary queue
        res.push_back(vertex->id);        //Put into info vector
        for(Edge<T> * edges: vertex->outgoing){    //Search for Edges
            if(!edges->dest->visited){       //If not previously visited
                aux.push(edges->dest);       //Put into queue for posterior processing
                edges->dest->visited=true;   //Mark as visited
            }
        }
    }
    return res;
}

//Dijkstra

template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    for(Vertex<T>* vertex: vertexSet){
        vertex->dist=INT_MAX;
        vertex->path=NULL;
    }
    Vertex<T> * og = findVertex(origin);
    og->dist=0;
    MutablePriorityQueue<Vertex<T>> dijkstratqueue;
    dijkstratqueue.insert(og);
    Vertex<T>* temp;
    while(!dijkstratqueue.empty()){
        temp=dijkstratqueue.extractMin();
        for(Edge<T>* edge: temp->outgoing){
            if(edge->dest->getDist()>temp->getDist()+edge->weight){
                edge->dest->dist=temp->getDist()+edge->weight;
                edge->dest->path=temp;
                if(!dijkstratqueue.found(edge->dest))
                    dijkstratqueue.insert(edge->dest);
                else
                    dijkstratqueue.decreaseKey(edge->dest);
            }
        }
    }
}

template<class T>
Path Graph<T>::dijkstraShortestPath(const int &origin, const int &destination) {

    for(Vertex<T>* vertex: vertexSet){
        vertex->dist=INT_MAX;
        vertex->path=NULL;
    }
    Vertex<T> * og = findVertex(origin), *dest=findVertex(destination);
    og->dist=0;
    MutablePriorityQueue<Vertex<T>> queue;
    queue.insert(og);
    Vertex<T>* temp;
    while(!queue.empty()){
        temp=queue.extractMin();
        for(Edge<T>* edge: temp->outgoing){
            if(edge->dest->getDist()>temp->getDist()+edge->weight){
                edge->dest->dist=temp->getDist()+edge->weight;
                edge->dest->path=temp;
                if(!queue.found(edge->dest))
                    queue.insert(edge->dest);
                else
                    queue.decreaseKey(edge->dest);
            }
        }
    }
    vector<int> path;
    path.push_back(dest->id);
    Vertex<T>* vertex = dest;
    double distance=0;
    int difficulty, max;
    max = 0;
    while (vertex->path != NULL) {
        distance+= vertex->path->getCostTo(vertex->getID(), difficulty);
        if (difficulty > max) {
            max = difficulty;
        }
        vertex = vertex->path;
        path.emplace(path.begin(), vertex->id);
    }

    return Path(path, distance, max);
}


template<class T>
Path Graph<T>::AstarShortestPath(const int id_src, const int id_dest, function<double (T, T)> h) {
    for (Vertex<T> *vert: vertexSet) {
        vert->dist = INT_MAX;
        vert->path = NULL;
        vert->queueIndex = 0;
    }

    Vertex<T> *src = findVertex(id_src), *dest = findVertex(id_dest), *v;
    src->dist = h(src->getInfo(), dest->getInfo());
    MutablePriorityQueue<Vertex<T>> queue;
    queue.insert(src);

    while (!queue.empty()){
        v = queue.extractMin();

        if (v == dest){
            break;
        }

        for (Edge<T> *w : v->getAdj()){
            double f = v->dist - h(v->getInfo(), dest->getInfo()) +  w->getCost() + h(w->dest->getInfo(), dest->getInfo());
            if (w->dest->getDist() > f){
                double d = w->dest->getDist();
                w->dest->dist = f;
                w->dest->path = v;
                if (d == INT_MAX){
                    queue.insert(w->dest);
                }
                else {
                    queue.decreaseKey(w->dest);
                }
            }
        }
    }

    vector<int> path;
    double length = 0;
    path.push_back(dest->id);
    Vertex<T>* vertex = dest;

    int difficulty, max;
    max = 0;
    while (vertex->path != NULL) {
        length += vertex->path->getCostTo(vertex->id);
        if (difficulty > max) {
            max = difficulty;
        }
        vertex = vertex->path;
        path.emplace(path.begin(), vertex->id);
    }

    return Path(path, length, max);
}

#endif /*GRAPH_H_*/