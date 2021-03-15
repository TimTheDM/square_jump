#include <SFML/Graphics.hpp>
#include<vector>
#include "stage_init.h"
#include "collision.h"
//Includes functions for changing acceleration while midair

const double jumpHeight = 120.0; //rough height the bottom edge of the player in pixels
const double timeToApex = 12.0; //time in game frames to reach the height of the jump
const double maxFallRate = -2 * (-((2 * jumpHeight)/(timeToApex * timeToApex)) + ((2 * jumpHeight)/timeToApex)); //limits the maximum downward acceleration to twice the normal jump arc

sf::Vector2f position;
bool pressed = false;

void gravity(std::vector<fixture>*, player&, int);

void gravity(std::vector<fixture>* stages, player& p1, int stageOn) {
  //changes player objects acceleration if there was no down collision.
  //Sets to 0 if collision down or up occurs.
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !pressed /*jump command was pressed*/)
  {
      pressed = true;
      p1.acceleration -= (-((2 * jumpHeight)/(timeToApex * timeToApex)) + ((2 * jumpHeight)/timeToApex));
      p1.pSprite.move(0, p1.acceleration);
  }
  if (!downCollision(stages, p1, stageOn))
  {
      p1.acceleration -= -((2 * jumpHeight)/(timeToApex * timeToApex));
      if (p1.acceleration < maxFallRate)
      {
          p1.acceleration = maxFallRate;
      }
      p1.pSprite.move(0, p1.acceleration);

      position = p1.pSprite.getPosition();
      if (position.y > 800 - 100)
      {
          p1.pSprite.setPosition(position.x, 800 - 100);
          p1.acceleration = 0;
          pressed = false;
      }
  }
  if (downCollision(stages, p1, stageOn) or aboveCollision(stages, p1, stageOn))
  {
      p1.acceleration = 0;
      p1.pSprite.move(0, p1.acceleration);
  }
}
