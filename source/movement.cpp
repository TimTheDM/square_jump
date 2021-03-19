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
}

void rightMove(std::vector<fixture>* stages, player& p1, int stageOn)
{
    int movePixels = 5;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
    {
        movePixels = 9;
        rightCollision(stages, p1, stageOn, movePixels);
        p1.pSprite.move(movePixels,0.f);
    }
    else
    {
        rightCollision(stages, p1, stageOn, movePixels);
        p1.pSprite.move(movePixels,0.f);
    }
}

void leftMove(std::vector<fixture>* stages, player& p1, int stageOn)
{
    int movePixels = 5;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
    {
        int movePixels = 9;
        leftCollision(stages, p1, stageOn, movePixels);
        p1.pSprite.move((-1 * movePixels),0.f);
    }
    else
    {
        leftCollision(stages, p1, stageOn, movePixels);
        p1.pSprite.move((-1 * movePixels),0.f);
    }
}