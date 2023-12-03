#include <cstdlib>
#include <ctime>
#include "raylib.h"
#include <iostream>
#include "main.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------


int main(void)
{
    //RANDOM
    srand(time(0));
    int number, isPositive;
    number = rand() % 50 + 1 ;
    isPositive = rand() % 2;
    if(isPositive == 1){
        number -= number*2;
    }
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    //RECTANGLES

    float pillarPos = 850;

    Rectangle pillarA = {pillarPos, 0, 60 , screenHeight/2 - 65 + number};
    Rectangle pillarB = {pillarPos,screenHeight - (screenHeight/2 - 65 - number), 60,  screenHeight/2 - 65 - number};
    //PLAYER
    Sprite player(screenWidth/2,120,35);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            //bg
            ClearBackground(BLACK);
            //title
            // DrawText("Flappy Bird", 340, 40, 20, BLACK);
            pillarPos -= 0.25;
            //random number
            DrawRectangleRec(pillarA, RED);
            DrawRectangleRec(pillarB, RED);

            player.gravity();
            player.goUp();       
            player.updateSprite();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}