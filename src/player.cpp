#include "player.h"
#include "gun.h"
#include <raylib.h>

Player::Player() {
  position = {100, 100};
  speed = {5, 0}; // speed.x for movement, speed.y for vertical velocity
  isGrounded = false;
  g = 0.15f; // Gravity acceleration
  gun = new Gun(this);
}

Player::~Player() { delete gun; }

void Player::Draw() {
  gun->Draw();
  DrawRectangleV(position, (Vector2){30, 30}, YELLOW);
}

void Player::Input() {
  if (IsKeyDown(KEY_A)) {
    position.x -= speed.x; // Move left
  }
  if (IsKeyDown(KEY_D)) {
    position.x += speed.x; // Move right
  }

  // Jumping logic
  if (isGrounded && IsKeyPressed(KEY_SPACE)) {
    speed.y = -4.5f; // Stronger jump velocity
    isGrounded = false;
  }
}

void Player::Update() {
  Input();

  gun->Update();

  // Apply gravity
  if (!isGrounded) {
    speed.y += g;          // Accumulate gravity
    position.y += speed.y; // Apply vertical speed
  }

  // Ground collision check
  float groundLevel = 720 - 50 - 30; // Adjust this based on your game's floor
  if (position.y >= groundLevel) {
    position.y = groundLevel;
    speed.y = 0; // Stop falling
    isGrounded = true;
  }
}
