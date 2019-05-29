#include "statemanager.h"
#include <stdlib.h>

int STATEMANAGER_scale(StateManager *statemanager) {
  statemanager -> capacity *= 2;
  statemanager -> stack = realloc(statemanager -> stack, statemanager -> capacity * sizeof(State*));
  return statemanager -> capacity;
}

int STATEMANAGER_init(StateManager *statemanager) {
  statemanager -> capacity = 3;
  statemanager -> stack = malloc(statemanager -> capacity * sizeof(State*));
  statemanager -> top = -1;
  return 0;
}

int STATEMANAGER_free(StateManager *statemanager) {
  do {
    STATEMANAGER_pop(statemanager);
  } while (statemanager -> top > -1);
  free(statemanager -> stack);
  return 0;
}

int STATEMANAGER_push(StateManager *statemanager, State *state) {
  if (statemanager -> top + 1 == statemanager -> capacity) STATEMANAGER_scale(statemanager);
  statemanager -> top++;
  statemanager -> stack[statemanager -> top] = state;
  if (state -> init != NULL) state -> init();
  return statemanager -> top;
}

int STATEMANAGER_pop(StateManager *statemanager) {
  if (statemanager -> top == -1) return 0;
  State *top = STATEMANAGER_top(statemanager);
  if (top -> destroy != NULL) top -> destroy();
  statemanager -> stack[statemanager -> top] = NULL;
  statemanager -> top--;
  return statemanager -> top;
}

State *STATEMANAGER_top(StateManager *statemanager) {
  return statemanager -> stack[statemanager -> top];
}

int STATEMANAGER_update(StateManager *statemanager, float deltatime) {
  State *state = STATEMANAGER_top(statemanager);
  if (state -> update != NULL) return state -> update(deltatime);
  return 1;
}

int STATEMANAGER_draw(StateManager *statemanager, float deltatime) {
  State *state = STATEMANAGER_top(statemanager);
  if (state -> draw != NULL) return state -> draw(deltatime);
  return 1;
}
