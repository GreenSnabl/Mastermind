#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "functions.hpp"
#include <vector>
#include <iostream>
#include <string>
#include "get_ints.h"

class Mastermind{

public:
    Mastermind() : min{1}, max{6}, size{4} {}
    Mastermind(int minimum, int maximum, int codesize) : min{minimum}, max{maximum}, size{codesize} {}
    void menu();    
    void play();
    vector<int> get_code();
    void help();
    
private:
    vector<int> solution;
    int min;
    int max;
    int size;
};



#endif /* MASTERMIND_H */

