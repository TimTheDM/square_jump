#include <SFML/Graphics.hpp>
#include<vector>
#include "stage_init.h"
#include "collision.h"
//Includes functions for changing acceleration while midair
/*
The formula for the parabolic jump of the player, in regards to their perspective of the screen, is:
f(x) = (-j/T^2)(t - T)^2 + j; j = jumpHeight, T = timeToApex, t = time

The formula for the parabolic jump velocity of the player is:
f'(x) = (-2j/T^2)(t - T)

The formula for the parabolic jump acceleration of the player is:
f''(x) = -2j/T^2

Due to the y-axis of the window being opposite to standard, with the top being 0 and going down is the positive y direction, a positive acceleration delineates falling on the screen.
As such, the player sprite is moved in a negative acceleration (-p1.acceleration) to compensate.
*/

const double jumpHeight = 200.0; //rough height the top edge of the player in pixels, actual may change due to rounding error.
const double timeToApex = 15.0; //time in game frames to reach the height of the jump
const double maxFallRate = -2 * (-((2 * jumpHeight)/(timeToApex * timeToApex)) + ((2 * jumpHeight)/timeToApex)); //limits the maximum downward acceleration to twice the normal jump arc

sf::Vector2f position;
bool pressed = false;
int boundaryDistance;
bool downC, upC;

void gravity(std::vector<fixture>*, player&, int);

void gravity(std::vector<fixture>* stages, player& p1, int stageOn) {
  //changes player objects acceleration if there was no down collision.
  //Sets to 0 if collision down or up occurs.
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !pressed /*jump command was pressed*/)
  {
      pressed = true;
      p1.acceleration = (-((2 * jumpHeight)/(timeToApex * timeToApex)) + ((2 * jumpHeight)/timeToApex));
      boundaryDistance = abs(p1.acceleration);
  }
  //downC = downCollision(stages, p1, stageOn, boundaryDistance);
  //upC = aboveCollision(stages, p1, stageOn, boundaryDistance);
  if (aboveCollision(stages, p1, stageOn, boundaryDistance) && p1.acceleration >= 0)
  {
      p1.acceleration = 0;
      p1.pSprite.move(0, -boundaryDistance);
  }
  else if (downCollision(stages, p1, stageOn, boundaryDistance) && p1.acceleration <= 0)
  {
      p1.acceleration = 0;
      p1.pSprite.move(0, boundaryDistance);
      pressed = false;
  }
  else
  {
      p1.pSprite.move(0, -p1.acceleration);
  }
  if (!downCollision(stages, p1, stageOn, boundaryDistance))
  {
      p1.acceleration += -((2 * jumpHeight)/(timeToApex * timeToApex));
      if (p1.acceleration < maxFallRate)
      {
          p1.acceleration = maxFallRate;
      }
      boundaryDistance = abs(p1.acceleration);
      pressed = true;
  }
}