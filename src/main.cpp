#include <raylib.h>
#include "game.hpp"


int main() 
{
    const Color grey = {29, 29, 27, 255};
    
    const int windowWidth = 1750;
    const int windowHeight = 1700;
    
    // InitWindow(windowWidth, windowHeight, "C++ Game Festival");
    // SetTargetFPS(60);

    
    

    // Snake Code
    using namespace std;

    static bool allowMove = false;
    Color green = {173, 204, 96, 255};
    Color darkGreen = {43, 51, 24, 255};

    

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



    // snake main

    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Retro Snake");
    SetTargetFPS(60);

    Game game = Game();

    // Texture2D background = LoadTexture("Graphics/background.png");
    // background.width = offset * 2 + cellSize * cellCount;
    // background.height = offset * 2 + cellSize * cellCount;
    Button startButton{"Graphics/backToMenu.png", {290, 400}, 0.65};
    Button exitButton{"Graphics/backToMenu.png", {290, 600}, 0.65};
    Button backToMenuButton{"Graphics/backToMenu.png", {687, 10}, 0.30};
    
    bool exit = false;
    bool menu = true;

    // snake main

    // SnakeCode



    
    while (!WindowShouldClose())
    {

        // Update
        Game.HandleInput();

        // Draw
        BeginDrawing();
            ClearBackground(grey);

            Game.Draw();
            Game.CheckCollisionWithBoth();


            // Snake Main
            

            while (!WindowShouldClose() && exit == false  )
            {
            
                BeginDrawing();

                Vector2 mousePosition = GetMousePosition();
                bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
            
                if(menu == true){ 

                    // DrawTexture(background,0, 0, WHITE);

                    DrawText("Retro Snake", 170, 200, 90, darkGreen);
                    startButton.Draw();
                    DrawText("Start Game", 340, 450, 40, darkGreen);
                    exitButton.Draw();
                    DrawText("Exit", 415, 650, 40, darkGreen);
                    ClearBackground(green);
                
                    if(startButton.isPressed(mousePosition, mousePressed))
                    {
                        PlaySound(game.wallSound);
                        menu = false;
                    }
                    else if(exitButton.isPressed(mousePosition, mousePressed))
                    {
                        PlaySound(game.wallSound);
                        exit = true;
                    }
                
                } else
                {
                    if (EventTriggered(0.2))
                    {
                        allowMove = true;
                        game.Update();
                    }
                
                    if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1 && allowMove)
                    {
                        game.snake.direction = {0, -1};
                        game.running = true;
                        allowMove = false;
                    }
                    if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1 && allowMove)
                    {
                        game.snake.direction = {0, 1};
                        game.running = true;
                        allowMove = false;
                    }
                    if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1 && allowMove)
                    {
                        game.snake.direction = {-1, 0};
                        game.running = true;
                        allowMove = false;
                    }
                    if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1 && allowMove)
                    {
                        game.snake.direction = {1, 0};
                        game.running = true;
                        allowMove = false;
                    }
                
                    // Drawing
                    ClearBackground(green);
                    DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, darkGreen);
                    DrawText("Retro Snake", offset - 5, 20, 40, darkGreen);
                    DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);
                    game.Draw();
                    DrawText("Menu", 713, 20, 40, darkGreen);
                    backToMenuButton.Draw();
                
                    if(backToMenuButton.isPressed(mousePosition, mousePressed))
                    {
                        menu = true;
                        std::cout << "Merge butonul!" << std::endl;
                        game.GameOver();
                    }
                }
            
            

            
            
            
            
            
                EndDrawing();
            }
            CloseWindow();
            return 0;
            // Snake Main
            
        
        EndDrawing();
    }
    
    CloseWindow();
}