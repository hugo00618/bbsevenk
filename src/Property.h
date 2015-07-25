#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include <iostream>

#include "Block.h"

using namespace std;

class Player;

class Property: public Block {
protected:
    Player *owner;
    int purchaseCost;
    int baseTuition;
    bool combo;
public:
    Property(string name, int number, int purchaseCost, int bastTuition);
    void setOwner(Player &p);
    int getPurchaseCost();
    virtual int getTuition(int steps) = 0;
    void printOwnership();
};

#endif
