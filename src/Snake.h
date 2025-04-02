#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "raylib.h"
#include "Input.h"

/// @brief Main Player Type of the game.
typedef struct Snake {
    Vector2 bodyPositions;
    struct Snake *next;
} Snake;

extern const int snakeSize;
extern Vector2 headPostion;

/// @brief Initializes Snake with data in Snake.c
/// @param snake 
void initSnake(Snake *snake);

/// @brief Moves Snake's head based on latest input.
/// @param snake 
void snakeInput(enum LastInput *lastInput, Snake *snake);

/// @brief Copies each Snake node's bodyPositions to the next Snake node's.
/// @param snake 
void moveSnakeBody(Snake *snake);

/// @brief Adds a new snake node where the first node (head node) is.
/// @param snake 
void addSnakeBody(Snake *snake);

/// @brief Checks if position is inside of Snake. Iterates through Snake
///        starting at snakePart.
/// @param checkPosition 
/// @param snake 
/// @return true if position is in Snake
bool checkSnakePosition(Vector2 checkPosition, Snake *snake, int snakePart);

/// @brief Draws Snake. 🐍
/// @param snake 
void drawSnake(Snake *snake);



#endif