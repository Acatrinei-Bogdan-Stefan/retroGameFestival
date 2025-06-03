#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "button.hpp"






class Game
{
public:
    Snake snake = Snake();
    Food food = Food(snake.body);
    bool running = true;
    int score = 0;
    Sound eatSound;
    Sound wallSound;

    Game()
    {
        InitAudioDevice();
        eatSound = LoadSound("Sounds/eat.mp3");
        wallSound = LoadSound("Sounds/wall.mp3");
    }

    ~Game()
    {
        UnloadSound(eatSound);
        UnloadSound(wallSound);
        CloseAudioDevice();
    }

    void Draw()
    {
        food.Draw();
        snake.Draw();
    }

    void Update()
    {
        if (running)
        {
            snake.Update();
            CheckCollisionWithFood();
            CheckCollisionWithEdges();
            CheckCollisionWithTail();
        }
    }

    void CheckCollisionWithFood()
    {
        if (Vector2Equals(snake.body[0], food.position))
        {
            food.position = food.GenerateRandomPos(snake.body);
            snake.addSegment = true;
            score++;
            PlaySound(eatSound);
        }
    }

    void CheckCollisionWithEdges()
    {
        if (snake.body[0].x == cellCount || snake.body[0].x == -1)
        {
            GameOver();
        }
        if (snake.body[0].y == cellCount || snake.body[0].y == -1)
        {
            GameOver();
        }
    }

    void GameOver()
    {
        snake.Reset();
        food.position = food.GenerateRandomPos(snake.body);
        running = false;
        score = 0;
        PlaySound(wallSound);
    }

    void CheckCollisionWithTail()
    {
        deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front();
        if (ElementInDeque(snake.body[0], headlessBody))
        {
            GameOver();
        }
    }
};

int SnakeMain()
{
    
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
}