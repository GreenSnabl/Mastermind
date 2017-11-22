#ifndef MASTERMINDCHAR_H
#define MASTERMINDCHAR_H

#include "functions.hpp"
#include <vector>
#include <iostream>
#include <string>

void clear_int_stream();
int get_int(int, int);

class Mastermind{

public:
    
    void menu();    
    void play();
    vector<char> get_code();
    void help();
    
private:
    vector<char> solution;
};




#endif /* MASTERMIND_H */

