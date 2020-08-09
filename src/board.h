#ifndef BOARD_H
#define BOARD_H

class Board {
 public:
  enum class Direction {kLeft, kRight, kStop};

  Board(int screen_width, int screen_height)
      : screen_width(screen_width),
        screen_height(screen_height),
        x((screen_width-100)/2),
        y(screen_height-20){}

  void Update();

  int x;
  const int y;
  const int size_x{100};
  const int size_y{20};
  Direction direction;

 private:
  int screen_width;
  int screen_height;
};

#endif