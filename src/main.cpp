#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

const double pi = 3.141592653589793;

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{960};
  constexpr std::size_t kScreenHeight{640};

  Renderer renderer(kScreenWidth, kScreenHeight);
  Controller controller;
  Game game(kScreenWidth, kScreenHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game over!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  return 0;
}