//
//  main.cpp
//  Doodlebug_Simulation
//
//  Created by Jared Vaughn on 11/16/21.
//

#include <iostream>
#include "world.h"
#include "organism.h"
#include "doodlebug.h"

int main() {
    //X AND Y ARE BACKWARDS!!!!!
    
    srand(time(NULL)); 
    world big; //initialize the sim
    
    
    //runs the sim allowing the user to conitune or exit
    big.world_simulation();
   
    
}


//TODO
//DIE BUGS... 
