//
//  ants.cpp
//  Doodlebug_Simulation
//
//  Created by Jared Vaughn on 11/16/21.
//




#include <stdio.h>
#include "ants.h"
#include <iostream>
using namespace std;

ants::ants() : organism() {
    
    symbol = 'o';
    breeded = 1; 
    
    
}

ants::ants(int xPos, int yPos, world* grid) : organism(xPos, yPos, grid) {
    symbol = 'o';
    
}

void ants::starve() {};

void ants::breed() {
    if (age % 3 == 0) {
        if ((theWorld->grid[xPos+1][yPos] == nullptr) & (xPos + 1 < 20)){
        
            organism* ant = new ants(xPos+1, yPos, theWorld);
            theWorld->set_grid(xPos+1, yPos, ant);
        }
    
        else if ((theWorld->grid[xPos-1][yPos] == nullptr) && (xPos - 1 >= 0) ) {
            organism* ant = new ants(xPos-1, yPos, theWorld);
            theWorld->set_grid(xPos-1, yPos, ant);
            
        }
        
        else if ((theWorld->grid[xPos][yPos-1] == nullptr) && (yPos - 1 >= 0 )) {
            organism* ant = new ants(xPos, yPos - 1, theWorld);
            theWorld->set_grid(xPos, yPos - 1, ant);
        }
        
        else if ((theWorld->grid[xPos][yPos+1] == nullptr) && (yPos+1 < 20)) {
            organism* ant = new ants(xPos, yPos + 1, theWorld);
            theWorld->set_grid(xPos, yPos + 1, ant);
        }
            
        else {}
        
    }
}

void ants::move(){
    if (moved != true) {
        
        int a = rand() % 4;
        //freaking x and y are backwards
        
        // had to set limits within the simulation grid
        // otherwise it would just keep going and overwrite
       
       
        
        if (a == 0) {
            //up
            if ((theWorld->grid[xPos-1][yPos] == nullptr) && (xPos - 1 >= 0) )  {
                theWorld->set_grid(xPos - 1, yPos, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                xPos -= 1;
                this->setWorld(theWorld);
                
            }
            
            //left
            
            else if ((theWorld->grid[xPos][yPos-1] == nullptr) && (yPos - 1 >= 0 )) {
                theWorld->set_grid(xPos, yPos-1, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                yPos -= 1;
                this->setWorld(theWorld);
                
            }
            
           
            //down
            else if ((theWorld->grid[xPos+1][yPos] == nullptr) && (xPos + 1 < 20) ){
                theWorld->set_grid(xPos + 1, yPos, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                xPos += 1;
                this->setWorld(theWorld);
                
            }
            
            // right
            else if ((theWorld->grid[xPos][yPos+1] == nullptr) && (yPos+1 < 20)) {
                theWorld->set_grid(xPos, yPos+1, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                yPos += 1;
                this->setWorld(theWorld);
                
            }
            else {
                
            }
            
            setAge(age+1);
            has_Moved(true);
        
    }
        
        else if (a == 1) {
            if ((theWorld->grid[xPos][yPos-1] == nullptr) && (yPos - 1 >= 0 )) {
                theWorld->set_grid(xPos, yPos-1, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                yPos -= 1;
                this->setWorld(theWorld);
                
            }
            
           
            //down
            else if ((theWorld->grid[xPos+1][yPos] == nullptr) && (xPos + 1 < 20) ){
                theWorld->set_grid(xPos + 1, yPos, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                xPos += 1;
                this->setWorld(theWorld);
                
            }
            
            // right
            else if ((theWorld->grid[xPos][yPos+1] == nullptr) && (yPos+1 < 20)) {
                theWorld->set_grid(xPos, yPos+1, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                yPos += 1;
                this->setWorld(theWorld);
                
            }
            
            else if ((theWorld->grid[xPos-1][yPos] == nullptr) && (xPos - 1 >= 0) )  {
                theWorld->set_grid(xPos - 1, yPos, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                xPos -= 1;
                this->setWorld(theWorld);
                
            }
            
            else {
                
            }
            
            setAge(age+1);
            has_Moved(true);
        
        }
        
        else if (a == 2) {
            if ((theWorld->grid[xPos+1][yPos] == nullptr) && (xPos + 1 < 20) ){
                theWorld->set_grid(xPos + 1, yPos, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                xPos += 1;
                this->setWorld(theWorld);
                
            }
            
            // right
            else if ((theWorld->grid[xPos][yPos+1] == nullptr) && (yPos+1 < 20)) {
                theWorld->set_grid(xPos, yPos+1, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                yPos += 1;
                this->setWorld(theWorld);
                
            }
            
            else if ((theWorld->grid[xPos-1][yPos] == nullptr) && (xPos - 1 >= 0) )  {
                theWorld->set_grid(xPos - 1, yPos, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                xPos -= 1;
                this->setWorld(theWorld);
                
            }
            
            else if ((theWorld->grid[xPos][yPos-1] == nullptr) && (yPos - 1 >= 0 )) {
                theWorld->set_grid(xPos, yPos-1, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                yPos -= 1;
                this->setWorld(theWorld);
            }
            
            else {
                
            }
            
            setAge(age+1);
            has_Moved(true);
        }
        else {
            
            if ((theWorld->grid[xPos][yPos+1] == nullptr) && (yPos+1 < 20)) {
                theWorld->set_grid(xPos, yPos+1, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                yPos += 1;
                this->setWorld(theWorld);
                
            }
            
            else if ((theWorld->grid[xPos-1][yPos] == nullptr) && (xPos - 1 >= 0) )  {
                theWorld->set_grid(xPos - 1, yPos, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                xPos -= 1;
                this->setWorld(theWorld);
                
            }
            
            else if ((theWorld->grid[xPos][yPos-1] == nullptr) && (yPos - 1 >= 0 )) {
                theWorld->set_grid(xPos, yPos-1, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                yPos -= 1;
                this->setWorld(theWorld);
            }
            
            else if ((theWorld->grid[xPos+1][yPos] == nullptr) && (xPos + 1 < 20) ){
                theWorld->set_grid(xPos + 1, yPos, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                xPos += 1;
                this->setWorld(theWorld);
                
            }
            
            else {
                
            }
            
            setAge(age+1);
            has_Moved(true);
            }
            
            
        }
}
