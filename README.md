# CPPND: Capstone Snake Game

This project is based off of a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

## Gameplay

To navigate the snake, use the arrow keys on your keyboard. Each food eaten increases your score.

The goal of the game is to avoid running into your snake and getting the highest score possible. If you fail, you may press `space` to restart the game.

![Snake Game gameplay](./assets/snake_game.gif)

## Development

![Snake Game Code Structure](./assets/game_structure.jpg)

### Dependencies for Running Locally

- cmake >= 3.7
  - All OSes: [click here for installation instructions](https://cmake.org/install/)
- make >= 4.1 (Linux, Mac), 3.81 (Windows)
  - Linux: make is installed by default on most Linux distros
  - Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  - Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
- SDL2 >= 2.0
  - All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  - Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
- gcc/g++ >= 5.4
  - Linux: gcc / g++ is installed by default on most Linux distros
  - Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  - Windows: recommend using [MinGW](http://www.mingw.org/)

### Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Project Tasks

The project must satisfy all criteria for the "README" and "Compiling and Testing" sections. In addition, the project must also satisfy at least 5 total criteria from the rest of the tasks.

### README

- [x] A README with instructions is included with the project
- [x] The README indicates which project is chosen.
- [x] The README includes information about each rubric point addressed.

### Compiling and Testing

- [x] The submission must compile and run.

### Loops, Functions, & IO

- [x] The project demonstrates an understanding of C++ functions and control structures.
- [x] The project reads data from a file and process the data, or the program writes data to a file.
- [ ] The project accepts user input and processes the input.

### Object Oriented Programming

- [x] The project uses Object Oriented Programming techniques.
- [x] Classes use appropriate access specifiers for class members.
- [x] Class constructors utilize member initialization lists.
- [ ] Classes abstract implementation details from their interfaces.
- [x] Classes encapsulate behavior.
- [ ] Classes follow an appropriate inheritance hierarchy.
- [x] Overloaded functions allow the same function to operate on different parameters.
- [ ] Derived class functions override virtual base class functions.
- [ ] Templates generalize functions in the project.

### Memory Management

- [x] The project makes use of references in function declarations.
- [x] The project uses destructors appropriately.
- [ ] The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
- [x] The project follows the Rule of 5.
- [ ] The project uses move semantics to move data, instead of copying it, where possible.
- [x] The project uses smart pointers instead of raw pointers.

### Concurrency

- [ ] The project uses multithreading.
- [ ] A promise and future is used in the project.
- [ ] A mutex or lock is used in the project.
- [ ] A condition variable is used in the project.
