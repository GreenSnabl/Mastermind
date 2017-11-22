#include "MastermindChar.h"
using std::cout;
using std::cin;
using std::vector;
using std::string;



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
        else cout << "\nKeine Gültige Eingabe!\n\n"; return -1;
    }

}




vector<char> Mastermind::get_code()
{
    
    string code;
    while(true)
    {
        vector<char> codeVec;
        cin >> code;
        if(code.size() == 4) 
        {
            for(int i = 0; i < 4; ++i)
                codeVec.push_back(code[i]);
            if(isValidInput(codeVec, 4, 'a', 'f')) return codeVec;
        }
        cout << "Bitte geben Sie einen gültigen Code ein!\n";
        
    }
}   



void Mastermind::play() {
    cout << "Geben Sie den Lösungscode ein:\n";
    solution = get_code();
    string flood;
    string floodsign = "#";
    for(int i = 0; i < 500; ++i)
    {
        flood = "";
        if(i < 250){
        for (int j = 0; j < i; ++j)
            flood += floodsign;
        }
        else 
        {
            flood == floodsign;
            for (int j = 250; j<749-i; ++j)
                flood += floodsign;
        }
        flood += floodsign + "\n\n";
        cout << flood;
    }
        
    for(int counter = 0; counter < 8; ++counter)
    {
        vector<char> guess;
        cout << "Runde " << counter + 1 
             << "\n\nWie lautet ihr Tipp?\n";
        guess = get_code();
        cout << "\n\nIhr Tipp:\t\t" << guess[0] << guess[1] << guess[2] << guess[3] 
             << "\nSchwarze Marker:\t" << black(solution, guess) 
             << "\nWeiße Marker:\t\t" << white(solution, guess) << "\n\n";
        if (guess == solution)
        {
            cout << "\nDer Code wurde geknackt!\n\n************************************\n*******  Spieler 2 gewinnt!  *******\n************************************\n\n\n";
            return;
        }
    }
    cout << "\nSpieler 2 konnte den Code nicht innerhalb von 8 Runden knacken. \n\n************************************\n*******  Spieler 1 gewinnt!  *******\n************************************\n\n\n";
}

void Mastermind::help()
{
    cout << "\t\t*** Mastermind  ---  Spielregeln  --- Spiel für 2 Personen   ***\n\n\n"
         << "\t\tZu Spielbeginn legt Spieler 1 einen 4-stelligen Lösungscode fest.\n\n"
         << "\t\tDer Lösungscode besteht aus den Buchstaben \"a-f\".\n\n"
         << "\t\tJeder Buchstabe darf maximal einmalig verwendet werden.\n\n\n"
         << "\t\tSpieler 2 stehen nun 8 Raterunden  zur Verfügung.\n\n"
         << "\t\tNach jeder Runde erhält Spieler 2 Tipps in Form von schwarzen und weißen Markern.\n\n"
         << "\t\tEin weißer Marker zeigt an, dass ein korrekter Buchstabe an einer falschen Position getippt wurde.\n\n"
         << "\t\tEin schwarzer Marker zeigt an, dass ein korrekter Buchstabe an der korrekten Stelle getippt wurde.\n\n"
         << "\t\tSchafft es Spieler 2 nicht den Code innerhalb von 8 Runden zu erraten, hat Spieler 1 das Spiel gewonnen.\n\n";
}



void Mastermind::menu() {
    int select;
    cout << "..Mastermind..\n\n";
    while (true) {
        cout << "Hauptmenü\n\n"
                << "(1) Neues Spiel\n"
                << "(2) Spielregeln\n"
                << "(3) Beenden\n";
        select = get_int(1,3);
        switch (select) {
            case 1: play(); break;
            case 2: help(); break;
            case 3: return;
        }
    }
}
/*
void Mastermind::chooseMode()
{
    int select;
    cout << "Wählen Sie den Spielmodus:\n(1) Zahlencode\n(2) Buchstabencode\n";
    select = get_int(1,2);
    switch (select)
    {
        case 1: case 2: play(select); break;
        case 3: return;
    }
}
*/

