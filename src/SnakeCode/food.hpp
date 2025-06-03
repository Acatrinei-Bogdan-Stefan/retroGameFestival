#pragma once
#include <raylib.h>
#include <deque>
#include <raymath.h>

class Food
{
private:

public:
    Vector2 position;
    Texture2D texture;
    Food(deque<Vector2> snakeBody);
    ~Food();
    void Draw()
    Vector2 GenerateRandomCell()
    Vector2 GenerateRandomPos(deque<Vector2> snakeBody)
};