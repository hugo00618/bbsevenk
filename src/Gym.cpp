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
        if (lineNum >= 3 && lineNum <= 5 && owner) {
            if (combo) {
                cout << owner->getColour(COLOUR_TYPE_BACKGROUND) << "*" << COLOUR_DEFAULT_BACKGROUND;
            } else {
                cout << owner->getColour(COLOUR_TYPE_BACKGROUND) << " " << COLOUR_DEFAULT_BACKGROUND;
            }
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
                s.append((*it)->getColour(COLOUR_TYPE_FOREGROUND));
            }
            cout << "|" << setw(7) << left << s << "\e[49m";
            if (number == 12) {
                bar71();
            }
            break;
        }
    }
    
}
