#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <memory>
#include <random>
#include "SDL.h"
#include "controller.h"
#include "gamedata.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  void UpdateScore();

 private:
  GameData highScore{"high-score.txt"};

  std::shared_ptr<Snake> snake;
  std::vector<SDL_Point> foods;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int grid_width;
  int grid_height;

  int score{0};
  const int maxFood{4};
  std::chrono::_V2::system_clock::time_point lastFoodPlacement;

  void PlaceFood(int amount);
  void PlaceFood(SDL_Point &food);
  void Update();
  void Reset();
};

#endif