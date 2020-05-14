#include <cstdio>
#include "graphviewer.h"
#include <vector>
#include "../src/Utils/readFileGraph.h"
#include "src/Interface/graphDisplay.h"

int main() {
    Graph graph = readGraph("Porto");
    graphDisplay gd(graph, 1920, 1080);
    gd.show();

    getchar();
	return 0;
}
