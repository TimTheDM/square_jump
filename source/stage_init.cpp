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

fixture::fixture(bool isHazard, bool isWinPoint, sf::Texture& hazardText, sf::Vector2f& squareDimension) {
  this->isHazard = isHazard;
  this->isWinPoint = isWinPoint;

  if(isHazard) {
    sf::Sprite placeholder;
    placeholder.setTexture(hazardText);
    this->hazard = placeholder;
  } else {
    sf::RectangleShape placeholder(squareDimension);
    this->platform = placeholder;
  }
}

std::vector<fixture> collisionPlayground() {
  std::vector<fixture> cPlayground;
  return cPlayground;
}