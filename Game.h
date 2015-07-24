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

using namespace std;

class Game {
    static const int MAX_NUM_OF_PLAYERS = 7;

    Block **gameboard;
    int numOfPlayers;
    Player *players;

    struct Piece {
        char symbol;
        string discription;
    };
    map<char, string> pieces;
    
    void printBoard(int myWindowWidth, int myWindowHeight);
public:
    Game();
    ~Game();
    void play();
    void printHelp(int myWindowWidth, int myWindowHeight);
};

#endif
