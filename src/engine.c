#include <SDL2/SDL.h>
#include "engine.h"
#include "graphics.h"
#include "statemanager.h"

int ENGINE_init(Engine *engine, struct EngineOptions *options) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return 1;
  }

  if (options != NULL) {
    engine -> graphics.width = options -> width;
    engine -> graphics.height = options -> height;
    engine -> graphics.windowTitle = options -> title;
  }
  GRAPHICS_init(&engine -> graphics);

  STATEMANAGER_init(&engine -> statemanager);
  engine -> quit = 0;
  return 0;
}

int ENGINE_free(Engine *engine) {
  STATEMANAGER_free(&engine -> statemanager);
  GRAPHICS_free(&engine -> graphics);
  SDL_Quit();
  return 0;
}
