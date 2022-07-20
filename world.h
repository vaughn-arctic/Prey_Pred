//
//  world.h
//  Doodlebug_Simulation
//
//  Created by Jared Vaughn on 11/16/21.
//


#include <iostream>
#include <ctime>
#pragma once



using namespace std;
class organism;

class world {
    friend class organism;
    friend class ants;
    friend class doodlebug;
    
private:
    organism* grid[20][20];
    
    
public:
    world();
    void world_simulation(); 
    
    void world_output(); 
    void set_grid(int x, int y, organism* a);
    organism* share_grid();
    
    void breed_reset(); 
    void move_reset();
    void move_bug();
    void breed_bug();
    void starve();
    void move_ant();
    void breed_ant(); 
    
    
};
