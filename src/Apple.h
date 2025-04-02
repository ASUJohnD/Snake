#ifndef _APPLE_H_
#define _APPLE_H_

#include "Snake.h"
#include "Input.h"
#include "raylib.h"

// Apple
typedef struct Apple {
    Vector2 position;
    int size;
} Apple;

/// @brief Size of Apple. Should be equivalent to Size of Snake.
extern const int appleSize;

/// @brief Initializes Apple.
/// @param apple 
void initApple(Apple *apple);

/// @brief Draws Apple to screen.
/// @param apple 
void drawApple(Apple *apple);

/// NOTE: Should make Void in the future.
/// @brief Finds new random position for Apple after Snakes eats it.
/// @param apple 
/// @param screenWidth 
/// @param screenHeight 
/// @return 
Vector2 findNewPosition(Apple *apple, Snake *snake);

/// @brief Checks if Apple is on a corner of the screen. If so, it modifies
///        lastInput so that Snake doesn't go off screen and lose the game.
/// @param apple 
/// @param  
/// @return 
void inCorner(Apple *apple, enum LastInput *lastInput);

#endif