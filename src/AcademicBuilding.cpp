#include "AcademicBuilding.h"
#include "Player.h"

AcademicBuilding::AcademicBuilding(string name, int number, int purchaseCost, int baseTuition, int improvementCost): Property(name, number, purchaseCost, baseTuition), improvementCost(improvementCost), improvementLevel(0) {
    
}

void AcademicBuilding::print(int lineNum, int leftMargin, int topMargin, vector<Player*> players, MyInfoBoard &mib) {
    if (number >= 10 && number <= 20) {
        cout << setw(leftMargin) << "";
    }
    
    if (number == 11 || number == 13 || number == 14 || number == 16 || number == 18 || number == 19) {
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
            if (number == 14) {
                bar7bar14();
                cout << "|  $$    $$/$$    $$//$$/     $$ | $$  |  |";
                repeat(" ", 14);
            } else if (number == 16 || number == 18) {
                bar7bar71();
            } else if (number == 11) {
                if (mib.getInfoBoard().size() > 10) {
                    bar7();
                    cout << "|";
                    repeat(" ", 4);
                    cout << setw(67) << mib.getInfoBoard().at(10);
                } else {
                    bar7bar71();
                }
            } else if (number == 13) {
                if (mib.getInfoBoard().size() > 0) {
                    bar7();
                    cout << "|";
                    repeat(" ", 4);
                    cout << setw(67) << mib.getInfoBoard().at(0);
                } else {
                    bar7bar71();
                }
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
            cout << getColour() << setw(7) << left << s << COLOUR_DEFAULT_BACKGROUND;
            
            if (number == 16 || number == 19) {
                bar71();
            } else if (number == 11) {
                if (mib.getInfoBoard().size() > 11) {
                    cout << "|";
                    repeat(" ", 4);
                    cout << setw(67) << mib.getInfoBoard().at(11);
                } else {
                    bar71();
                }
            } else if (number == 13) {
                if (mib.getInfoBoard().size() > 1) {
                    cout << "|";
                    repeat(" ", 4);
                    cout << setw(67) << mib.getInfoBoard().at(1);
                } else {
                    bar71();
                }
            } else if (number == 14) {
                bar14();
                cout << "|  $$$$$$$/ $$$$$$$/ $$/      $$/   $$/   |";
                repeat(" ", 14);
            } else if (number == 18) {
                cout << "|";
                repeat(" ", 7);
                if (players.size() > 0) {
                    cout << players.at(0)->getColour(COLOUR_TYPE_FOREGROUND);
                    if (players.at(0)->getMyTurn()) {
                        cout << "> ";
                    } else {
                        cout << "  ";
                    }
                    cout << players.at(0)->getPiece() << " ";
                    cout << setw(12) << left << players.at(0)->getName();
                    cout << "$ " << setw(4) << players.at(0)->getCash();
                    cout << COLOUR_DEFAULT_FOREGROUND;
                    repeat(" ", 13);
                } else {
                    repeat(" ", 35);
                }
                
                if (players.size() > 1) {
                    cout << players.at(1)->getColour(COLOUR_TYPE_FOREGROUND);
                    if (players.at(1)->getMyTurn()) {
                        cout << "> ";
                    } else {
                        cout << "  ";
                    }
                    cout << players.at(1)->getPiece() << " ";
                    cout << setw(12) << left << players.at(1)->getName();
                    cout << "$ " << setw(4) << players.at(1)->getCash();
                    cout << COLOUR_DEFAULT_FOREGROUND;
                    repeat(" ", 7);
                } else {
                    repeat(" ", 29);
                }
            }
            break;
        }
        case 3: {
            cout << "|";
            repeat("-", 7);
            
            if (number == 18 || number == 19) {
                bar71();
            } else if (number == 11) {
                if (mib.getInfoBoard().size() > 12) {
                    cout << "|";
                    repeat(" ", 4);
                    cout << setw(67) << mib.getInfoBoard().at(12);
                } else {
                    bar71();
                }
            } else if (number == 13) {
                if (mib.getInfoBoard().size() > 2) {
                    cout << "|";
                    repeat(" ", 4);
                    cout << setw(67) << mib.getInfoBoard().at(2);
                } else {
                    bar71();
                }
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
            
            if (number == 14 || number == 19) {
                bar71();
            } else if (number == 11) {
                if (mib.getInfoBoard().size() > 13) {
                    cout << "|";
                    repeat(" ", 4);
                    cout << setw(67) << mib.getInfoBoard().at(13);
                } else {
                    bar71();
                }
            } else if (number == 13) {
                if (mib.getInfoBoard().size() > 3) {
                    cout << "|";
                    repeat(" ", 4);
                    cout << setw(67) << mib.getInfoBoard().at(3);
                } else {
                    bar71();
                }
            } else if (number == 16) {
                bar14();
                cout << "|   _______  _______  ________ __    __   |";
                repeat(" ", 14);
            } else if (number == 18) {
                cout << "|";
                repeat(" ", 7);
                if (players.size() > 2) {
                    cout << players.at(2)->getColour(COLOUR_TYPE_FOREGROUND);
                    if (players.at(2)->getMyTurn()) {
                        cout << "> ";
                    } else {
                        cout << "  ";
                    }
                    cout << players.at(2)->getPiece() << " ";
                    cout << setw(12) << left << players.at(2)->getName();
                    cout << "$ " << setw(4) << players.at(2)->getCash();
                    cout << COLOUR_DEFAULT_FOREGROUND;
                    repeat(" ", 13);
                } else {
                    repeat(" ", 35);
                }
                
                if (players.size() > 3) {
                    cout << players.at(3)->getColour(COLOUR_TYPE_FOREGROUND);
                    if (players.at(3)->getMyTurn()) {
                        cout << "> ";
                    } else {
                        cout << "  ";
                    }
                    cout << players.at(3)->getPiece() << " ";
                    cout << setw(12) << left << players.at(3)->getName();
                    cout << "$ " << setw(4) << players.at(3)->getCash();
                    cout << COLOUR_DEFAULT_FOREGROUND;
                    repeat(" ", 7);
                } else {
                    repeat(" ", 29);
                }
            }
            break;
        }
        case 5: {
            string s = "";
            int count = 0;
            for (vector<Player*>::iterator it = landers.begin(); it != landers.end(); it++) {
                count++;
                s.append((*it)->getColour(COLOUR_TYPE_FOREGROUND));
                s.append(string(1, (*it)->getPiece()));
            }
            
            cout << "|" << s << COLOUR_DEFAULT_FOREGROUND;
            repeat(" ", 7-count);
            
            if (number == 11 || number == 13 || number == 14 || number == 18 || number == 19) {
                bar71();
            } else if (number == 13) {
                if (mib.getInfoBoard().size() > 4) {
                    cout << "|";
                    repeat(" ", 4);
                    cout << setw(67) << mib.getInfoBoard().at(4);
                } else {
                    bar71();
                }
            } else if (number == 16) {
                bar14();
                cout << "|  /       \\/       \\/        /  |  /  |  |";
                repeat(" ", 14);
            }
            break;
        }
    }
    
    if ((number >= 30 && number <= 39)) {
        cout << "|";
        if (lineNum >= 3 && lineNum <= 5 && owner) {
            if (combo) {
                cout << owner->getColour(COLOUR_TYPE_BACKGROUND) << "*" << COLOUR_DEFAULT_BACKGROUND;
            } else {
                cout << owner->getColour(COLOUR_TYPE_BACKGROUND) << " " << COLOUR_DEFAULT_BACKGROUND;
            }
        }
    }
}

int AcademicBuilding::getTuition(int steps = 0) {
    return 0;
}

string AcademicBuilding::getColour() {
    string colour = "\e[48;5;";
    
    if (number == 1 || number == 3) {
        colour.append("130");
    } else if (number == 6 || number == 8 || number == 9) {
        colour.append("172");
    } else if (number == 11 || number == 13 || number == 14) {
        colour.append("54");
    } else if (number == 16 || number == 18 || number == 19) {
        colour.append("30");
    } else if (number == 21 || number == 23 || number == 24) {
        colour.append("142");
    } else if (number == 26 || number == 27 || number == 29) {
        colour.append("32");
    } else if (number == 31 || number == 32 || number == 34) {
        colour.append("111");
    } else if (number == 37 || number == 39) {
        colour.append("162");
    }
    colour.append("m");
    
    return colour;
}
