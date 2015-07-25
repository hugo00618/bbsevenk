#include "Property.h"
#include "Player.h"

Property::Property(string name, int number, int purchaseCost, int baseTuition): Block(name, number), purchaseCost(purchaseCost), baseTuition(baseTuition), combo(false) {
    
}

void Property::setOwner(Player &p) {
    owner = &p;
}

int Property::getPurchaseCost() {
    return purchaseCost;
}

void Property::printOwnership() {
    if ((number >= 0 && number <= 10) || (number >= 20 && number <= 30)) {
        if (owner) {
            if (combo) {
                cout << "   " << owner->getColour() << "*****" << COLOUR_DEFAULT << " ";
            } else {
                cout << "   " << owner->getColour() << "     " << COLOUR_DEFAULT << " ";
            }
        } else {
            cout << setw(7) << "";
        }
    }
}
