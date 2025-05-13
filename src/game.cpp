#include "game.hpp"


Game::Game()
{

}

Game::~Game()
{

}

void Game::Draw()
{
    player.Draw();
    gamebooth.Draw({20, 40});
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

void CheckCollisionWithBoth()
{
    if(Player.Getposition() == Gamebooth.position.x)
    {

    }
}