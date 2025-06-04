#pragma once
#include <raylib.h>
#include <deque>
#include <raymath.h>

class Snake
{
private:

public:
  deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
  Vector2 direction = {1, 0};
  bool addSegment = false;
  void Draw();
  void Update();
  void Reset();

  int cellSize = 30;
  int cellCount = 25;
  int offset = 75;
};