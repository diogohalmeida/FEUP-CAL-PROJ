#ifndef EXPLOREIT_UTILS_H
#define EXPLOREIT_UTILS_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void trim(string &str);

bool isLetter(char a);

string removeExtraSpaces(string aux);

void stringFormatting(string &str);

string toLower(string const& str);

vector<int> stringToDataVector(string str);

double euclidianDistance(pair<double, double> p1, pair<double, double> p2);


#endif //EXPLOREIT_UTILS_H
