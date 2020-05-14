#include "utils.h"


string toLower(string const str){
    string result;
    for (char c: str){
        result += tolower(c);
    }
    return result;
}