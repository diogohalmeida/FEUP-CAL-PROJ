#include "menu.h"


int displayMenu(vector<Graph> regions){
    cout << "==================== Display a Region ====================" << endl;
    cout << "Please select the desired region  to display: " << endl;
    cout << "1. Aveiro" << endl;
    cout << "2. Ermesinde" << endl;
    cout << "3. Fafe" << endl;
    cout << "4. Gondomar" << endl;
    cout << "5. Maia" << endl;
    cout << "6. Porto" << endl;
    cout << "7. Viseu" << endl;
    cout << "0. Go Back to Main Menu" << endl;
    cout << "===================================================" << endl << endl;
    int choice;
    verifyMenuOptions(choice,0,7);
    string city;
    Graph graph;
    switch(choice){
        case 0:
            return 0;
        case 1:
            graph = regions.at(0);
            break;
        case 2:
            graph = regions.at(1);
            break;
        case 3:
            graph = regions.at(2);
            break;
        case 4:
            graph = regions.at(3);
            break;
        case 5:
            graph = regions.at(4);
            break;
        case 6:
            graph = regions.at(5);
            break;
        case 7:
            graph = regions.at(6);
            break;
    }
    GraphDisplay gd(graph, 1280, 720);
    gd.show();
    cout << "Now showing " + graph.getRegion() + "'s rural region..." << endl;
    cout << "Please close the map's window before proceeding" << endl;
    system("pause");
    cout << endl << endl;
    return 0;
}



int mainMenu(vector<Graph> regions){
    cout << "==================== Main Menu ====================" << endl;
    cout << "Please select the desired option: " << endl;
    cout << "1. Display a region's map" << endl;
    cout << "2. Plan a tour" << endl;
    cout << "0. Exit program" << endl;
    cout << "===================================================" << endl << endl;
    int choice;
    verifyMenuOptions(choice,0,2);
    switch(choice){
        case 0:
            return 0;
        case 1:
            while (displayMenu(regions) != 0);
            return 1;
    }
    return 0;
}