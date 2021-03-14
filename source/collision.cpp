#include <SFML/Graphics.hpp>
#include<vector>
#include "stage_init.h"
//file for collision detection functions

void stateCheck(std::vector<fixture>*, player&, int);
bool aboveCollision(std::vector<fixture>*, player&, int);
bool leftCollision(std::vector<fixture>*, player&, int);
bool rightCollision(std::vector<fixture>*, player&, int);
bool downCollision(std::vector<fixture>*, player&, int);
bool isCollide(std::vector<fixture>*, player&, int);

void stateCheck(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks if win or hazard object is being touched
  //runs helper functions to change block to starting point
}

bool aboveCollision(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks if colliding fixture is above player object sprite
  return false;
}

bool leftCollision(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks if colliding fixture is left of player object sprite
  return false;
}

bool rightCollision(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks if colliding fixture is right of player object sprite
  return false;
}

bool downCollision(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks if colliding fixture is below player object sprite
  return false;
}

bool isCollide(std::vector<fixture>* stages, player& p1, int stageOn) {
  //helper function to see if ANY fixtures are colliding with player sprite
  return false;
}