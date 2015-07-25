#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Property.h"

using namespace std;

const int INITIAL_BALANCE = 1500;

const int COLOUR_TYPE_FOREGROUND = 0;
const int COLOUR_TYPE_BACKGROUND = 1;

class Player {
    string name;
    char piece;
    int number;
    vector<Property*> properties;
    int cash;
    int position;
    int rollingTime;
    int doubleCount;
    int rollDice();
public:
    Player();
    void setName(string name);
    string getName();
    void setPiece(char piece);
    char getPiece();
    void setNumber(int number);
    int getNumber();
    string getColour(int type);
    void roll();
    void next();
    void trade(string tradeWith, vector<Property*> myProperties, vector<Property*> othersProperties);
    void improve();
    void mortage(Property *p);
    void unmortage(Property *p);
    void bankrupt();
    void assets();
    void save(string);
};

#endif
