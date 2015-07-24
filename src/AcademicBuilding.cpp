#include "AcademicBuilding.h"
#include "Player.h"

AcademicBuilding::AcademicBuilding(string name, int number, int purchaseCost, int baseTuition, int improvementCost): Property(name, number, purchaseCost, baseTuition), improvementCost(improvementCost), improvementLevel(0) {
    
}

void AcademicBuilding::print(int lineNum, int leftMargin, int topMargin) {
    if (number >= 10 && number <= 20) {
        cout << setw(leftMargin) << "";
    }
    
    switch (lineNum) {
        case 1: {
            if (number == 14) {
                bar7bar14();
                cout << "|  $$    $$/$$    $$//$$/     $$ | $$  |  |";
                repeat(" ", 14);
            } else if (number == 11 || number == 13 || number == 16 || number == 18) {
                bar7bar71();
            } else if (number == 19) {
                bar7();
                cout << "|";
                int j = 0;
                for (int i = 0; i < 71; i++) {
                    if (j == 7) {
                        cout << "|";
                        j = 0;
                    } else {
                        cout << "_";
                        j++;
                    }
                }
            } else if (number == 9 || number == 31 || number == 32 || number == 34 || number == 37 || number == 39) {
                bar7();
            } else {
                repeat("_", 8);
            }
            break;
        }
        case 2: {
            cout << "|";
            string s = "";
            for (int i = 0; i < improvementLevel; i++) {
                s.append("*");
            }
            cout << setw(7) << left << s;
            
            if (number == 11 || number == 13 || number == 16 ||number == 18 || number == 19) {
                bar71();
            } else if (number == 14) {
                bar14();
                cout << "|  $$$$$$$/ $$$$$$$/ $$/      $$/   $$/   |";
                repeat(" ", 14);
            }
            break;
        }
        case 3: {
            string placeHolder = combo? "***": "---";
            cout << "|";
            cout << placeHolder;
            cout << (owner? string(1,owner->getPiece()): "-");
            cout << placeHolder;
            
            if (number == 11 || number == 13 ||number == 18 || number == 19) {
                bar71();
            } else if (number == 14) {
                bar14();
                cout << "|";
                repeat("_", 41);
                cout << "|";
                repeat(" ", 14);
            } else if (number == 16) {
                bar14();
                repeat("_", 43);
                repeat(" ", 14);
            }
            break;
        }
        case 4: {
            cout << "|" << setw(7) << left << name;
            
            if (number == 11 || number == 13 || number == 14 || number == 18 || number == 19) {
                bar71();
            } else if (number == 16) {
                bar14();
                cout << "|   _______  _______  ________ __    __   |";
                repeat(" ", 14);
            }
            break;
        }
        case 5: {
            string s = "";
            for (vector<Player*>::iterator it = landers.begin(); it != landers.end(); it++) {
                s.append(string(1, (*it)->getPiece()));
            }
            cout << "|" << setw(7) << left << s;
            
            if (number == 11 || number == 13 || number == 14 || number == 18 || number == 19) {
                bar71();
            } else if (number == 16) {
                bar14();
                cout << "|  /       \\/       \\/        /  |  /  |  |";
                repeat(" ", 14);
            }
            break;
        }
    }
    
    if ((number >= 30 && number <= 39) || number == 0) {
        cout << "|";
        
    }
}

int AcademicBuilding::getTuition(int steps = 0) {
    return 0;
}
