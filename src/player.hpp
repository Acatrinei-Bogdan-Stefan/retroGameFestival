#pragma once
#include <raylib.h>

class Player
{
private:
 
 
public:
Vector2 position;
Texture2D image;
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