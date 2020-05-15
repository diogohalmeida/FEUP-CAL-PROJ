#ifndef EXPLOREIT_GRAPHDISPLAY_H
#define EXPLOREIT_GRAPHDISPLAY_H

#pragma once
#include "../src/Graph/Graph.h"
#include "../lib/graphviewer.h"

class GraphDisplay {
private:
    Graph graph;
    GraphViewer * gv;
    int height;
    int width;
public:
    GraphDisplay(Graph &graph, int width, int height);
    void setGraph(Graph &graph);
    void show();
};


#endif //EXPLOREIT_GRAPHDISPLAY_H
