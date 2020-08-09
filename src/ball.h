#ifndef BALL_H
#define BALL_H

class Ball {
 public:
  Ball(int screen_width, int screen_height)
      : screen_width(screen_width),
        screen_height(screen_height),
        x((screen_width-20)/2),
        y(0){}

  void Update();
  void SetAngle(double theta)
  {
    angle = theta;
  }

  float speed{2.0};
  float x;
  float y;
  float angle;
  const int size_x{20};
  const int size_y{20};

 private:
  int screen_width;
  int screen_height;
};

#endif