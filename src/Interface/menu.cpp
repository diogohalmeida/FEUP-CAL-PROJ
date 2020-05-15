#include "menu.h"


int displayMenu(){
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
    switch(choice){
        case 0:
            return 0;
        case 1:
            city = "Aveiro";
            break;
        case 2:
            city = "Ermesinde";
            break;
        case 3:
            city = "Fafe";
            break;
        case 4:
            city = "Gondomar";
            break;
        case 5:
            city = "Maia";
            break;
        case 6:
            city = "Porto";
            break;
        case 7:
            city = "Viseu";
            break;
    }
    Graph graph = readGraph(city);
    GraphDisplay gd(graph, 1920, 1080);
    gd.show();
    cout << "Now showing " + city + "'s rural region..." << endl;
    cout << "Please close the map's window before proceeding" << endl;
    system("pause");
    return 0;
}



int mainMenu(){
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
            while (displayMenu() != 0);
            return 1;
    }
    return 0;
}