#include "Mastermind.h"
#include "MastermindChar.h"

using std::string;
using std::cout;
using std::cin;
using std::vector;

int main() {
    
    Mastermind m(1,9,5);
    m.menu();

    MastermindChar mc('a', 'm', 6);
    mc.menu();
    
    
    return 0;
}

