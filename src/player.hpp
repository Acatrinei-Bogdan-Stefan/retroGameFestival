#pragma once
#include <raylib.h>

class Player
{
private:
 Texture2D image;
 Vector2 position;
public:
  Player(/* args */);
  ~Player();
  void Draw();

  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void MoveDown();
  void MoveUpRight();
  void MoveUpLeft();
  void MoveDownRight();
  void MoveDownLeft();
  
  void FireLaser();
};