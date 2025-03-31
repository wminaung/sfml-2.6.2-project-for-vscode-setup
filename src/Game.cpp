#include "Game.h"

// Private Fnction
void Game::initVariable() { this->window = nullptr; }

void Game::initWindow() {
  videoMode.height = 600;
  videoMode.width = 800;
  this->window = new sf::RenderWindow(videoMode, "My Game",
                                      sf::Style::Titlebar | sf::Style::Close);
}

// Constructor
Game::Game(/* args */) {
  //
  this->initVariable();
  this->initWindow();
}

// Destructor
Game::~Game() {
  //
  delete this->window;
}

// Accessors
const bool Game::running() const {
  //
  return this->window->isOpen();
}

// Functions

void Game::pollEvents() {

  while (this->window->pollEvent(this->ev)) {
    switch (this->ev.type) {
    case sf::Event::Closed:
      this->window->close();
      break;

    case sf::Event::KeyPressed:
      if (this->ev.key.code == sf::Keyboard::Escape) {
        this->window->close();
      }
      break;

    default:
      break;
    }
  }
}

void Game::update() {
  // Game Update
  this->pollEvents();
}

void Game::render() {
  /*
    @return void
    - clear old frame
    - render objects
    - display frame in window
    Renders the game object
  */
  this->window->clear(sf::Color(255, 0, 0, 255));
  this->window->display();
}
