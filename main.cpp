#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    GraphViewer *gv = new GraphViewer(600, 600, true);
    gv->createWindow(1920, 1080);
	getchar();
	return 0;
}
