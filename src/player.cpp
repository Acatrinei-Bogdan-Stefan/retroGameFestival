#include "player.hpp"


Player::Player()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth() - image.width)/2;
    position.y = GetScreenHeight() - image.height;
}

Player::~Player()
{
    UnloadTexture(image);
}

void Player::Draw()
{
    DrawTextureV(image,position,WHITE);
}

void Player::MoveLeft()
{
    position.x -= 7;
    if(position.x < 0)
    {
        position.x = 0;
    }
}

void Player::MoveRight()
{
    position.x += 7;
    if(position.x > GetScreenWidth() - image.width)
    {
        position.x = GetScreenWidth() - image.width;
    }
}

void Player::MoveUp()
{
    position.y -= 7;
    if(position.y > GetScreenWidth() - image.width)
    {
        position.x = GetScreenWidth() - image.width;
    }
}

void Player::MoveDown()
{
    position.y += 7;
    if(position.x > GetScreenWidth() - image.width)
    {
        position.x = GetScreenWidth() - image.width;
    }

}

void Player::MoveUpRight()
{
    position.y += 3.5;
    if(position.y > GetScreenWidth() - image.width)
    {
        position.y = GetScreenWidth() - image.width;
    }
    position.x += 3.5;
    if(position.x > GetScreenWidth() - image.width)
    {
        position.x = GetScreenWidth() - image.width;
    }
}

void Player::MoveUpLeft()
{
    position.y += 3.5;
    if(position.y > GetScreenWidth() - image.width)
    {
        position.y = GetScreenWidth() - image.width;
    }

    position.x -= 3.5;
    if(position.x < 0)
    {
        position.x = 0;
    }
}

void Player::MoveDownRight()
{
    position.y += 3.5;
    if(position.x > GetScreenWidth() - image.width)
    {
        position.x = GetScreenWidth() - image.width;
    }

    position.x += 3.5;
    if(position.x > GetScreenWidth() - image.width)
    {
        position.x = GetScreenWidth() - image.width;
    }
}

void Player::MoveDownLeft()
{
    position.y += 3.5;
    if(position.x > GetScreenWidth() - image.width)
    {
        position.x = GetScreenWidth() - image.width;
    }

    position.x -= 3.5;
    if(position.x < 0)
    {
        position.x = 0;
    }
}



void Player::FireLaser()
{
    
}