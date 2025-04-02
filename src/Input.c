#include "Input.h"
#include "raylib.h"
#include <stdlib.h>

enum LastInput getInput(enum LastInput *lastInput)
{
    switch (GetKeyPressed()) {
    case KEY_W:
    case KEY_UP:
        if (*lastInput == DOWN) break;
        *lastInput = UP;
        break;
    case KEY_S:
    case KEY_DOWN:
        if (*lastInput == UP) break;
        *lastInput = DOWN;
        break;
    case KEY_A:
    case KEY_LEFT:
        if (*lastInput == RIGHT) break;
        *lastInput = LEFT;
        break;
    case KEY_D:
    case KEY_RIGHT:
        if (*lastInput == LEFT) break;
        *lastInput = RIGHT;
        break;
    }
    return *lastInput;
}

