#include <SFML/Graphics.hpp>
#include<vector>
#include <iostream>
#include "stage_init.h"
#include "collision.h"
//file for collision detection functions


void stateCheck(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks if win or hazard object is being touched
  //runs helper functions to change block to starting point
}

bool aboveCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {
  
  for (int i = 0;i < stages[stageOn].size();i++) {
    if (!stages[stageOn].at(i).isHazard) {
      sf::Vector2f fixturePos = stages[stageOn].at(i).platform.getPosition();
    }
  }
  return false;
}

bool leftCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {
  //checks if colliding fixture is left of player object sprite
  return false;
}

bool rightCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {
  //checks if colliding fixture is right of player object sprite
  return false;
}

bool downCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {
  //checks if colliding fixture is below player object sprite
  return false;
}

bool isCollide(std::vector<fixture>* stages, player& p1, int stageOn) {
  
  return false;
}