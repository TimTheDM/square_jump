#include "stage_init.h"

class fixture {
  //contains a stage fixture, such as platform, hazard, and win point
};

class player {
  //contains player sprite and acceleration variable
};

fixture** stageInit();

fixture** stageInit() {
  //where the fixtures and their positions will be set
  return new const fixture*[5];
}