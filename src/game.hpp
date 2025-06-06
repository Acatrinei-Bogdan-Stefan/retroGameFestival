#pragma once
#include <raylib.h>
#include "player.hpp"
#include "gamebooth.hpp"


class Game
{
private:
  Player player;
  Gamebooth gamebooth;
  
public:
  Game();
  ~Game();
  
  void Draw();
  void Update();
  void HandleInput();
  void CheckCollisionWithBoth();
};


 