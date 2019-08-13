#include <stdio.h>
#include <raylib.h>
#include "src/engine.h"

unsigned int initState1() {
  printf("state 1 created\n");
  return 0;
}

unsigned int updateState1(float deltatime) {
  printf("state 1 update %f\n", deltatime);
  return 0;
}

unsigned int drawState1(float deltatime) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
    DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);
    EndDrawing();
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

  Engine engine = {0};
  ENGINE_init(&engine, &options);

  State state1 = {0};
  state1.init = initState1;
  /* state1.update = updateState1; */
  state1.draw = drawState1;
  state1.destroy = destroyState1;
  STATEMANAGER_push(&engine.statemanager, &state1);

  while (!WindowShouldClose()) {
      STATEMANAGER_update(&engine.statemanager, 10.0f);
      STATEMANAGER_draw(&engine.statemanager, 10.0f);
  }

  ENGINE_free(&engine);
}
