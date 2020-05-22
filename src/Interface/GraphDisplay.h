#ifndef EXPLOREIT_GRAPHDISPLAY_H
#define EXPLOREIT_GRAPHDISPLAY_H

#pragma once
#include "../src/Graph/Graph.h"
#include "../lib/graphviewer.h"

class GraphDisplay {
private:
    Graph<coordinates> graph;
    GraphViewer * gv;
    int height;
    int width;
public:
    GraphDisplay(Graph<coordinates> &graph, int width, int height);
    void setGraph(Graph<coordinates> &graph);
    void show();
    void close();
};


#endif //EXPLOREIT_GRAPHDISPLAY_H
