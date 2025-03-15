#pragma once
#include "player.h"

class Menu {
public:
  bool isOpen; // Flag to toggle the menu

  Menu();
  ~Menu();
  void Update(Player &player); // Accept Player reference
  void Draw(Player &player);
};
