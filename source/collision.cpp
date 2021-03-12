#include <SFML/Graphics.hpp>
#include "stage_init.h"
//file for collision detection functions

void stateCheck(fixture**, player&, int);
bool aboveCollision(fixture**, player&, int);
bool leftCollision(fixture**, player&, int);
bool rightCollision(fixture**, player&, int);
bool downCollision(fixture**, player&, int);
bool isCollide(fixture**, player&, int);

void stateCheck(fixture** stages, player& p1, int stageOn) {
  //checks if win or hazard object is being touched
  //runs helper functions to change block to starting point
}

bool aboveCollision(fixture** stages, player& p1, int stageOn) {
  //checks if colliding fixture is above player object sprite
  return false;
}

bool leftCollision(fixture** stages, player& p1, int stageOn) {
  //checks if colliding fixture is left of player object sprite
  return false;
}

bool rightCollision(fixture** stages, player& p1, int stageOn) {
  //checks if colliding fixture is right of player object sprite
  return false;
}

bool downCollision(fixture** stages, player& p1, int stageOn) {
  //checks if colliding fixture is below player object sprite
  return false;
}

bool isCollide(fixture** stages, player& p1, int stageOn) {
  //helper function to see if ANY fixtures are colliding with player sprite
  return false;
}