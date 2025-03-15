#include "rlImGui.h"
#include "src/game.h"
#include "src/menu.h"
#include "src/player.h"
#include <iostream>
#include <raylib.h>

int main() {
  InitWindow(1080, 720, "Platformer");
  // SetWindowState(FLAG_FULLSCREEN_MODE);
  Player player;
  Menu menu;
  Game game;

  rlImGuiSetup(true);
  SetTargetFPS(60);

  HideCursor();

  while (!WindowShouldClose()) {
    player.Update();
    menu.Update(player);

    BeginDrawing();
    ClearBackground(BLACK);

    player.Draw();
    menu.Draw(player);
    game.Update();

    EndDrawing();
  }

  rlImGuiShutdown();
  CloseWindow();
  return 0;
}
