#include "Gym.h"
#include "Player.h"

Gym::Gym(string name, int number): Property(name, number, 150, 0) {
    
}

int Gym::getTuition(int steps = 0) {
    return 0;
}

void Gym::print(int lineNum, int leftMargin, int topMargin) {
    if (number >= 10 && number <= 20) {
        cout << setw(leftMargin) << "";
    }
    
    if (number == 12) {
        if (lineNum >= 3 && lineNum <= 5) {
            cout << "*";
        } else {
            cout << " ";
        }
    }
    
    switch (lineNum) {
        case 1: {
            if (number == 12) {
                bar7bar71();
            } else {
                repeat("_", 8);
            }
            
            break;
        }
        case 2: {
            cout << "|" << setw(7) << left << name;
            if (number == 12) {
                bar71();
            }
            break;
        }
        case 3: {
            cout << "|";
            repeat(" ", 7);
            if (number == 12) {
                bar71();
            }
            break;
        }
        case 4: {
            cout << setw(8) << left << "|";
            if (number == 12) {
                bar71();
            }
            break;
        }
        case 5: {
            string s = "";
            for (vector<Player*>::iterator it = landers.begin(); it != landers.end(); it++) {
                s.append(string(1, (*it)->getPiece()));
            }
            cout << "|" << setw(7) << left << s;
            if (number == 12) {
                bar71();
            }
            break;
        }
    }
    
}
