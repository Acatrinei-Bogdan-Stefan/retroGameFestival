#include <raylib.h>
#include "game.hpp"
// #include "laser.hpp"

int main() 
{
    const Color grey = {29, 29, 27, 255};
    
    const int windowWidth = 750;
    const int windowHeight = 700;
    
    InitWindow(windowWidth, windowHeight, "C++ Game Festival");
    SetTargetFPS(60);

    Game game;
    // Laser laser = Laser({100,100},7);
    
    while (!WindowShouldClose())
    {

        // Update
        game.HandleInput();

        // Draw
        BeginDrawing();
            ClearBackground(grey);

            game.Draw();
            DrawRectangle(100,100,100,100,WHITE);
            // laser.Draw();
        
        EndDrawing();
    }
    
    CloseWindow();
}