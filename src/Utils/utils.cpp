#include "utils.h"

void trim(string &str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}

bool isLetter(char a) {
    string alphabet = "abcdefghijklmnopqrstuvwxyzãáàâçéêíõóôúüÃÁÀÂÇÉÊÍÕÓÔÚÜ";
    a = tolower(a);

    return alphabet.find(a) != string::npos;

}

string removeExtraSpaces(string aux) {
    string auxiliar;
    bool spacefound = false;
    trim(aux);

    for (char i : aux) {
        if (i == ' ' && !spacefound) {
            auxiliar += ' ';
            spacefound = true;
        }
        else if (i != ' ') {
            auxiliar += i;
            spacefound = false;
        }
    }

    return auxiliar;
}

void stringFormatting(string &str) {

    str = removeExtraSpaces(str);

    transform(str.begin(), str.end(), str.begin(), ::tolower);//toda a string é colocada em minusculas

    str = " " + str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' && isLetter(str[i + 1])) {
            str[i + 1] = toupper(str[i + 1]);// coloca a primeira letra de cada palavra a maiuscula
        }
    }
    trim(str);
}

string toLower(string const& str){
    string result;
    for (char c: str){
        result += tolower(c);
    }
    return result;
}

vector<int> stringToDataVector(string str){
    string delimiter = ",";
    str = str.substr(1, str.size() - 2);
    vector<string> data;
    vector<int> result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        result.push_back(stoi(i));
    }

    return result;
}