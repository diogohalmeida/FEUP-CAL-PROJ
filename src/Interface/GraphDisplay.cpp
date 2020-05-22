#include "GraphDisplay.h"

GraphDisplay::GraphDisplay(Graph<coordinates> &graph, int width, int height) {
    this->graph = graph;
    this->width = width;
    this->height = height;
    this->gv = new GraphViewer(width, height, false);
}

void GraphDisplay::setGraph(Graph<coordinates> &graph) {
    this->graph = graph;
}

void GraphDisplay::show() {
    gv->defineVertexColor("blue");
    gv->defineVertexSize(5);
    gv->defineEdgeCurved(false);
    gv->createWindow(width, height);
    double yPercent, xPercent;

    for (Vertex<coordinates>* vertex: graph.getVertexSet()){

        yPercent = (vertex->getInfo().second- graph.getMinY())/(graph.getMaxY() - graph.getMinY())*0.9 + 0.05;
        xPercent = (vertex->getInfo().first - graph.getMinX())/(graph.getMaxX() - graph.getMinX())*0.9 + 0.05;

        if (vertex->getTag() == "headquarters"){
            gv->setVertexColor(vertex->getID(), "red");
            gv->setVertexSize(vertex->getID(), 10);
        }

        if (vertex->getTag() == "meeting_point"){
            gv->setVertexColor(vertex->getID(), "orange");
            gv->setVertexSize(vertex->getID(), 8);
        }
        gv->addNode(vertex->getID(), (int) (xPercent * width), (int) (yPercent * height));
        //gv->setVertexLabel(vertex->getID(), vertex->getTag());
        gv->setVertexLabel(vertex->getID(), to_string(vertex->getID()));
    }

    int id = 0;
    for (Vertex<coordinates>* vertex: graph.getVertexSet()){
        for (Edge<coordinates>* edge: vertex->getAdj()){
            gv->setEdgeThickness(id, 2);
            switch(edge->getDifficulty()){
                case 1:
                    gv->setEdgeColor(id, "green");
                    break;
                case 2:
                    gv->setEdgeColor(id, "yellow");
                    break;
                case 3:
                    gv->setEdgeColor(id, "orange");
                    break;
                case 4:
                    gv->setEdgeColor(id, "red");
                    break;
            }
            gv->addEdge(id,vertex->getID(),edge->getDest()->getID(),EdgeType::UNDIRECTED);
            //gv->setEdgeLabel(id, to_string(edge->getWeight()));
            id++;
        }
    }

    gv->rearrange();
    this->close();
}


void GraphDisplay::close() {
    cin.ignore(1, '\n');
    cout << "Please press Enter to exit the graph viewer." << endl;
    int character = getchar();
    if (character == '\n') {
        if(gv!= nullptr){
            gv->closeWindow();
            delete(gv);
        }
    }
    else
        cin.ignore(1000, '\n');
}

