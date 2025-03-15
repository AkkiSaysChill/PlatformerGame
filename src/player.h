#pragma once

#include <raylib.h>

class Gun;

class Player {
public:
  Player();
  ~Player();
  void Draw();
  void Update();
  void Input();
  Vector2 speed;
  bool isGrounded;
  Vector2 position;
  float g;
  Gun *gun;

private:
};
