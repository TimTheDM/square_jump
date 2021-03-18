#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include "stage_init.h"
#include "movement.h"
#include "collision.h"
//where control is passed each game loop to check if a key is pressed
//calls movement functions, and uses functions from collision

void pressCheck(std::vector<fixture>*, player&, int);
void leftMove(std::vector<fixture>*, player&, int);
void rightMove(std::vector<fixture>*, player&, int);
void jump(player&);

void pressCheck(std::vector<fixture>* stages, player& p1, int stageOn) {
  //checks what keyboard buttons are being held down, calls sideMove or jump
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
        leftMove(stages, p1, stageOn);
  }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
        rightMove(stages, p1, stageOn);
  }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
        jump(p1);
  }
}

void rightMove(std::vector<fixture>*, player& p1, int stageOn)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Shift))
    {
        p1.pSprite.move(12.f,0.f);
        rightCollision(stages, p1, stageOn, 12);
    }
    else
    {
        p1.pSprite.move(5.f,0.f);
        rightCollision(stages, p1, stageOn, 5);
    }
}

void leftMove(std::vector<fixture>*, player& p1, int stageOn)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Shift))
    {
        p1.pSprite.move(-12.f,0.f);
        leftCollision(stages, p1, stageOn, 12);
    }
    else
    {
        p1.pSprite.move(-5.f,0.f);
        leftCollision(stages, p1, stageOn, 5);
    }
}

void jump(player&)
{
  //sets player objects acceleration according to Alex's Nonsense

}
