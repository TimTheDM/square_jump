#include <SFML/Graphics.hpp>
#include<vector>
#include <iostream>
#include "stage_init.h"
#include "collision.h"
//file for collision detection functions

bool isAbove(const sf::FloatRect&, const sf::FloatRect&);
bool isDown(const sf::FloatRect&, const sf::FloatRect&);

bool isRun = true;

void stateCheck(std::vector<fixture>* stages, player& p1, int stageOn, sf::RenderWindow& window) {
  //checks if win or hazard object is being touched
  //runs helper functions to change block to starting point
  if (isRun) {
    //sf::Mouse::setPosition(sf::Vector2i(100, 650), window);
    sf::FloatRect fixt = stages[0].at(2).platform.getGlobalBounds();
    sf::FloatRect play = p1.pSprite.getGlobalBounds();

    if (isDown(fixt, play)) {
      std::cout << "Is down";
    }
    isRun = false;
  }

  sf::Vector2i t = sf::Mouse::getPosition(window);
  bool isMove = true;

  /*sf::FloatRect h = p1.pSprite.getGlobalBounds();
  if (t.y < h.top) {
    int guh = h.top - t.y;
    if (aboveCollision(stages, p1, 0, guh)) {
      isMove = false;
      p1.pSprite.move(0, guh*-1);
    }
  } else if (t.y > h.top) {
    int guh = 1;
    if (downCollision(stages, p1, 0, guh)) {
      isMove = false;
      std::cout << guh << std::endl;
      p1.pSprite.move(0, guh);
    }
  }

  if (isMove) {
    p1.pSprite.setPosition(t.x, t.y);
  }*/

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

bool leftCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {
  //checks if colliding fixture is left of player object sprite
  return false;
}

bool rightCollision(std::vector<fixture>* stages, player& p1, int stageOn, int& boundaryDistance) {
  //checks if colliding fixture is right of player object sprite
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
      int distance = playerRect.top - fixtureRect.top - PLAYER_SIZE;
      if (distance < boundaryDistance) {
        if (boundaryDistance > distance) boundaryDistance = distance;
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

bool isCollide(std::vector<fixture>* stages, player& p1, int stageOn) {
  
  return false;
}