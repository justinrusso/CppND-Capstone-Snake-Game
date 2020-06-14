#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : grid_width(grid_width),
      grid_height(grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  snake = std::make_shared<Snake>(grid_width, grid_height);
  PlaceFood(2);
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  bool exit = false;

  while (!exit) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, exit, snake);
    Update();
    renderer.Render(snake, foods);

    // Wait for specific input to restart
    // and update high score if neccesary
    if (!snake->alive) {
      running = false;
      UpdateScore();
    }
    while (!snake->alive && !exit) {
      controller.HandleInput(running, exit, snake);
      if (running) {
        Reset();
      }
    }

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

void Game::PlaceFood(int amount) {
  int addedCount = 0;
  while (addedCount < amount) {
    SDL_Point food = {};
    PlaceFood(food);
    foods.emplace_back(food);
    addedCount++;
  }
}
void Game::PlaceFood(SDL_Point &food) {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake->SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      lastFoodPlacement = std::chrono::system_clock::now();
      return;
    }
  }
}

void Game::Update() {
  if (!snake->alive) return;

  snake->Update();

  int new_x = static_cast<int>(snake->head_x);
  int new_y = static_cast<int>(snake->head_y);

  // Check if there's food over here
  for (int i = 0; i < foods.size(); i++) {
    auto &food = foods[i];
    if (food.x == new_x && food.y == new_y) {
      score++;

      if (foods.size() == 1) {
        PlaceFood(food);
      } else {
        foods.erase(foods.begin() + i);
      }

      // Grow snake and increase speed.
      snake->GrowBody();
      snake->speed += 0.02;
    }

    if (foods.size() < maxFood) {
      auto secondsSinceFoodPlacement =
        std::chrono::duration_cast<std::chrono::seconds>(
          std::chrono::system_clock::now() - lastFoodPlacement
        ).count();
      
      if (secondsSinceFoodPlacement > 4) {
        PlaceFood(1);
      }
    }
  }
}

void Game::Reset() {
  while (foods.size() > 1) {
    foods.erase(foods.begin());
  }
  PlaceFood(foods[0]);

  snake.reset(new Snake(grid_width, grid_height));
  score = 0;
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake->size; }

void Game::UpdateScore() {
  if (GetScore() > highScore.getProperty("score")) {
    highScore.setProperty("score", GetScore());
    std::cout << "New high score!" << "\n";
  }
  std::cout << "Score: " << GetScore() << "\n";

  if (GetSize() > highScore.getProperty("size")) {
    highScore.setProperty("size", GetSize());
    std::cout << "New largest size!" << "\n";
  }
  std::cout << "Size: " << GetSize() << "\n";

  highScore.writeData();
}
