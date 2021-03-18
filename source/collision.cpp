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
bool isBeside(player&, const sf::FloatRect&);
void startMove(player&);

bool isRun = true;

int stateCheck(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks if win or hazard object is being touched
  //runs helper functions to change block to starting point
  if (isRun) {
    isRun = false;
    p1.pSprite.setPosition(100, 450);
  }

  sf::FloatRect fixt;
  
  for (int i = 0;i < stages[stageOn].size();i++) {
    bool isHazard = false;
    bool isWin = false;
    if (stages[stageOn].at(i).isHazard) {
      fixt = stages[stageOn].at(i).hazard.getGlobalBounds();
      isHazard = true;
    } else if (stages[stageOn].at(i).isWinPoint) {
      fixt = stages[stageOn].at(i).platform.getGlobalBounds();
      isWin = true;
    } else {
      continue;
    }

    if (isBeside(p1, fixt)) {
      std::cout << "Hazarded";
      if (isHazard) {
        startMove(p1);
        break;
      } else if (isWin) {
        startMove(p1);
        return stageOn + 1;
      }
    }
  }
  return stageOn;
}

bool isBeside(player& p1, const sf::FloatRect& hazard) {
  //returns if the player is within 1 pixel of 2nd arg
  p1.pSprite.move(0, 2);
  if (p1.pSprite.getGlobalBounds().intersects(hazard)) {
    p1.pSprite.move(0, -2);
    return true;
  }

  p1.pSprite.move(0, -4);
  if (p1.pSprite.getGlobalBounds().intersects(hazard)) {
    p1.pSprite.move(0, 2);
    return true;
  }

  p1.pSprite.move(2, 2);
  if (p1.pSprite.getGlobalBounds().intersects(hazard)) {
    p1.pSprite.move(-2, 0);
    return true;
  }

  p1.pSprite.move(-4, 0);
  if (p1.pSprite.getGlobalBounds().intersects(hazard)) {
    p1.pSprite.move(2, 0);
  }

  p1.pSprite.move(2, 0);

  return false;
}

void startMove(player& p1) {
  p1.pSprite.setPosition(START_X, START_Y);
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