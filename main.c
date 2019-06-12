#include <SDL2/SDL.h>
#include <stdio.h>
#include "src/engine.h"

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
  struct EngineOptions options = {0};
  options.title = "C engine test";
  options.width = 480;
  options.height = 272;

  Engine engine;
  ENGINE_init(&engine, &options);

  State state1;
  state1.init = initState1;
  state1.update = updateState1;
  state1.destroy = destroyState1;
  STATEMANAGER_push(&engine.statemanager, &state1);

  SDL_Event e;
  while (!engine.quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) engine.quit = 1;
    }
    STATEMANAGER_update(&engine.statemanager, 10.0f);
  }

  ENGINE_free(&engine);
}
