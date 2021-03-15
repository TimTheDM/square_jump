#include <SFML/Graphics.hpp>
#include <vector>
#include "stage_init.h"
#include "movement.h"
#include "gravity.h"
#include "collision.h"

const int windowHeight = 800, windowLength = 1200;

void drawGame(sf::RenderWindow&, std::vector<fixture>*, player&, int);

int main()
{
  sf::RenderWindow window(sf::VideoMode(windowLength, windowHeight), "Cube Jump");
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

    //Checks if the player object has collided with a hazard or winPoint type fixture
    //Calls a function to change player position to start point if it does, and increments stageOn
    //If the colliding fixture was a win point type
    stateCheck(stages, p1, stageOn);

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
