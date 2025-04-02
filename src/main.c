/*******************************************************************************************
*
*   raylib [core] example - Basic window (adapted for HTML5 platform)
*
*   This example is prepared to compile for PLATFORM_WEB and PLATFORM_DESKTOP
*   As you will notice, code structure is slightly different to the other examples...
*   To compile it for PLATFORM_WEB just uncomment #define PLATFORM_WEB at beginning
*
*   This example has been created using raylib 1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include "Screen.h"
#include "Input.h"
#include "Apple.h"
#include "Snake.h"


#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
static enum LastInput lastInput = RIGHT;    // Last Input from keyboard
static Snake snake;                         // Snake
static Apple apple;                         // Apple


//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void);     // Update and Draw one frame
void snakeEatsApple(void);      // Runs Conditions for when Snake eats Apple
bool winConditions(void);       // Returns true when player wins
bool loseConditions(void);      // Returns true when player loses
void simpleAutoSolve(void);     // Solves the Game (only works without loseConditions)


//----------------------------------------------------------------------------------
// Main Entry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Raylib Snake Game");
    // Initialize Game Elements
    initSnake(&snake);
    initApple(&apple);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else

    SetTargetFPS(10);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void)
{
    // Update
    if (!winConditions() && !loseConditions()) {
        if (IsKeyDown(KEY_SLASH))
            simpleAutoSolve();
        moveSnakeBody(&snake);
        snakeInput(&lastInput, &snake);
    
        snakeEatsApple();

        // vectorClamp(&snake.bodyPositions, snakeSize);
    }
    
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(BLACK);

        drawApple(&apple);
        drawSnake(&snake);

        if (winConditions()) {
            DrawText(
                "YOU WIN!", 
                screenWidth/2 - fontSize*2, 
                screenHeight/2 - fontSize,
                fontSize,
                YELLOW
            );
        }
        else if (loseConditions()) {
            DrawText(
                "YOU LOSE!", 
                screenWidth/2 - fontSize*2, 
                screenHeight/2 - fontSize,
                fontSize,
                RED
            );
        }

    EndDrawing();
    //----------------------------------------------------------------------------------
}

inline void snakeEatsApple(void)
{
    if (apple.position.x == snake.bodyPositions.x && 
        apple.position.y == snake.bodyPositions.y) {
            inCorner(&apple, &lastInput);
            findNewPosition(&apple, &snake);
            addSnakeBody(&snake);
            snakeInput(&lastInput, &snake);
            screenResolution -= snakeSize*snakeSize;
    }
}

bool winConditions(void) 
{
    if (screenResolution <= (snakeSize*snakeSize)*2) return true;
    return false;
}

bool loseConditions(void) 
{
    // If player goes outside screen bounds (differs from typical snake)
    if (snake.bodyPositions.x < 0 || 
        snake.bodyPositions.x >= screenWidth || 
        snake.bodyPositions.y < 0 || 
        snake.bodyPositions.y >= screenHeight) {
            return true;
    }
    if (checkSnakePosition(snake.bodyPositions, &snake, 1)) {
        return true;
    }

    return false;
}

void simpleAutoSolve(void) 
{
    if (snake.bodyPositions.y > apple.position.y) {
        lastInput = UP;
    }
    else if (snake.bodyPositions.y < apple.position.y) {
        lastInput = DOWN;
    }
    else if (snake.bodyPositions.x > apple.position.x) {
        lastInput = LEFT;
    }
    else if (snake.bodyPositions.x < apple.position.x) {
        lastInput = RIGHT;
    }
}
