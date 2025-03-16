#include "game.h"
#include "enemy.h"
#include "player.h"
#include <cmath>
#include <raylib.h>

Game::Game() {}

Game::~Game() {}

void Game::Update() {
  DrawRectangleV({0, 720 - 50}, {1080, 50}, WHITE);
  DrawRectangleV({(1080 / 2) - 100, 420}, {200, 50}, WHITE);
}

float Game::CheckDistance(Player *player) {

  Enemy enemy;

  float playerPosX = player->position.x;
  float playerPosY = player->position.y;
  float enemyPosX = enemy.position.x;
  float enemyPosY = enemy.position.y;

  float coddX = playerPosX - enemyPosX;
  float coddY = playerPosY - enemyPosY;

  float distance = std::sqrt((coddX * coddX) + (coddY * coddY));

  return distance;
}
