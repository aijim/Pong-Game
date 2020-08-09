#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "ball.h"
#include "board.h"

class Game {
 public:
  Game(std::size_t screen_width, std::size_t screen_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

 private:
  Board board;
  Ball ball;

  std::random_device dev;
  std::mt19937 engine;

  int score{0};

  void Update(bool &running);

private:
  int screen_width;
  int screen_height;
};

#endif