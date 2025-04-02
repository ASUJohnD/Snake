#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "raymath.h"

extern const int screenWidth;
extern const int screenHeight;
extern int screenResolution;
extern const int fontSize;

/// @brief Clamps Object to within Screen Area.
/// @param object 
/// @param objectSize 
void vectorClamp(Vector2 *object, int objectSize);

#endif