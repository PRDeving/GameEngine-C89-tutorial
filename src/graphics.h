#ifndef ENGINE_GRAPHICS_H
#define ENGINE_GRAPHICS_H

typedef struct {
  char *windowTitle;
  int width;
  int height;
  void *window;
} Graphics;

int GRAPHICS_init(Graphics *graphics);
void GRAPHICS_free(Graphics *graphics);

#endif
