//
//  world.cpp
//  Doodlebug_Simulation
//
//  Created by Jared Vaughn on 11/16/21.
//

#include <stdio.h>
#include <iostream>
#include "world.h"
#include "organism.h"
#include "doodlebug.h"
#include "ants.h"
using namespace std;

world::world() {
    
    
    int antz = 0;
    int bugs = 0;
    
    for(int i= 0; i < 20; i++) {
        for (int j= 0; j < 20; j++){
            set_grid(i, j, nullptr);
            
        }
    }
    while (bugs < 5) {
        int a = rand() % 20;
        int b = rand() % 20;
        
        if (grid[a][b] == nullptr) {
            
            organism* d = new doodlebug(a, b, this);
            set_grid(a, b, d);
            
            bugs +=1;
        }
    }
    
    while (antz < 100) {
        int a = rand() % 20;
        int b = rand() % 20;
        
        if (grid[a][b] == nullptr){
            organism* d = new ants(a, b, this);
            set_grid(a, b, d);
            
            antz += 1;
        }
    }
}

void world::world_simulation() {
    char c = 'd';
    
    
    while (c != 'q') {
    // TO make this keep going just set a stop character = Q
        move_bug();
        breed_bug();
        move_ant();
        breed_ant();
        starve();
        world_output();
        move_reset();
        breed_reset();
        cin >> c;
    
    }
}


void world::set_grid(int x, int y, organism* a){
    grid[x][y] = a;
}


void world::world_output() {
    
    int antz = 0;
    int bugs = 0;
    
    // this method outputs the world by collums
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20 ; j++) {
            
            if (grid[i][j] == nullptr){
                cout << " .";
            }
            else {
                if (grid[i][j]->output() == 'X') {
                    bugs += 1;
                }
                if (grid[i][j]->output() == 'o'){
                    antz += 1;
                }
                cout <<" "<< grid[i][j]->output();
            }
            
        }
        cout << endl;
    }
    
    cout <<"       doodlebugs-"<< bugs <<"   "<< antz << "-ants" << endl;
    cout <<"   Press 'q' and Enter to end the simulation" << endl;
    cout <<"   Press any other key and Enter to continue" << endl;
}



void world::move_bug() {
    int i,j;
    for (i = 0; i < 20 ; i++) {
        for (j = 0; j < 20; j++) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->output() == 'X'){
                    grid[i][j]->move();
                }
            }
        }
    }
}



void world::move_ant() {
    int i,j;
    for (i = 0; i < 20 ; i++) {
        for (j = 0; j < 20; j++) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->output() == 'o'){
                    grid[i][j]->move();
                }
            }
        }
    }
}


void world::move_reset() {
    int i,j;
    for (i = 0; i < 20 ; i++) {
        for (j = 0; j < 20; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->has_Moved(false);
            }
        }
    }
}

void world::breed_reset() {
    int i,j;
    for (i = 0; i < 20 ; i++) {
        for (j = 0; j < 20; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->set_breed(false);
            }
        }
    }
}

void world::breed_bug(){
    int i,j;
    for (i = 0; i < 20 ; i++) {
        for (j = 0; j < 20; j++) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->output() == 'X'){
                    if (grid[i][j]->get_breed() == false) {
                        grid[i][j]->breed();
                    }
                }
            }
        }
    }
}

void world::breed_ant() {
    int i,j;
    for (i = 0; i < 20 ; i++) {
        for (j = 0; j < 20; j++) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->output() == 'o'){
                    if (grid[i][j]->get_breed() == false) {
                        grid[i][j]->breed();
                    }
                }
            }
        }
    }
}




void world::starve() {
    int i,j;
    for (i = 0; i < 20 ; i++) {
        for (j = 0; j < 20; j++) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->output() == 'o'){
                    if (grid[i][j]->get_breed() == false) {
                        grid[i][j]->starve();
                    }
                }
            }
        }
    }
}
