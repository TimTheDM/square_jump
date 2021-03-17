#include<vector>
#include <SFML/Graphics.hpp>
#include "stage_init.h"

std::vector<fixture>* stageInit();

std::vector<fixture>* stageInit() {
  std::vector<fixture>* stages = new std::vector<fixture>[STAGE_TOTAL];
  static sf::Texture spikes;
  spikes.loadFromFile("spikes.png");
  stages[0] = collisionPlayground(spikes);
  return stages;
}

player::player() {
  this->acceleration = 0.0;
  sf::RectangleShape pSprite(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
  pSprite.setPosition(445, 550);
  pSprite.setFillColor(sf::Color(0, 255, 255));
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

std::vector<fixture> collisionPlayground(sf::Texture& spike) {
  std::vector<fixture> cPlayground;
  fixture fix1(false, false, spike, 1200, 50, 0, 750);
  fixture fix2(false, false, spike, 50, 800, 0, 0);
  fixture fix3(false, false, spike, 150, 50, 300, 650);
  fixture fix4(false, false, spike, 150, 50, 550, 550);
  fixture fix5(false, false, spike, 150, 50, 800, 450);
  fixture fix6(true, false, spike, 0, 0, 950, 700);
  fixture fix7(true, false, spike, 0, 0, 1000, 700);
  fixture fix8(true, false, spike, 0, 0, 1050, 700);
  fixture fix9(true, false, spike, 0, 0, 1100, 700);
  fixture fix10(true, false, spike, 0, 0, 1150, 700);
  fixture fix11(false, false, spike, 150, 50, 550, 300);
  fixture fix12(false, false, spike, 400, 50, 0, 50);
  fixture fix13(false, false, spike, 400, 50, 0, 150);
  fixture fix14(true, false, spike, 0, 0, 100, 550);
  fixture fix15(true, false, spike, 0, 0, 100, 500);
  fixture fix16(true, false, spike, 0, 0, 100, 450);
  fixture fix17(true, false, spike, 0, 0, 100, 400);
  fix14.hazard.rotate(90);
  fix15.hazard.rotate(90);
  fix16.hazard.rotate(90);
  fix17.hazard.rotate(90);
  cPlayground.push_back(fix1);
  cPlayground.push_back(fix2);
  cPlayground.push_back(fix3);
  cPlayground.push_back(fix4);
  cPlayground.push_back(fix5);
  cPlayground.push_back(fix6);
  cPlayground.push_back(fix7);
  cPlayground.push_back(fix8);
  cPlayground.push_back(fix9);
  cPlayground.push_back(fix10);
  cPlayground.push_back(fix11);
  cPlayground.push_back(fix12);
  cPlayground.push_back(fix13);
  cPlayground.push_back(fix14);
  cPlayground.push_back(fix15);
  cPlayground.push_back(fix16);
  cPlayground.push_back(fix17);
  return cPlayground;
}