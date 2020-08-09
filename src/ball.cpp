#include "ball.h"
#include <cmath>
#include <iostream>

const double pi = 3.141592653589793;

void Ball::Update() {
  float speed_x = speed * std::cos(angle);
  float speed_y = speed * std::sin(angle);
  
  x = x + speed_x;
  y = y + speed_y;
  if(x + size_x >= screen_width){
    x = screen_width - size_x;
    angle = pi -angle;
  }else if(x <= 0){
    x = 0;
    angle = pi - angle;
  }
  if(y <= 0){
    y = 0;
    angle = -angle;
  }

}
