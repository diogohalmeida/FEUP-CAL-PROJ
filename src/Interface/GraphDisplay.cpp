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
    gv->defineVertexColor("gray");
    gv->defineVertexSize(5);
    gv->defineEdgeCurved(false);
    gv->createWindow(width, height);
    double yPercent, xPercent;

    for (Vertex<coordinates>* vertex: graph.getVertexSet()){

        yPercent = (vertex->getInfo().second- graph.getMinY())/(graph.getMaxY() - graph.getMinY())*0.9 + 0.05;
        xPercent = (vertex->getInfo().first - graph.getMinX())/(graph.getMaxX() - graph.getMinX())*0.9 + 0.05;

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
            gv->setEdgeThickness(id, 1);
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


void GraphDisplay::showPath(Path path) {
    gv->defineVertexColor("gray");
    gv->defineVertexSize(5);
    gv->defineEdgeCurved(false);
    gv->createWindow(width, height);
    double yPercent, xPercent;

    for (Vertex<coordinates>* vertex: graph.getVertexSet()){

        yPercent = (vertex->getInfo().second- graph.getMinY())/(graph.getMaxY() - graph.getMinY())*0.9 + 0.05;
        xPercent = (vertex->getInfo().first - graph.getMinX())/(graph.getMaxX() - graph.getMinX())*0.9 + 0.05;

        if (vertex->getTag() == "meeting_point"){
            gv->setVertexColor(vertex->getID(), "orange");
            gv->setVertexSize(vertex->getID(), 8);
        }

        vector<int> path_id = path.getPath();
        int id = vertex->getID();
        for (int node: path_id){

            if (node == id){
                if (node == path_id.at(0)){
                    gv->setVertexColor(vertex->getID(), "blue");
                    gv->setVertexSize(vertex->getID(), 14);
                }
                else {
                    gv->setVertexColor(vertex->getID(), "red");
                    gv->setVertexSize(vertex->getID(), 10);
                }
                break;
            }
        }

        if (vertex->getTag() == "lunch_point"){
            gv->setVertexColor(vertex->getID(), "yellow");
            gv->setVertexSize(vertex->getID(), 14);
        }

        if (vertex->getTag() == "end_of_tour"){
            gv->setVertexColor(vertex->getID(), "blue");
            gv->setVertexSize(vertex->getID(), 14);
        }


        gv->addNode(vertex->getID(), (int) (xPercent * width), (int) (yPercent * height));
        //gv->setVertexLabel(vertex->getID(), vertex->getTag());
        //gv->setVertexLabel(vertex->getID(), to_string(vertex->getID()));
    }

    int id = 0;
    for (Vertex<coordinates>* vertex: graph.getVertexSet()){
        vector<int> path_id = path.getPath();
        bool found = false;
        for (Edge<coordinates>* edge: vertex->getAdj()){
            for (int i = 0; i < path_id.size()-1; i++){
                if (path_id.at(i) == edge->getDest()->getID() && path_id.at(i+1) == vertex->getID()){
                    gv->setEdgeColor(id, "blue");
                    gv->setEdgeThickness(id, 5);
                    gv->addEdge(id,vertex->getID(),edge->getDest()->getID(),EdgeType::UNDIRECTED);
                    found = true;
                    break;
                }
                if (path_id.at(i) == vertex->getID() && path_id.at(i+1) == edge->getDest()->getID()){
                    gv->setEdgeColor(id, "blue");
                    gv->setEdgeThickness(id, 5);
                    gv->addEdge(id,vertex->getID(),edge->getDest()->getID(),EdgeType::DIRECTED);
                    found = true;
                    break;
                }
            }
            if (!found) {
                gv->setEdgeThickness(id, 1);
                switch (edge->getDifficulty()) {
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

                gv->addEdge(id, vertex->getID(), edge->getDest()->getID(), EdgeType::UNDIRECTED);
            }
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

