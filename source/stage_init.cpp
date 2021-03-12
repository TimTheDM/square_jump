#include "stage_init.h"

fixture** stageInit();

fixture** stageInit() {
  //where the fixtures and their positions will be set
  return new fixture*[5];
}