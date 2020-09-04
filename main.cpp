#include "src/Interface/menu.h"


void generateGraphDijsktra(vector<Graph<coordinates>> &regions);
void generateGraphBFS(vector<Graph<coordinates>> &regions);
void generateGraphDFS(vector<Graph<coordinates>> &regions);

int main() {
    cout << "Hello There! Welcome to ExploreIT!" << endl;
    cout << "Loading region maps..." << endl;
    //Read region data from files
    vector<Graph<coordinates>> regions = readAllRegions();
    Graph<coordinates> region = regions.at(1);


    //Main menu call
    while (mainMenu(regions) != 0);


    //To generate the graphs for the report
    //generateGraphDijsktra(regions);
    //generateGraphDFS(regions);
    //generateGraphBFS(regions);


    cout << "Thank you for using ExploreIT! Have a great tour!" << endl;


	return 0;
}

void generateGraphDijsktra(vector<Graph<coordinates>> &regions) {
    srand(time(NULL));
    ofstream outputFile;
    string fileName = "./graph.csv";
    outputFile.open(fileName, ios::app);
    int j = 1000;
    for (int n = 1; n <= 10; n ++) {
        // Start the clock for this n
        auto start = chrono::high_resolution_clock::now();
        // Create 1000 sequences
        for (int i = 0; i < j; i++) {
            int start_id = rand() % regions.at(0).getVertexSet().size();
            if (regions.at(0).findVertex(start_id) == nullptr){
                continue;
            }
            int end = rand() % regions.at(0).getVertexSet().size();
            if (regions.at(0).findVertex(end) == nullptr){
                continue;
            }
            regions.at(0).dijkstraShortestPath(start_id, end);
        }

        // Stop the clock
        auto finish = chrono::high_resolution_clock::now();
        // Get the total time
        auto mili = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
        // Print to the .csv file
        cout << j << " -> " << mili << endl;
        outputFile << j << "," << mili << endl;
        j += 200;
    }
    outputFile.close();
}

void generateGraphBFS(vector<Graph<coordinates>> &regions) {
    srand(time(NULL));
    ofstream outputFile;
    string fileName = "./graph.csv";
    outputFile.open(fileName, ios::app);
    int j = 2000;
    for (int n = 1; n <= 10; n ++) {
        // Start the clock for this n
        auto start = chrono::high_resolution_clock::now();
        // Create 1000 sequences
        for (int i = 0; i < j; i++) {
            int start_id = rand() % regions.at(0).getVertexSet().size();
            if (regions.at(0).findVertex(start_id) == nullptr){
                continue;
            }
            regions.at(0).bfs(start_id);
        }

        // Stop the clock
        auto finish = chrono::high_resolution_clock::now();
        // Get the total time
        auto mili = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
        // Print to the .csv file
        cout << j << " -> " << mili << endl;
        outputFile << j << "," << mili << endl;
        j += 400;
    }
    outputFile.close();
}

void generateGraphDFS(vector<Graph<coordinates>> &regions) {
    srand(time(NULL));
    ofstream outputFile;
    string fileName = "./graph.csv";
    outputFile.open(fileName, ios::app);
    int j = 2000;
    for (int n = 1; n <= 10; n ++) {
        // Start the clock for this n
        auto start = chrono::high_resolution_clock::now();
        // Create 1000 sequences
        for (int i = 0; i < j; i++) {
            int start_id = rand() % regions.at(0).getVertexSet().size();
            if (regions.at(0).findVertex(start_id) == nullptr){
                continue;
            }
            regions.at(0).dfs(start_id);
        }

        // Stop the clock
        auto finish = chrono::high_resolution_clock::now();
        // Get the total time
        auto mili = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
        // Print to the .csv file
        cout << j << " -> " << mili << endl;
        outputFile << j << "," << mili << endl;
        j += 400;
    }
    outputFile.close();
}
