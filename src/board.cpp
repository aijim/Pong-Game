#include "board.h"

#include <cmath>
#include <iostream>

void Board::Update() {
  switch (direction) {
    case Direction::kLeft:
      x -= 2;
      if(x<0)
      {
          x = 0;
      }
      break;
    case Direction::kRight:
      x += 2;
      if(x + size_x > screen_width)
      {
          x = screen_width - size_x;
      }
      break;
  }
}