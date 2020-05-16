#include "GraphDisplay.h"

GraphDisplay::GraphDisplay(Graph &graph, int width, int height) {
    this->graph = graph;
    this->width = width;
    this->height = height;
    this->gv = new GraphViewer(width, height, false);
}

void GraphDisplay::setGraph(Graph &graph) {
    this->graph = graph;
}

void GraphDisplay::show() {
    gv->createWindow(width, height);


    double yPercent, xPercent;

    for (Vertex* vertex: graph.getVertexSet()){
        yPercent = 1.0 - ((vertex->getY()- graph.getMinY())/(graph.getMaxY() - graph.getMinY())*0.9 + 0.05);
        xPercent = (vertex->getX() - graph.getMinX())/(graph.getMaxX() - graph.getMinX())*0.9 + 0.05;

        if (vertex->getTag() == "restaurant" || vertex->getTag()== "cafe" || vertex->getTag() == "pub" || vertex->getTag() == "fast_food" || vertex->getTag() == "bar"){
            gv->setVertexColor(vertex->getID(),"red");
        }
        gv->addNode(vertex->getID(), (int) (xPercent * width), (int) (yPercent * height));
        gv->setVertexLabel(vertex->getID(), vertex->getTag());
    }

    int id = 0;
    for (Vertex* vertex: graph.getVertexSet()){
        for (Edge edge: vertex->getAdj()){
            gv->setEdgeThickness(id, 2);
            switch(edge.getDifficulty()){
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
                case 5:
                    break;
            }
            gv->addEdge(id,vertex->getID(),edge.getDestID(),0);
            //gv->setEdgeLabel(id, to_string(edge.getWeight()));
            id++;
        }
    }

    gv->rearrange();
}
