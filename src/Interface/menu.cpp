#include "menu.h"


int tourMenu(vector<Graph<coordinates>> regions){
    int size;
    cout << endl << "==================== Plan a Tour ====================" << endl;
    cout << "Please insert the size of the tour group (0 to go back to the Main Menu): ";
    verifyMenuOptions(size, 0, 30);
    if (size == 0){
        return 0;
    }
    vector<Worker> workers;
    int duration, single;
    cout << endl << "Tour's duration: Please keep in mind all tours start at 9:00 and can last up to 10 hours (with a 6 hour minimum duration)";
    cout << endl << "Please insert the tour's duration (in hours): ";
    verifyMenuOptions(duration, 6, 10);
    cout << endl << "Do you which to stay together as a group after lunch? (0 for NO / 1 for YES)";
    verifyMenuOptions(single, 0, 1);
    cout << endl << "Now, insert the information about each member of the group: " << endl;
    for (int i = 1; i <= size; i++){
        string name;
        int skill;
        cout << "====================" << endl;
        cout << "Member " + to_string(i) << endl;
        cout << "Name: ";
        cin >> name;
        verifyAllLetters(name);
        cout << "Tour Skill (1 to 4): ";
        cin >> skill;
        Worker toAdd(name, skill, duration, Path({}));
        workers.push_back(toAdd);
        cout << endl << "Processing Tour..." << endl;
    }


    vector<Path> paths = tourGenerator(regions.at(1), workers, single);
    givePathsToWorkers(workers,paths);
    int choice;

    while (true) {
        cout << endl << "==================== Tour paths generated! ====================" << endl;
        cout << "Please insert the number of the member to see their path (0 to go back to the Main Menu): " << endl;
        int count = 1;
        for (Worker worker: workers) {
            cout << count << " - " << worker.getName() << endl;
            count++;
        }
        cout << endl << "===============================================================" << endl;
        verifyMenuOptions(choice, 0, workers.size());
        if (choice == 0){
            break;
        }

        cout << "Path: ";
        for (int id: workers.at(choice-1).getPath().getPath()){
            cout << id << " -> ";
        }
        cout << endl << "Number of nodes: " << workers.at(choice-1).getPath().getPath().size() << endl;
        if (workers.at(choice-1).getPath().getMaxDifficulty() > workers.at(1).getSkill())
            cout << "Difficulty: " << workers.at(choice-1).getPath().getMaxDifficulty() << "< - Warning: the tour's difficulty exceeds the skill of the member  " << endl;
        else
            cout << "Difficulty: " << workers.at(choice-1).getPath().getMaxDifficulty();
        cout << "\nTotal Distance: " << workers.at(choice-1).getPath().getDistance() << endl;

        GraphDisplay gd(regions.at(1), 1280, 720);
        gd.showPath(workers.at(choice-1).getPath());
    }
    return 0;
}



int displayMenu(vector<Graph<coordinates>> regions){
    cout << endl << "==================== Display Region ====================" << endl;
    cout << "Please select the desired section to display: " << endl;
    cout << "1. Penafiel - Full Region" << endl;
    cout << "2. Penafiel - Rural Region (for Tours)" << endl;
    cout << "0. Go Back to Main Menu" << endl;
    cout << "========================================================" << endl << endl;
    int choice;
    cout << "Choose an option from the menu (integer number): ";
    verifyMenuOptions(choice,0,2);
    string city;
    Graph<coordinates> graph;
    switch(choice){
        case 0:
            return 0;
        case 1:
            graph = regions.at(0);
            break;
        case 2:
            graph = regions.at(1);
            break;
    }
    GraphDisplay gd(graph, 1280, 720);
    gd.show();
    cout << "Now showing the selected section of the region..." << endl;
    cout << endl << endl;
    return 0;
}



int mainMenu(vector<Graph<coordinates>> regions){
    cout << "==================== Main Menu ====================" << endl;
    cout << "Please select the desired option: " << endl;
    cout << "1. Display the region's map" << endl;
    cout << "2. Plan a tour" << endl;
    cout << "0. Exit program" << endl;
    cout << "===================================================" << endl << endl;
    int choice;
    cout << "Choose an option from the menu (integer number): ";
    verifyMenuOptions(choice,0,2);
    switch(choice){
        case 0:
            return 0;
        case 1:
            while (displayMenu(regions) != 0);
            return 1;
        case 2:
            while (tourMenu(regions) != 0);
            return 1;
    }
    return 0;
}