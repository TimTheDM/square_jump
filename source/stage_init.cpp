#include<vector>
#include "stage_init.h"

std::vector<fixture>* stageInit();

std::vector<fixture>* stageInit() {
  //where the fixtures and their positions will be set
  return new std::vector<fixture>[5];
}