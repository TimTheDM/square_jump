#include <SFML/Graphics.hpp>
#include<vector>
#include <iostream>
#include "stage_init.h"
#include "collision.h"
//file for collision detection functions

bool isAbove(const sf::FloatRect&, const sf::FloatRect&);
bool isDown(const sf::FloatRect&, const sf::FloatRect&);
bool isLeft(const sf::FloatRect&, const sf::FloatRect&);
bool isRight(const sf::FloatRect&, const sf::FloatRect&);

bool isRun = true;

void stateCheck(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks if win or hazard object is being touched
  //runs helper functions to change block to starting point
}

bool aboveCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {

  bool canCollide = false;
  sf::FloatRect fixtureRect;
  sf::FloatRect playerRect = p1.pSprite.getGlobalBounds();

  for (int i = 0;i < stages[stageOn].size();i++) {

    if (!stages[stageOn].at(i).isHazard) fixtureRect = stages[stageOn].at(i).platform.getGlobalBounds();
    else fixtureRect = stages[stageOn].at(i).hazard.getGlobalBounds();
    
    if (isAbove(fixtureRect, playerRect)) {
      int distance = playerRect.top - (fixtureRect.top + fixtureRect.height);
      if (distance < boundaryDistance) {
        if (boundaryDistance > distance) boundaryDistance = distance;
        canCollide = true;
      } 
    }
  }

  return canCollide;
}

bool isAbove(const sf::FloatRect& fixtureRect, const sf::FloatRect& playerRect) {
  if (fixtureRect.top < playerRect.top) {
    if ((playerRect.left <= fixtureRect.left && (fixtureRect.left - playerRect.left) < PLAYER_SIZE)) {
      return true;
    } else if (playerRect.left >= fixtureRect.left && (playerRect.left - fixtureRect.left) < fixtureRect.width) {
      return true;
    }
  }
  return false;
}

bool downCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {

  bool canCollide = false;
  sf::FloatRect fixtureRect;
  sf::FloatRect playerRect = p1.pSprite.getGlobalBounds();

  for (int i = 0;i < stages[stageOn].size();i++) {

    if (!stages[stageOn].at(i).isHazard) fixtureRect = stages[stageOn].at(i).platform.getGlobalBounds();
    else fixtureRect = stages[stageOn].at(i).hazard.getGlobalBounds();
    
    if (isDown(fixtureRect, playerRect)) {
      int distance = fixtureRect.top - playerRect.top - PLAYER_SIZE;
      if (distance < boundaryDistance) {
        boundaryDistance = distance;
        canCollide = true;
      } 
    }
  }

  return canCollide;
}

bool isDown(const sf::FloatRect& fixtureRect, const sf::FloatRect& playerRect) {
  if (fixtureRect.top > playerRect.top) {
    if ((playerRect.left <= fixtureRect.left && (fixtureRect.left - playerRect.left) < PLAYER_SIZE)) {
      return true;
    } else if (playerRect.left >= fixtureRect.left && (playerRect.left - fixtureRect.left) < fixtureRect.width) {
      return true;
    }
  }
  return false;
}

bool leftCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {

  bool canCollide = false;
  sf::FloatRect fixtureRect;
  sf::FloatRect playerRect = p1.pSprite.getGlobalBounds();

  for (int i = 0;i < stages[stageOn].size();i++) {

    if (!stages[stageOn].at(i).isHazard) fixtureRect = stages[stageOn].at(i).platform.getGlobalBounds();
    else fixtureRect = stages[stageOn].at(i).hazard.getGlobalBounds();
    
    if (isLeft(fixtureRect, playerRect)) {
      int distance = playerRect.left - (fixtureRect.left + fixtureRect.width);
      if (distance < boundaryDistance) {
        boundaryDistance = distance;
        canCollide = true;
      } 
    }
  }

  return canCollide;
}

bool isLeft(const sf::FloatRect& fixtureRect, const sf::FloatRect& playerRect) {
  if (fixtureRect.left+fixtureRect.width <= playerRect.left) {
    if (playerRect.top < fixtureRect.top+fixtureRect.height && playerRect.top >= fixtureRect.top) {
      return true;
    } else if (fixtureRect.top < playerRect.top+PLAYER_SIZE && fixtureRect.top >= playerRect.top) {
      return true;
    }
  }
  return false;
}

bool rightCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {

  bool canCollide = false;
  sf::FloatRect fixtureRect;
  sf::FloatRect playerRect = p1.pSprite.getGlobalBounds();

  for (int i = 0;i < stages[stageOn].size();i++) {

    if (!stages[stageOn].at(i).isHazard) fixtureRect = stages[stageOn].at(i).platform.getGlobalBounds();
    else fixtureRect = stages[stageOn].at(i).hazard.getGlobalBounds();
    
    if (isRight(fixtureRect, playerRect)) {
      int distance = fixtureRect.left - PLAYER_SIZE - playerRect.left;
      if (distance < boundaryDistance) {
        boundaryDistance = distance;
        canCollide = true;
      } 
    }
  }

  return canCollide;
}

bool isRight(const sf::FloatRect& fixtureRect, const sf::FloatRect& playerRect) {
  if (fixtureRect.left >= playerRect.left+PLAYER_SIZE) {
    if (playerRect.top < fixtureRect.top+fixtureRect.height && playerRect.top >= fixtureRect.top) {
      return true;
    } else if (fixtureRect.top < playerRect.top+PLAYER_SIZE && fixtureRect.top >= playerRect.top) {
      return true;
    }
  }
  return false;
}

bool isCollide(std::vector<fixture>* stages, player& p1, int stageOn) {
  
  return false;
}