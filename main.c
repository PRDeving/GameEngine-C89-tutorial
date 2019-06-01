#include <SDL2/SDL.h>
#include "src/graphics.h"
#include "src/statemanager.h"
#include <stdio.h>


unsigned int initState1() {
  printf("state 1 created\n");
  return 0;
}

unsigned int updateState1(float deltatime) {
  printf("state 1 update %f\n", deltatime);
  return 0;
}

unsigned int destroyState1() {
  printf("state 1 destroyed\n");
  return 0;
}

int main() {
  State state1;
  state1.init = initState1;
  state1.update = updateState1;
  state1.destroy = destroyState1;

  StateManager statemanager;
  STATEMANAGER_init(&statemanager);
  STATEMANAGER_push(&statemanager, &state1);

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    STATEMANAGER_free(&statemanager);
    return 1;
  }

  Graphics graphics;
  if (GRAPHICS_init(&graphics) != 0) {
    STATEMANAGER_free(&statemanager);
    SDL_Quit();
    return 1;
  }

  int quit = 0;
  SDL_Event e;
  while(!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) quit = 1;
    }
    STATEMANAGER_update(&statemanager, 10.0f);
  }

  STATEMANAGER_free(&statemanager);
  GRAPHICS_free(&graphics);
  SDL_Quit();
}
