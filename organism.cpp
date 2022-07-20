//
//  organism.cpp
//  Doodlebug_Simulation
//
//  Created by Jared Vaughn on 11/16/21.
//

#include <stdio.h>
#include "organism.h"
#include <iostream>
using namespace std;


organism::organism() {
    
}

organism::organism(int xPos, int yPos, world* grid) : xPos(xPos), yPos(yPos), age(0), theWorld(grid), alive(1), moved(0), breeded(1) {}

bool organism::get_breed() {
    return breeded; 
}

void organism::set_breed(bool a) {
    breeded = a; 
}

char organism::output() {
     return symbol; 
}

void organism::has_Moved(bool a){
    moved = a; 
}

void organism::setWorld(world* a) {
    theWorld = a;
}

void organism::setAge(int newAge) {
    age = newAge;
}

void organism::move() {
    if (moved != true) {
        //freaking x and y are backwards
        
        // had to set limits within the simulation grid
        // otherwise it would just keep going and overwrite
       
        //up
        
        has_Moved(true);
    
    }
    
    
}
void organism::breed() {
    
}


void organism::starve(){}

organism::~organism(){}
