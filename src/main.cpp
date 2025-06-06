#include <raylib.h>
#include "game.hpp"


int main() 
{
    const Color grey = {29, 29, 27, 255};
    
    const int windowWidth = 1400;
    const int windowHeight = 800;
    
    InitWindow(windowWidth, windowHeight, "C++ Game Festival");
    SetTargetFPS(60);

    Game game;


    while (!WindowShouldClose())
    {

        // Update
        game.HandleInput();

        // Draw
        BeginDrawing();
            ClearBackground(grey);

            game.Draw();
            game.CheckCollisionWithBoth();

            
        
        EndDrawing();
    }
    
    CloseWindow();
}