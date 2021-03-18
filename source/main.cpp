#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "stage_init.h"
#include "movement.h"
#include "gravity.h"
#include "collision.h"

void mouseMove(sf::RenderWindow&, std::vector<fixture>*, player&, int);
void drawGame(sf::RenderWindow&, std::vector<fixture>*, player&, int);

int main()
{
  sf::RenderWindow window(sf::VideoMode(1200, 800), "Cube Jump");
  window.setFramerateLimit(30);

  //class named fixture is what each platform, hazard, and win point is in a stage represented
  std::vector<fixture>* stages = stageInit();
  int stageOn = 0;
  //calls constructor for object representing players controlled square
  player p1;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    //passed a reference to window to check what keys are being pressed
    //Press check calls movement function for left and right, and calls jump function
    //Left and right move call collision on their own. May displace player object position
    pressCheck(stages, p1, stageOn);

    //calls gravity function, which changes acceleration of member var of player object
    //depending on results of collision checks and existing acceleration variable
    //gravity then displaces player objects sprite member
    gravity(stages, p1, stageOn);

    mouseMove(window, stages, p1, stageOn);
    
    //Checks if the player object has collided with a hazard or winPoint type fixture
    //Calls a function to change player position to start point if it does, and increments stageOn
    //If the colliding fixture was a win point type
    stageOn = stateCheck(stages, p1, stageOn);

    window.clear();
    //draws all game elements in their updated positions
    drawGame(window, stages, p1, stageOn);
    window.display();
  }

  return 0;
}

void drawGame(sf::RenderWindow& window, std::vector<fixture>* stages, player& p1, int stageOn) {

  window.draw(p1.pSprite);

  for (int i = 0;i < stages[stageOn].size();i++) {
    if (stages[stageOn].at(i).isHazard) {
      window.draw(stages[stageOn].at(i).hazard);
    } else {
      window.draw(stages[stageOn].at(i).platform);
    }
  }
}

bool moveMouse = true;

void mouseMove(sf::RenderWindow& window, std::vector<fixture>* stages, player& p1, int stageOn) {

  if (moveMouse) {
    sf::Mouse::setPosition(sf::Vector2i(100, 650), window);
    moveMouse = false;
  }
  sf::Vector2i t = sf::Mouse::getPosition(window);
  bool isMove = true;

  sf::FloatRect h = p1.pSprite.getGlobalBounds();
  if (t.y < h.top) {
    int guh = h.top - t.y;
    if (aboveCollision(stages, p1, 0, guh)) {
      isMove = false;
      p1.pSprite.move(0, guh*-1);
    }
  } 

  if (t.y > h.top) {
    int guh = t.y - h.top;
    if (downCollision(stages, p1, 0, guh)) {
      isMove = false;
      p1.pSprite.move(0, guh);
    }
  }

  if (t.x < h.left) {
    int guh = h.left - t.x;
    if (leftCollision(stages, p1, 0, guh)) {
      isMove = false;
      p1.pSprite.move(guh*-1, 0);
    }
  }

  if (t.x > h.left) {
    int guh = t.x - h.left;
    if (rightCollision(stages, p1, 0, guh)) {
      isMove = false;
      p1.pSprite.move(guh, 0);
    }
  }

  if (isMove) {
    p1.pSprite.setPosition(t.x, t.y);
  }
}