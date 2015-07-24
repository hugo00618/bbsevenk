#ifndef __NONPROPERTY_H__
#define __NONPROPERTY_H__

#include <iostream>
#include "Block.h"
#include "Player.h"

class NonProperty: public Block {
public:
    NonProperty(string name, int number);
    void effect();
};

#endif
