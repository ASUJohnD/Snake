#include "Snake.h"
#include "Screen.h"
#include <stdlib.h>

const int snakeSize = 20;
 
void initSnake(Snake *snake)
{
    Vector2 headPosition = {
        200 - snakeSize,
        300 - snakeSize
    };
    snake->bodyPositions = headPosition;
    snake->next = NULL;
}

void snakeInput(enum LastInput *lastInput, Snake *snake)
{
    switch (getInput(lastInput)) {
    case UP:
        snake->bodyPositions.y -= snakeSize;
        break;
    case DOWN:
        snake->bodyPositions.y += snakeSize;
        break;
    case LEFT:
        snake->bodyPositions.x -= snakeSize;
        break;
    case RIGHT:
        snake->bodyPositions.x += snakeSize;
        break;
    }    
}

void moveSnakeBody(Snake *snake)
{
    Vector2 prev = snake->bodyPositions;
    Vector2 curr;

    while (snake != NULL) {
        curr = snake->bodyPositions;
        snake->bodyPositions = prev;
        prev = curr;
        snake = snake->next;
    }
}

void addSnakeBody(Snake *snake)
{
    Snake *newSnakeBody = malloc(sizeof(Snake));

    newSnakeBody->next = snake->next;
    snake->next = newSnakeBody;

    newSnakeBody->bodyPositions = snake->bodyPositions;
}

bool checkSnakePosition(Vector2 checkPosition, Snake *snake, int snakePart)
{
    while (snakePart > 0) {
        snakePart--;
        snake = snake->next;
    }

    while (snake != NULL) {
        if (checkPosition.x == snake->bodyPositions.x &&
            checkPosition.y == snake->bodyPositions.y) return true;
        snake = snake->next;
    }
    return false;
}

void drawSnake(Snake *snake)
{
    while (snake != NULL) {
        DrawRectangle(
            snake->bodyPositions.x,
            snake->bodyPositions.y,
            snakeSize,
            snakeSize,
            GREEN
        );
        snake = snake->next;
    }
}