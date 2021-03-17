#include <SFML/Graphics.hpp>
#include<vector>
#include <iostream>
#include "stage_init.h"
#include "collision.h"
//file for collision detection functions

bool isAbove(const sf::FloatRect&, const sf::FloatRect&);

bool isRun = true;

void stateCheck(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks if win or hazard object is being touched
  //runs helper functions to change block to starting point
  if (isRun) {
    sf::FloatRect t1 = p1.pSprite.getGlobalBounds();
    sf::FloatRect t2 = stages[0].at(13).hazard.getGlobalBounds();

    if (isAbove(t2, t1)) {
      std::cout << "Fixture 13 is above player";
    }
    isRun = false;
  }
}

bool aboveCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {
  
  sf::FloatRect fixtureRect;
  sf::FloatRect playerRect = p1.pSprite.getGlobalBounds();;

  for (int i = 0;i < stages[stageOn].size();i++) {

    if (!stages[stageOn].at(i).isHazard) fixtureRect = stages[stageOn].at(i).platform.getGlobalBounds();
    else fixtureRect = stages[stageOn].at(i).hazard.getGlobalBounds();
    
    if (isAbove(fixtureRect, playerRect)) {
      int distance = playerRect.top - (fixtureRect.top + fixtureRect.height);
      if (distance < boundaryDistance) {
        boundaryDistance -= distance;
        return true;
      } 
    }
  } 
  return false;
}

bool isAbove(const sf::FloatRect& fixtureRect, const sf::FloatRect& playerRect) {

  if (fixtureRect.top < playerRect.top) {
    if ((playerRect.left <= fixtureRect.left && (fixtureRect.left - playerRect.left) < 100)) {
      return true;
    } else if (playerRect.left >= fixtureRect.left && (playerRect.left - fixtureRect.left) < fixtureRect.width) {
      return true;
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