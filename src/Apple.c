#include "Apple.h"
#include "Screen.h"

const int appleSize = 20;

void initApple(Apple *apple)
{
    apple->position.x = 600 - appleSize;
    apple->position.y = 300 - appleSize;
    apple->size = appleSize;
}

void drawApple(Apple *apple)
{
    DrawRectangle(
        apple->position.x, 
        apple->position.y, 
        appleSize,
        appleSize,
        RED
    );
}

Vector2 findNewPosition(Apple *apple, Snake *snake)
{
    do {
        apple->position.x = (int)GetRandomValue(
            0, 
            screenWidth/appleSize - 1)*appleSize;
        
        apple->position.y = (int)GetRandomValue(
            0, 
            screenHeight/appleSize - 1)*appleSize;
    } while (checkSnakePosition(apple->position, snake, 0));
    
    return apple->position;
}

void inCorner(Apple *apple, enum LastInput *lastInput)
{
    // Apple in Top Left Corner
    if (apple->position.x == 0 && 
        apple->position.y == 0){
            if (*lastInput == UP)
                *lastInput = RIGHT;
            else {
                *lastInput = DOWN;
            }
    }
    // Apple in Top Right Corner
    else if (apple->position.x == (screenWidth - appleSize) && 
        apple->position.y == 0) {
            if (*lastInput == UP) 
                *lastInput = LEFT;
            else {
                *lastInput = DOWN;
            }
    }
    // Apple in Bottom Left Corner
    else if (apple->position.x == 0 && 
        apple->position.y == (screenHeight - appleSize)) {
            if (*lastInput == DOWN)
                *lastInput = RIGHT;
            else {
                *lastInput = UP;
            }
    }
    // Apple in Bottom Right Corner
    else if (apple->position.x == (screenWidth - appleSize) && 
        apple->position.y == (screenHeight - appleSize)) {
            if (*lastInput == DOWN)
                *lastInput = LEFT;
            else {
                *lastInput = UP;
            }
    }
    
}
