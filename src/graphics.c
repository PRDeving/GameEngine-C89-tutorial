#include <raylib.h>
#include <stdio.h>
#include <string.h>
#include "graphics.h"

int GRAPHICS_init(Graphics *graphics) {
  if (!graphics -> windowTitle) graphics -> windowTitle = "No Name";
  if (!graphics -> width) graphics -> width = 800;
  if (!graphics -> height) graphics -> height = 600;

  InitWindow(
      graphics -> width,
      graphics -> height,
      graphics -> windowTitle
  );
  graphics -> window = GetWindowHandle();

  if (!graphics -> window) {
      fprintf(stderr, "error creating window");
      return 1;
  }
  return 0;
}

void GRAPHICS_free(Graphics *graphics) {
}
