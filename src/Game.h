#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <vector>
#include <map>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <iomanip>

#include "Block.h"
#include "Player.h"
#include "NonProperty.h"
#include "AcademicBuilding.h"
#include "Residence.h"
#include "Gym.h"
#include "MyInfoBoard.h"

using namespace std;

const int MAX_NUM_OF_PLAYERS = 7;

class Game {
    Block **gameboard;
    int numOfPlayers;
    vector<Player*> players;
    MyInfoBoard mib;

    struct Piece {
        char symbol;
        string discription;
    };
    map<char, string> pieces;
    int myLeftMargin, myTopMargin;
    
    void printBoard(int myWindowWidth, int myWindowHeight);
public:
    Game();
    ~Game();
    void play();
    void printHelp(int myWindowWidth, int myWindowHeight);
};

#endif
