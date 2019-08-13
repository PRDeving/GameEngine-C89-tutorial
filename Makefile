# SDL_INCLUDE = -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks
# SDL_LIB = -framework SDL2

RL_PATH = raylib/src
RL_INCLUDE = -I$(RL_PATH)
RL_LIB = -L$(RL_PATH) -lraylib
RL_FLAGS = PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED

CC = gcc
CC_FLAGS = -Wall -pedantic -std=c99 -fPIC

INCLUDE = $(SDL_INCLUDE)
LIB = $(SDL_LIB)

O_ENGINE = src/engine.o src/graphics.o src/statemanager.o

test: static
	$(CC) main.c -Iinclude -L. -o test -l:libengine.a -lraylib

lib:
	make -C $(RL_PATH)
	make -C $(RL_PATH) $(RL_FLAGS)
	sudo make -C $(RL_PATH)  install $(RL_FLAGS)

include:
	mkdir -p include
	cp -rv src/*.h include

shared: ${O_ENGINE}
	gcc -shared $^ -o libengine.so
	make include

static: ${O_ENGINE}
	ar cr libengine.a $^
	make include

%.o: %.c
	$(CC) -c $(CC_FLAGS) $< $(RL_INCLUDE) -o $@

clean:
	rm -f src/*.o libengine* test
	rm -rf include

cleanraylib:
	make -C $(RL_PATH) clean
	sudo make -C $(RL_PATH) uninstall $(RL_FLAGS)
	rm -f $(RL_PATH)/libraylib*

cleanall: clean cleanraylib
