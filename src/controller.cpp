#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "board.h"

void Controller::HandleInput(bool &running, Board &board) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          board.direction = Board::Direction::kLeft;
          break;

        case SDLK_RIGHT:
          board.direction = Board::Direction::kRight;
          break;
      }
    }else{
      board.direction = Board::Direction::kStop;
    }
  }
}