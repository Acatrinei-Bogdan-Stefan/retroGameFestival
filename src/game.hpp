#pragma once
#include <raylib.h>
#include "player.hpp"
#include "gamebooth.hpp"
#include "Snake-mini-game.cpp"

class Game
{
private:
  Player player;
  Gamebooth gamebooth;
  SnakeGame snakegame;
public:
  Game();
  ~Game();
  void Draw();
  void Update();
  void HandleInput();
  void CheckCollisionWithBoth();
};


 