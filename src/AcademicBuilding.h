#ifndef __ACADEMIC_BUILDING_H__
#define __ACADEMIC_BUILDING_H__

#include <iostream>
#include <iomanip>

#include "Property.h"

class AcademicBuilding: public Property {
    int improvementCost;
    int improvementLevel;
    
    string getColour();
public:
    AcademicBuilding(string name, int number, int purchaseCost, int bastTuition, int improvementCost);
    void print(int lineNum, int leftMargin, int topMargin);
    int getTuition(int steps);
    int getImprovementCost();
};

#endif
