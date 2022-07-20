//
//  doodlebug.cpp
//  Doodlebug_Simulation
//
//  Created by Jared Vaughn on 11/16/21.
//

#include <stdio.h>
#include "doodlebug.h"
#include <iostream>
using namespace std;

doodlebug::doodlebug() : organism() {
    
    symbol = 'X';
    time_since_eat = 0;
    breeded = 1; 
    
}

doodlebug::doodlebug(int xPos, int yPos, world* grid) : organism(xPos, yPos, grid) {
    symbol = 'X';
    time_since_eat = 0;
}

doodlebug::~doodlebug(){}

void doodlebug::timeEatUp(int val){
    time_since_eat = val;
}

void doodlebug::move(){
    if (moved != true) {

        if (theWorld->grid[xPos+1][yPos] != nullptr) {
            if (theWorld->grid[xPos+1][yPos]->output() == 'o') {
                
                theWorld->set_grid(xPos + 1, yPos, this);
                theWorld->set_grid(xPos, yPos, nullptr);
                xPos += 1;
                this->setWorld(theWorld);
                    timeEatUp(0);
            }
        }
        
        else if (theWorld->grid[xPos][yPos+1] != nullptr) {
            if (theWorld->grid[xPos][yPos+1]->output() == '0'){
            theWorld->set_grid(xPos, yPos+1, this);
            theWorld->set_grid(xPos, yPos, nullptr);
            yPos += 1;
            this->setWorld(theWorld);
                timeEatUp(0);
            }
        }
        
        else if (theWorld->grid[xPos-1][yPos] != nullptr) {
            
        
           if (theWorld->grid[xPos-1][yPos]->output() == 'o') {
            theWorld->set_grid(xPos - 1, yPos, this);
            theWorld->set_grid(xPos, yPos, nullptr);
            xPos -= 1;
            this->setWorld(theWorld);
               timeEatUp(0);
           }
        }
        
        else if (theWorld->grid[xPos][yPos-1] != nullptr) {
            if (theWorld->grid[xPos][yPos-1]->output() =='0') {
            theWorld->set_grid(xPos, yPos-1, this);
            theWorld->set_grid(xPos, yPos, nullptr);
            yPos -= 1;
            this->setWorld(theWorld);
                timeEatUp(0);
            }
            
        }
        
        else {
            int a = rand() % 4;
            timeEatUp(time_since_eat + 1);
            if (a == 0) {
                //up
                if ((theWorld->grid[xPos-1][yPos] == nullptr) && (xPos - 1 >= 0) )  {
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
                
                // right
                else if ((theWorld->grid[xPos][yPos+1] == nullptr) && (yPos+1 < 20)) {
                    theWorld->set_grid(xPos, yPos+1, this);
                    theWorld->set_grid(xPos, yPos, nullptr);
                    yPos += 1;
                    this->setWorld(theWorld);
                    
                }
                else {
                    
                }
                
                
            
            }
            
            else if (a == 1) {
                if ((theWorld->grid[xPos][yPos-1] == nullptr) && (yPos - 1 >= 0 )) {
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
                
                else {   }
                
                
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
                
                
            }
        }
        setAge(age+1);
        has_Moved(true);
        
    }
}
    



void doodlebug::starve() {
    if (time_since_eat > 3) {
        delete this; 
    }
}




void doodlebug::breed() {
    /// Repname the new doodble
    
    if (age % 8 == 0) {
        if ((theWorld->grid[xPos+1][yPos] == nullptr) & (xPos + 1 < 20)){
        
            organism* ant = new doodlebug(xPos+1, yPos, theWorld);
            theWorld->set_grid(xPos+1, yPos, ant);
        }
    
        else if ((theWorld->grid[xPos-1][yPos] == nullptr) && (xPos - 1 >= 0) ) {
            organism* ant = new doodlebug(xPos-1, yPos, theWorld);
            theWorld->set_grid(xPos-1, yPos, ant);
            
        }
        
        else if ((theWorld->grid[xPos][yPos-1] == nullptr) && (yPos - 1 >= 0 )) {
            organism* ant = new doodlebug(xPos, yPos - 1, theWorld);
            theWorld->set_grid(xPos, yPos - 1, ant);
        }
        
        else if ((theWorld->grid[xPos][yPos+1] == nullptr) && (yPos+1 < 20)) {
            organism* ant = new doodlebug(xPos, yPos + 1, theWorld);
            theWorld->set_grid(xPos, yPos + 1, ant);
        }
            
        else {}
        
    }
}
