#include "game.h"
// #include "enemy.h"
#include "player.h"
#include <raylib.h>

Game::Game() {}

Game::~Game() {}

void Game::Update() {
  // Enemy enemy;
  // Player player;
  // enemy.Update(&player);
  DrawRectangleV({0, 720 - 50}, {1080, 50}, WHITE);
  DrawRectangleV({(1080 / 2) - 100, 420}, {200, 50}, WHITE);
}
