#pragma once
#include "player.h"
#include <raylib.h>

class Enemy {
public:
  Enemy();
  ~Enemy();
  void Draw();
  void Update(Player *player);
  void Move(Player *player);
  Vector2 position;
  Vector2 speed;
};
