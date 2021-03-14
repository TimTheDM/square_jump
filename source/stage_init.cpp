#include<vector>
#include <SFML/Graphics.hpp>
#include "stage_init.h"

std::vector<fixture>* stageInit();

std::vector<fixture>* stageInit() {
  std::vector<fixture>* stages = new std::vector<fixture>[STAGE_TOTAL];
  stages[0] = collisionPlayground();
  return stages;
}

player::player() {
  this->acceleration = 0.0;
  sf::RectangleShape pSprite(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
  this->pSprite = pSprite;
}

fixture::fixture(bool isHazard, bool isWinPoint, sf::Texture& hazardText, int width, int length, int xOffset, int yOffset) {
  this->isHazard = isHazard;
  this->isWinPoint = isWinPoint;

  if(isHazard) {
    sf::Sprite placeholder;
    placeholder.setTexture(hazardText);
    placeholder.setPosition(xOffset, yOffset);
    this->hazard = placeholder;
  } else {
    sf::RectangleShape placeholder(sf::Vector2f(width, length));
    placeholder.setPosition(xOffset, yOffset);
    placeholder.setFillColor(sf::Color(255, 255, 0));
    this->platform = placeholder;
  }
}

std::vector<fixture> collisionPlayground() {
  std::vector<fixture> cPlayground;
  sf::Texture spike;
  fixture fix1(false, false, spike, 1200, 50, 0, 750);
  cPlayground.push_back(fix1);
  return cPlayground;
}