#include "src/statemanager.h"
#include <stdio.h>


unsigned int initState1() {
  printf("state 1 created\n");
  return 0;
}

unsigned int destroyState1() {
  printf("state 1 destroyed\n");
  return 0;
}

unsigned int initState2() {
  printf("state 2 created\n");
  return 0;
}

unsigned int updateState2(float deltatime) {
  printf("state 2 update %f\n", deltatime);
  return 0;
}

unsigned int destroyState2() {
  printf("state 2 destroyed\n");
  return 0;
}

int main() {

  StateManager statemanager;
  STATEMANAGER_init(&statemanager);

  State state1;
  state1.init = initState1;
  state1.destroy = destroyState1;

  State state2;
  state2.init = initState2;
  state2.update = updateState2;;
  state2.destroy = destroyState2;

  STATEMANAGER_push(&statemanager, &state1);
  STATEMANAGER_update(&statemanager, 10.0f);
  STATEMANAGER_push(&statemanager, &state2);
  STATEMANAGER_update(&statemanager, 10.0f);
  STATEMANAGER_pop(&statemanager);
  STATEMANAGER_update(&statemanager, 10.0f);

  STATEMANAGER_free(&statemanager);
}
