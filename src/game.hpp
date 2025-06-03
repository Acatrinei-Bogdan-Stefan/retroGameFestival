#pragma once
#include <raylib.h>
#include "player.hpp"
#include "gamebooth.hpp"
#include "Snake-mini-game.cpp"

class MainGame
{
private:
  Player player;
  Gamebooth gamebooth;
  
public:
  MainGame();
  ~MainGame();
  
  void Draw();
  void Update();
  void HandleInput();
  void CheckCollisionWithBoth();
};


 