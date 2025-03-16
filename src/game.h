#pragma once

#include "player.h"
class Game {
public:
  Game();
  ~Game();
  void Update();
  float CheckDistance(Player *player);

private:
};
