#include "game.h"
#include <iostream>
#include <random>
#include "SDL.h"

const double pi = 3.141592653589793;

Game::Game(std::size_t screen_width, std::size_t screen_height):
    screen_width(screen_width),
    screen_height(screen_height),
    ball(screen_width, screen_height),
    board(screen_width, screen_height){
      srand (static_cast <signed> (time(0)));
      ball.SetAngle(pi * ((float)rand() / (float) RAND_MAX));
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, board);
    Update(running);
    renderer.Render(ball, board);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update(bool &running) {

  ball.Update();
  //std::cout<<ball.x<< "," << ball.y << "," << ball.angle << std::endl;
  board.Update();

  // Check if there's food over here
  if (ball.y > screen_height - ball.size_y - board.size_y){
    if(board.x<=ball.x+ball.size_x-1 && board.x+board.size_x-1 >= ball.x ) {
      score++;
      ball.speed += 0.2;
      ball.angle = - ball.angle;
    }else{
      running = false;
    }
  }
}

int Game::GetScore() const { return score; }