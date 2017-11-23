#ifndef MASTERMINDCHAR_H
#define MASTERMINDCHAR_H

#include "functions.hpp"
#include <vector>
#include <iostream>
#include <string>
#include "get_ints.h"


class MastermindChar{

public:
    MastermindChar() : min{'a'}, max{'b'}, size{4} {}
    MastermindChar(char minimum, char maximum, int codesize) : min{minimum}, max{maximum}, size{codesize} {}
    void menu();    
    void play();
    vector<char> get_code();
    void help();
    
private:
    vector<char> solution;
    char min;
    char max;
    int size;
};
    
    





#endif /* MASTERMINDCHAR_H */

