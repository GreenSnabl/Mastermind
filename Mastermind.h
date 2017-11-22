#ifndef MASTERMIND_H
#define MASTERMIND_H

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
    vector<int> get_code();
    void help();
    
private:
    vector<int> solution;
};




#endif /* MASTERMIND_H */

