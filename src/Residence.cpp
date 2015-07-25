#include "Residence.h"
#include "Player.h"

Residence::Residence(string name, int number): Property(name, number, 200, 25) {
    
}

int Residence::getTuition(int steps) {
    return 0;
}

void Residence::print(int lineNum, int leftMargin, int topMargin) {
    if (number >= 10 && number <= 20) {
        cout << setw(leftMargin) << "";
    }
    
    if (number == 15) {
        if (lineNum >= 3 && lineNum <= 5 && owner) {
            if (combo) {
                cout << owner->getColour(COLOUR_TYPE_BACKGROUND) << "*" << COLOUR_DEFAULT_BACKGROUND;
            } else {
                cout << owner->getColour(COLOUR_TYPE_BACKGROUND) << " " << COLOUR_DEFAULT_BACKGROUND;
            }
        } else {
            cout << " ";
        }
    };
    
    switch (lineNum) {
        case 1: {
            if (number == 15) {
                bar7bar14();
                cout << "|  $$$$$$$  $$$$$$$  $$$$$$$$/$$ | /$$/   |";
                repeat(" ", 14);
            } else if (number == 35) {
                bar7();
            } else {
                repeat("_", 8);
            }
            
            break;
        }
        case 2: {
            cout << "|" << setw(7) << left << name;
            if (number == 15) {
                bar14();
                cout << "|  $$ |__$$ $$ |__$$ |   /$$/ $$ |/$$/    |";
                repeat(" ", 14);
            }
            break;
        }
        case 3: {
            cout << "|";
            repeat(" ", 7);
            if (number == 15) {
                bar14();
                cout << "|  $$    $$<$$    $$<   /$$/  $$  $$<     |";
                repeat(" ", 14);
            }
            break;
        }
        case 4: {
            cout << setw(8) << left << "|";
            if (number == 15) {
                bar14();
                cout << "|  $$$$$$$  $$$$$$$  | /$$/   $$$$$  \\    |";
                repeat(" ", 14);
            }
            break;
        }
        case 5: {
            string s = "";
            for (vector<Player*>::iterator it = landers.begin(); it != landers.end(); it++) {
                s.append(string(1, (*it)->getPiece()));
                s.append((*it)->getColour(COLOUR_TYPE_FOREGROUND));
            }
            cout << "|" << setw(7) << left << s << COLOUR_DEFAULT_FOREGROUND;
            if (number == 15) {
                bar14();
                cout << "|  $$ |__$$ $$ |__$$ |/$$/    $$ |$$  \\   |";
                repeat(" ", 14);
            }
            break;
        }
    }
    
    if (number == 35) {
        cout << "|";
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
    
}
