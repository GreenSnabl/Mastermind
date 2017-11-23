#include "Mastermind.h"
using std::cout;
using std::cin;
using std::vector;
using std::string;



vector<int> Mastermind::get_code()
{
    
    string code;
    while(true)
    {
        vector<int> codeVec;
        cin >> code;
        if(code.size() == size) 
        {
            for(int i = 0; i < size; ++i)
                codeVec.push_back(code[i]-48);
            if(isValidInput(codeVec, size, min, max)) return codeVec;
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
        vector<int> guess;
        cout << "Runde " << counter + 1 
             << "\n\nWie lautet ihr Tipp?\n";
        guess = get_code();
        cout << "\n\nIhr Tipp:\t\t";
        for (int i = 0; i < size; ++i)
            cout << guess[i];
        cout << "\nSchwarze Marker:\t" << black(solution, guess) 
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
         << "\t\tZu Spielbeginn legt Spieler 1 einen "<< size << "-stelligen Lösungscode fest.\n\n"
         << "\t\tDer Lösungscode besteht aus den Ziffern \"" << min << "-" << max << "\".\n\n"
         << "\t\tJede Ziffer darf maximal einmalig verwendet werden.\n\n\n"
         << "\t\tSpieler 2 stehen nun 8 Raterunden  zur Verfügung.\n\n"
         << "\t\tNach jeder Runde erhält Spieler 2 Tipps in Form von schwarzen und weißen Markern.\n\n"
         << "\t\tEin weißer Marker zeigt an, dass eine korrekte Ziffer an einer falschen Position getippt wurde.\n\n"
         << "\t\tEin schwarzer Marker zeigt an, dass eine korrekte Ziffer an der korrekten Stelle getippt wurde.\n\n"
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

