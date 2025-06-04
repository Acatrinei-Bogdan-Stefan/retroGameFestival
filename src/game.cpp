#include "game.hpp"
#include <iostream>


Game::Game()
{

    // Snake
    InitAudioDevice();
    eatSound = LoadSound("Sounds/eat.mp3");
    wallSound = LoadSound("Sounds/wall.mp3");

}

Game::~Game()
{

    // Snake
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();

}

void Game::Draw()
{
    // Snake
    food.Draw();
    snake.Draw();

    player.Draw();
    gamebooth.Draw({20, 40});
}

void Game::Update()
{
    // Snake
     if (running)
        {
            snake.Update();
            CheckCollisionWithFood();
            CheckCollisionWithEdges();
            CheckCollisionWithTail();
        }
}

void Game::CheckCollisionWithFood()
{
    if (Vector2Equals(snake.body[0], food.position))
    {
        food.position = food.GenerateRandomPos(snake.body);
        snake.addSegment = true;
        score++;
        PlaySound(eatSound);
    }
}
void Game::CheckCollisionWithEdges()
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
void Game::GameOver()
{
    snake.Reset();
    food.position = food.GenerateRandomPos(snake.body);
    running = false;
    score = 0;
    PlaySound(wallSound);
}

void Game::CheckCollisionWithTail()
{
    deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if (ElementInDeque(snake.body[0], headlessBody))
    {
        GameOver();
    }
}

void Game::HandleInput()
{
    if(IsKeyDown(KEY_LEFT))
    {
        player.MoveLeft();
    }
    else if(IsKeyDown(KEY_RIGHT))
    {
        player.MoveRight();
    }
    if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT))
    {
        player.MoveUpRight();
    }
    if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT))
    {
        player.MoveDownRight();
    }
    else if(IsKeyDown(KEY_UP))
    {
        player.MoveUp();
    }
    else if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT))
    {
        player.MoveUpLeft();
    }
    else if(IsKeyDown(KEY_DOWN))
    {
        player.MoveDown();
    }
    else if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT))
    {
        player.MoveDownLeft();
    }
}

void Game::CheckCollisionWithBoth()
{

    // booth edges
   int l_booth_x{20};
   int r_booth_x{20+100};    
   int u_cbooth_y{40};   
   int b_booth_y{40+100};  

   

    // // player edge
    float l_player_x{player.position.x};
    float r_player_x{player.position.x + player.image.width};    
    float u_player_y{player.position.y};   
    float b_player_y{player.position.y + player.image.height};  

    // // update colision_with_axe 
    bool collision_with_axe = 
                           (l_booth_x <= l_player_x) && 
                           (r_booth_x >= r_player_x) && 
                           (u_cbooth_y <= u_player_y) && 
                           (b_booth_y >= b_player_y);

    if(collision_with_axe && IsKeyDown(KEY_E))
    {
        // SnakeMain();
    }
    
}
