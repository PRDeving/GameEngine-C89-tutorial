SDL_INCLUDE = -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks
SDL_LIB = -framework SDL2

all:
	gcc $(SDL_LIB) src/graphics.c src/statemanager.c main.c $(SDL_INCLUDE) -o test
