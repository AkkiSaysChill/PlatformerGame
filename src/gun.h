#pragma once
#include "player.h"
#include <raylib.h>

class Gun {
public:
  Vector2 pos;
  Player *player; // Pointer to the player
  Vector2 mousePos;
  float angle;

  Gun(Player *player); // Constructor takes a Player reference
  ~Gun();

  void Draw();
  void Update();
};
