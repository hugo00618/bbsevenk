#include "Property.h"
#include "Player.h"

Property::Property(string name, int number, int purchaseCost, int baseTuition): Block(name, number), purchaseCost(purchaseCost), baseTuition(baseTuition), combo(false) {
    
}

int Property::getPurchaseCost() {
    return purchaseCost;
}


