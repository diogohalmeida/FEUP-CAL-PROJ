#include "graphDisplay.h"

graphDisplay::graphDisplay(Graph &graph, int width, int height) {
    this->graph = graph;
    this->width = width;
    this->height = height;
    this->gv = new GraphViewer(width, height, false);
}

void graphDisplay::setGraph(Graph &graph) {
    this->graph = graph;
}

void graphDisplay::show() {
    gv->createWindow(width, height);

    double yPercent, xPercent;

    for (Vertex* vertex: graph.getVertexSet()){
        yPercent = 1.0 - ((vertex->getY()- graph.getMinY())/(graph.getMaxY() - graph.getMinY())*0.9 + 0.05);
        xPercent = (vertex->getX() - graph.getMinX())/(graph.getMaxX() - graph.getMinX())*0.9 + 0.05;

        gv->addNode(vertex->getID(), (int) (xPercent * width), (int) (yPercent * height));
    }

    int id = 0;
    for (Vertex* vertex: graph.getVertexSet()){
        for (Edge edge: vertex->getAdj()){
            gv->addEdge(id,vertex->getID(),edge.getDestID(),0);
            id++;
        }
    }
}