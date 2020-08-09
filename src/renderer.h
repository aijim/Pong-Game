#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "board.h"
#include "ball.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(Ball const &ball, Board const &board);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif