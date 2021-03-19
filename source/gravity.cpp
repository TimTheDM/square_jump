#include <SFML/Graphics.hpp>
#include<vector>
#include "stage_init.h"
#include "collision.h"
//Includes functions for changing acceleration while midair

void gravity(std::vector<fixture>*, player&, int);

void gravity(std::vector<fixture>* stages, player& p1, int stageOn) {
  //changes player objects acceleration if there was no down collision.
  //Sets to 0 if collision down or up occurs.
}
