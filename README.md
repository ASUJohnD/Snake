
# Snake

A linked-list implementation of Snake using [Raylib](https://github.com/raysan5/raylib). 

## Design

Generally speaking, dynamic memory allocation should not be used unless it is necessary, though in this case, this was more of a learning exercise for Raylib and is not supposed to be an ideal or optimized version of Snake. A more optimized version of Snake would likely use an array to determine the positions of the different parts of the snake, and the size of this array would be determined at compile time based off the given screen size. The game would then have a contiguous chunk of memory in the stack instead of fragmented chunks of memory in the heap, which is the case for the linked-list implementation.

## Rules

The game follows the standard rules of Snake (except for one rule):

- The player can move the snake to eat the apple, so that the snake can grow.
- The snake must be within the space of the screen. Player will lose if the snake leaves the screen.
- The snake cannot eat itself or the Player will lose the game.
- The game is won when the player has taken up all (or almost all) of the screen space with the snake.

## Build

The game can be built using the Make or CMake build system. The only dependencies include Raylib and the C99 standard library. The Makefile is a modified version of the one Raylib provides. It allows for multiple files to be linked without any errors and doesn't need an empty obj directory to build the program. 

### GNU Make

```
cd PATH/TO/Snake
make
```

### CMake

```
cd PATH/TO/Snake
cmake -S . -B obj
```
