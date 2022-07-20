//
//  doodlebug.h
//  Doodlebug_Simulation
//
//  This is the program to run the doodlebug vs ants simulation. This program uses inheritance and friend classes to allow the children of the organism class to interact within the 2D array of the world class
//


#include <stdio.h>
#include "organism.h"
#include <iostream>
#pragma once

using namespace std;

class doodlebug : public organism {
    
public:
    doodlebug();
    doodlebug(int xPos, int yPos, world* grid);
    ~doodlebug(); 
    void move();
    void breed();
    void starve();
    void timeEatUp(int val); 
    
private:
    int time_since_eat; 
    
};
