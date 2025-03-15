#include "gun.h"
#include "player.h"
#include <cmath>
#include <raylib.h>

Gun::Gun(Player *player) {
  this->player = player;
  pos = player->position;
}

Gun::~Gun() {}

void Gun::Draw() {
  DrawRectanglePro((Rectangle){player->position.x, player->position.y, 35, 5},
                   (Vector2){25, 25}, angle, BLUE);

  // Draw a line from the object to the mouse (for visualization)
  DrawLineV(player->position, mousePos, DARKGRAY);
}

void Gun::Update() {
  mousePos = GetMousePosition();
  angle =
      atan2f(mousePos.y - player->position.y, mousePos.x - player->position.y) *
      180.0f / PI;
  pos = {player->position.x + 20, player->position.y + 10};
}
