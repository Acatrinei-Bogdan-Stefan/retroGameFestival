#pragma once
#include <raylib.h>
#include "player.hpp"
#include "gamebooth.hpp"
#include <iostream>
#include <deque>
#include <raymath.h>
#include "button.hpp"
#include "food.hpp"
#include "snake.hpp"

class Game
{
private:
  Player player;
  Gamebooth gamebooth;
  
public:
 // Snake variables
  Snake snake = Snake();
  Food food = Food(snake.body);
  bool running = true;
  int score = 0;
  Sound eatSound;
  Sound wallSound;
  int cellSize = 30;
  int cellCount = 25;
  int offset = 75;

  Game();
  ~Game();
  
  void Draw();
  void Update();
  void HandleInput();
  void CheckCollisionWithBoth();
  void GameOver();
  void CheckCollisionWithEdges();
  void CheckCollisionWithFood();
  void CheckCollisionWithTail()
};


 