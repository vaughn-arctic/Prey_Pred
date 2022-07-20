//
//  ants.h
//  Doodlebug_Simulation
//
//  Created by Jared Vaughn on 11/16/21.
//


#include <stdio.h>
#include "organism.h"
#include <iostream>
#include "world.h"
#pragma once

using namespace std;

class ants : public organism {
    
public:
    ants();
    ants(int xPos, int yPos, world* grid);
    ~ants();
    void move();
    void breed();
    void starve();
    
    
private:
    
    
};
