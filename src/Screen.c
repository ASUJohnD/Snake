#include "Screen.h"

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

const int screenWidth = SCREEN_WIDTH;
const int screenHeight = SCREEN_HEIGHT;
int screenResolution = SCREEN_WIDTH * SCREEN_HEIGHT;
const int fontSize = 48;

void vectorClamp(Vector2 *object, int objectSize)
{
    object->y = Clamp(
        object->y, 
        0, 
        screenHeight - objectSize
    );

    object->x = Clamp(
        object->x, 
        0, 
        screenWidth - objectSize

    );
}