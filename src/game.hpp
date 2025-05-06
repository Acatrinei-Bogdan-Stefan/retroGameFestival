#pragma once
#include <raylib.h>
#include "player.hpp"

class Game
{
private:
  Player player;
public:
  Game();
  ~Game();
  void Draw();
  void Update();
  void HandleInput();
};


 