#include "Mastermind.h"
#include "MastermindChar.h"

using std::string;
using std::cout;
using std::cin;
using std::vector;

int main() {
    
    Mastermind m(1,6,4);
    m.menu();

    MastermindChar mc('a', 'f', 4);
    mc.menu();
    
    
    return 0;
}

