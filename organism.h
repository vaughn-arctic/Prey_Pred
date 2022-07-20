//
//  organism.h
//  Doodlebug_Simulation
//
//  Created by Jared Vaughn on 11/16/21.
//'
#pragma once
#include <stdio.h>
#include <iostream>
#include "world.h"


using namespace std; 


class organism {
protected:
    char symbol;
    int xPos;
    int yPos;
    int age;
    world* theWorld;
    bool alive;
    bool moved;
    bool breeded;
    
    
public:
    //creator
    organism();
    organism(int xPos, int yPos,world* grid);
    ~organism();
    
    
    //setter
    void setXY(int x, int y);
    void setAge(int newAge);
    void setWorld(world* a); 
    void has_Moved(bool a);
    bool get_breed();
    void set_breed(bool a);
    
    void died();
    
    virtual void move();
    virtual void breed();
    void virtual starve();
    char output();
    
    
};
