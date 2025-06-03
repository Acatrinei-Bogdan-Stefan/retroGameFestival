#include <raylib.h>
#include "game.hpp"
#include "food.hpp"
#include "snake.hpp"

int main() 
{
    const Color grey = {29, 29, 27, 255};
    
    const int windowWidth = 1750;
    const int windowHeight = 1700;
    
    InitWindow(windowWidth, windowHeight, "C++ Game Festival");
    SetTargetFPS(60);

    
    

// Snake Code
using namespace std;

static bool allowMove = false;
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;
int offset = 75;

double lastUpdateTime = 0;

bool ElementInDeque(Vector2 element, deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;
}

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

Snake snake = Snake();
Food food = Food(snake.body);


// SnakeCode



    
    while (!WindowShouldClose())
    {

        // Update
        MainGame.HandleInput();

        // Draw
        BeginDrawing();
            ClearBackground(grey);

            MainGame.Draw();
            MainGame.CheckCollisionWithBoth();
            // laser.Draw();
        
        EndDrawing();
    }
    
    CloseWindow();
}