#include "get_ints.h"
using std::cin; using std::cout;


void clear_int_stream() {
    if (cin.fail()) {
        cin.clear();
        for (char ch; cin >> ch;)
                return;
    }
}

int get_int() {
    int input = 0;                      
    while (true) {
        if (cin >> input) return input;
        clear_int_stream();
        return -1;
    }
}

int get_int(int low, int high) {
    while (true) {
        int n = get_int();
        if (low <= n && n <= high) return n;
        else{ cout << "\nKeine Gültige Eingabe!\n\n"; cin.ignore(1000, '\n'); return -1;}
    }

}


