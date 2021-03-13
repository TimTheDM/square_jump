#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include "stage_init.h"
#include "movement.h"
#include "collision.h"
//where control is passed each game loop to check if a key is pressed
//calls movement functions, and uses functions from collision

void pressCheck(std::vector<fixture>*, player&, int);
void sideMove(char, std::vector<fixture>*, player&, int);
void jump(player&);

void pressCheck(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks what keyboard buttons are being held down, calls sideMove or jump
}

void sideMove(char side, std::vector<fixture>*, player& p1, int stageOn) {
  //moves to side according to side, checking collision before displacing player
}

void jump(player&) {
  //sets player objects acceleration according to a const I'll put somewhere
}