#include "menu.h"
// #include "enemy.h"
#include "player.h"
#include "rlImGui.h"
#include <imgui.h>
#include <raylib.h>

Menu::Menu() {
  isOpen = true; // Menu starts open
}

Menu::~Menu() {}

void Menu::Update(Player &player) {
  if (IsKeyPressed(KEY_M)) { // Press 'M' to toggle menu
    isOpen = !isOpen;
  }
}

void Menu::Draw(Player &player) {
  if (!isOpen)
    return; // If menu is closed, do nothing

  rlImGuiBegin();
  // Enemy enemy;
  if (ImGui::Begin("Menu", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::Text("Modify Player Properties");
    ImGui::SliderFloat("Speed X", &player.speed.x, 1.0f,
                       100.0f); // Adjust player speed
    ImGui::SliderFloat("Speed Y", &player.speed.y, 1.0f, 100.0f);
    ImGui::SliderFloat("position x", &player.position.x, -GetScreenWidth(),
                       GetScreenWidth());
    ImGui::SliderFloat("position y", &player.position.y, -GetScreenHeight(),
                       GetScreenHeight());
    ImGui::SliderFloat("Gravity", &player.g, 0.0001f, 1.0f);
    // ImGui::Text("Distance: %.2f", enemy.CalculateDistance(&player));
    if (ImGui::Button("isGrounded")) {
      player.isGrounded = !player.isGrounded;
    }
    if (ImGui::Button("Close")) {
      isOpen = false;
    }
    ImGui::End();
  }
  rlImGuiEnd();
}
