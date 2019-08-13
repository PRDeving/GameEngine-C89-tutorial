#include <raylib.h>
#include "engine.h"
#include "graphics.h"
#include "statemanager.h"

int ENGINE_init(Engine *engine, struct EngineOptions *options) {
  if (options) {
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
  CloseWindow();
  return 0;
}
