#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Player;

const string COLOUR_DEFAULT_BACKGROUND = "\e[49m";
const string COLOUR_DEFAULT_FOREGROUND = "\e[39m";

class Block {
protected:
    string name;
    int number;
    vector<Player*> landers;
    
    void repeat(string s, int times);
    void bar7();
    void bar14();
    void bar71();
    void bar7bar14();
    void bar7bar71();
public:
    Block(string name, int number);
    virtual void print(int lineNum, int leftMargin, int topMargin);
    void addLander(Player *p);
    void removeLander(Player *p);
};

#endif
