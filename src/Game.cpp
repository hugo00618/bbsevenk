#include "Game.h"

using namespace std;

void clearScreen(int windowHeight);

Game::Game() {
    // window
    struct winsize myWindowsSize;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &myWindowsSize);
    int myWindowWidth = myWindowsSize.ws_col;
    int myWindowHeight = myWindowsSize.ws_row;
    myLeftMargin = (myWindowWidth-91)/2;
    myTopMargin = (myWindowHeight-58)/2;
    
    // gameboard
    gameboard = new Block*[40];
    gameboard[0] = new NonProperty("Goose Nesting", 20);
    gameboard[1] = new AcademicBuilding("EV1", 21, 220, 18, 150);
    gameboard[2] = new NonProperty("NEEDLES HALL", 22);
    gameboard[3] = new AcademicBuilding("EV2", 23, 220, 18, 150);
    gameboard[4] = new AcademicBuilding("EV3", 24, 240, 20, 150);
    gameboard[5] = new Residence("V1", 25);
    gameboard[6] = new AcademicBuilding("PHYS", 26, 260, 22, 150);
    gameboard[7] = new AcademicBuilding("B1", 27, 260, 22, 150);
    gameboard[8] = new Gym("CIF", 28);
    gameboard[9] = new AcademicBuilding("B2", 29, 280, 24, 150);
    gameboard[10] = new NonProperty("GO TO TIMS", 30);
    gameboard[11] = new AcademicBuilding("OPT", 19, 200, 16, 100);
    gameboard[12] = new AcademicBuilding("EIT", 31, 300, 26, 200);
    gameboard[13] = new AcademicBuilding("BMH", 18, 180, 14, 100);
    gameboard[14] = new AcademicBuilding("ESC", 32, 300, 26, 200);
    gameboard[15] = new NonProperty("SLC", 17);
    gameboard[16] = new NonProperty("SLC", 33);
    gameboard[17] = new AcademicBuilding("LHI", 16, 180, 14, 100);
    gameboard[18] = new AcademicBuilding("C2", 34, 320, 28, 200);
    gameboard[19] = new Residence("UWP", 15);
    gameboard[20] = new Residence("REV", 35);
    gameboard[21] = new AcademicBuilding("CPH", 14, 160, 12, 100);
    gameboard[22] = new NonProperty("NEEDLES HALL", 36);
    gameboard[23] = new AcademicBuilding("DWE", 13, 140, 10, 100);
    gameboard[24] = new AcademicBuilding("MC", 37, 350, 35, 200);
    gameboard[25] = new Gym("PAC", 12);
    gameboard[26] = new NonProperty("COOP FEE", 38);
    gameboard[27] = new AcademicBuilding("RCH", 11, 140, 10, 100);
    gameboard[28] = new AcademicBuilding("DC", 39, 400, 50, 200);
    gameboard[29] = new NonProperty("DC Tims Line", 10);
    gameboard[30] = new AcademicBuilding("HH", 9, 120, 8, 50);
    gameboard[31] = new AcademicBuilding("PAS", 8, 100, 6, 50);
    gameboard[32] = new NonProperty("NEEDLES HALL", 7);
    gameboard[33] = new AcademicBuilding("ECH", 6, 100, 6, 50);
    gameboard[34] = new Residence("MKV", 5);
    gameboard[35] = new NonProperty("TUITION", 4);
    gameboard[36] = new AcademicBuilding("ML", 3, 60, 4, 50);
    gameboard[37] = new NonProperty("SLC", 2);
    gameboard[38] = new AcademicBuilding("AL", 1, 40, 2, 50);
    gameboard[39] = new NonProperty("COLLECT OSAP", 0);
    
    // pieces
    pieces['G'] = "Goose";
    pieces['B'] = "GRT bus";
    pieces['D'] = "Tim Hortons doughnut";
    pieces['P'] = "Professor";
    pieces['S'] = "Student";
    pieces['$'] = "Money";
    pieces['L'] = "Laptop";
    pieces['T'] = "Pink Tie";
    
    // welcome screen
    clearScreen(myWindowHeight);
    cout << setw((myWindowWidth+10)/2) << "Welcome to" << endl;
    cout << setw((myWindowWidth+37)/2) << " _______  _______  ________ __    __ " << endl;
    cout << setw((myWindowWidth+37)/2) << "/       \\/       \\/        /  |  /  |" << endl;
    cout << setw((myWindowWidth+37)/2) << "$$$$$$$  $$$$$$$  $$$$$$$$/$$ | /$$/ " << endl;
    cout << setw((myWindowWidth+37)/2) << "$$ |__$$ $$ |__$$ |   /$$/ $$ |/$$/  " << endl;
    cout << setw((myWindowWidth+37)/2) << "$$    $$<$$    $$<   /$$/  $$  $$<   " << endl;
    cout << setw((myWindowWidth+37)/2) << "$$$$$$$  $$$$$$$  | /$$/   $$$$$  \\  " << endl;
    cout << setw((myWindowWidth+37)/2) << "$$ |__$$ $$ |__$$ |/$$/    $$ |$$  \\ " << endl;
    cout << setw((myWindowWidth+37)/2) << "$$    $$/$$    $$//$$/     $$ | $$  |" << endl;
    cout << setw((myWindowWidth+37)/2) << "$$$$$$$/ $$$$$$$/ $$/      $$/   $$/ " << endl << endl;
    clearScreen((myWindowHeight-9)/2);
    
    sleep(3);
    
    // setup
    printBoard(myWindowWidth, myWindowHeight);
    while (true) {
        cout << "Number of players (2-" << MAX_NUM_OF_PLAYERS << "): ";
        string tmpS;
        cin >> tmpS;
        istringstream ss(tmpS);
        
        if (ss >> numOfPlayers && numOfPlayers >= 2 && numOfPlayers <= MAX_NUM_OF_PLAYERS) {
            players = new Player[numOfPlayers];
            break;
        } else {
            printBoard(myWindowWidth, myWindowHeight);
            cout << "Please enter a number between 2 and " << MAX_NUM_OF_PLAYERS << "." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    
    printBoard(myWindowWidth, myWindowHeight);
    for (int i = 0; i < numOfPlayers; i++) {
        cout << "Player " << i+1 << "'s name: ";
        string tmpS;
        cin >> tmpS;
        players[i].setName(tmpS);
        players[i].setNumber(i+1);
        printBoard(myWindowWidth, myWindowHeight);
        
        while (true) {
            cout << "Available pieces:" << endl;
            for (map<char,string>::iterator it = pieces.begin(); it != pieces.end(); it++) {
                cout << it->first << " " << it->second << endl;
            }
            
            char tmpC;
            cout << players[i].getName() << "'s piece: ";
            cin >> tmpS;
            istringstream ss(tmpS);
            ss >> tmpC;
            players[i].setPiece(tmpC);
            
            if (pieces[tmpC] == "") {
                printBoard(myWindowWidth, myWindowHeight);
                cout << tmpS << " is not available, please try again." << endl;
                pieces.erase(tmpC);
                cin.clear();
                cin.ignore();
            } else {
                players[i].setPiece(tmpC);
                pieces.erase(tmpC);
                printBoard(myWindowWidth, myWindowHeight);
                break;
            }
        }
        
        while (true) {
            cout << "Is " << players[i].getName() << " a robot player? (y/n): ";
            cin >> tmpS;
            if (tmpS == "y") {
                while (true) {
                    cout << "On a scale of 1 to 3, select the easiness: ";
                    cin >> tmpS;
                    stringstream ss(tmpS);
                    int easinessLv;
                    if (ss >> easinessLv && easinessLv >= 1 && easinessLv <= 3) {
                        // create a robot player
                        printBoard(myWindowWidth, myWindowHeight);
                        break;
                    } else {
                        printBoard(myWindowWidth, myWindowHeight);
                        cout << "Please enter a number from 1 to 3." << endl;
                    }
                }
                break;
            } else if (tmpS == "n") {
                break;
            } else {
                printBoard(myWindowWidth, myWindowHeight);
                cout << "Please enter either y or n." << endl;
            }
        }
        
        gameboard[39]->addLander(&players[i]);
        printBoard(myWindowWidth, myWindowHeight);
    }
    
    // play game
}

Game::~Game() {
    for (int i = 0; i < 40; i++) {
        delete gameboard[i];
    }
    delete [] gameboard;
}

void Game::play() {
    
}

void clearScreen(int windowHeight) {
    for (int i = 0; i < windowHeight; i++) {
        cout << endl;
    }
}

void Game::printBoard(int myWindowWidth, int myWindowHeight) {
    clearScreen(myWindowHeight);
    
    cout << setw(myLeftMargin+1) << "";
    for (int i = 0; i < 11; i++) {
        if (dynamic_cast<NonProperty*>(gameboard[i])) {
            for (int j = 0; j < 8; j++) {
                cout << " ";
            }
        } else {
            Property *p = dynamic_cast<Property*>(gameboard[i]);
            p->printOwnership();
        }
    }
    cout << endl;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 11; j < 13; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 13; j < 15; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 15; j < 17; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 17; j < 19; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 19; j < 21; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 21; j < 23; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 23; j < 25; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 25; j < 27; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 27; j < 29; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 29; j < 40; j++) {
            gameboard[j]->print(i+1, myLeftMargin, myTopMargin);
        }
        cout << endl;
    }
    
    cout << setw(myLeftMargin+1) << "";
    for (int i = 0; i < 11; i++) {
        cout << "|_______";
    }
    cout << "|" << endl;
    
    cout << setw(myLeftMargin+1) << "";
    for (int i = 29; i < 40; i++) {
        if (dynamic_cast<NonProperty*>(gameboard[i])) {
            for (int j = 0; j < 7; j++) {
                cout << " ";
            }
        } else {
            Property *p = dynamic_cast<Property*>(gameboard[i]);
            p->printOwnership();
        }
    }
    cout << endl;
    
    clearScreen(myTopMargin);
}

void Game::printHelp(int myWindowWidth, int myWindowHeight) {
    clearScreen(myWindowHeight);
    
    cout << setw((myWindowWidth+16)/2) << "LIST OF COMMANDS" << endl << endl;
    
    int leftMargin = (myWindowWidth - 16) / 2 - 37;
    
    cout << setw(leftMargin) << "" << left << "Single Player Action" << endl;
    cout << setw(leftMargin) << "" << left << "    roll                             Roll two dice" << endl;
    cout << setw(leftMargin) << "" << left << "    next                             End your turn" << endl;
    cout << setw(leftMargin) << "" << left << "    assets (<player>)                Display the assets of <player> or the current player if <player> is not specified" << endl;
    cout << setw(leftMargin) << "" << left << "    leave <cash/cup>                 Leave the DC Tims Line by either paying $50 or using a Roll Up the Rim cup" << endl;
    cout << setw(leftMargin) << "" << left << "    bankrupt                         Declare bankruptcy" << endl << endl;
    
    cout << setw(leftMargin) << "" << left << "Property Action" << endl;
    cout << setw(leftMargin) << "" << left << "    improve <property> <buy/sell>    <buy> or <sell> an improvement for <property>" << endl;
    cout << setw(leftMargin) << "" << left << "    mortgage <property>              Mortgage <property>" << endl;
    cout << setw(leftMargin) << "" << left << "    unmortgage <property>            Unmortgage <property>" << endl << endl;
    
    cout << setw(leftMargin) << "" << left << "Multi-Player Action" << endl;
    cout << setw(leftMargin) << "" << left << "    trade <name> <give> <receive>    Offer a trade to <name> with the current player offering <give> and requesting <receive>" << endl;
    cout << setw(leftMargin) << "" << left << "    accept                           Accept the given offer" << endl;
    cout << setw(leftMargin) << "" << left << "    reject                           Reject the given offer" << endl << endl;
    
    cout << setw(leftMargin) << "" << left << "Game Action" << endl;
    cout << setw(leftMargin) << "" << left << "    save <filename>                  Save the current state of the game to <filename>" << endl;
    
    clearScreen((myWindowHeight-21)/2);
}
