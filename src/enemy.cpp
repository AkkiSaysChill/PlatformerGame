#include "enemy.h"
#include "game.h"
#include "player.h"
#include <cmath>
#include <iostream>
#include <raylib.h>

Enemy::Enemy() {
  position = {100, 100};
  speed = {5, 5};
}

Enemy::~Enemy() {}

void Enemy::Draw() {
  // comment
  DrawRectangleV(position, {50, 50}, RED);
}

void Enemy::Move(Player *player) {
  if (!player)
    return; // Ensure player is valid

  float playerPosX = player->position.x;
  float playerPosY = player->position.y;
  float enemyPosX = this->position.x;
  float enemyPosY = this->position.y;

  float distX = playerPosX - enemyPosX;
  float distY = playerPosY - enemyPosY;

  float dist =
      std::sqrt(distX * distX + distY * distY); // Calculate Euclidean distance

  if (dist > 0) { // Move towards the player
    if (distX > 0)
      this->position.x += speed.x;
    else if (distX < 0)
      this->position.x -= speed.x;

    if (distY > 0)
      this->position.y += speed.y;
    else if (distY < 0)
      this->position.y -= speed.y;
  }
}

void Enemy::Update(Player *player) {
  Draw();
  Move(player);
}
