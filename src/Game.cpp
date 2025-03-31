#include "Game.h"

// Private Fnction
void Game::initVariable() { this->window = nullptr; }

void Game::initWindow() {
  videoMode.height = 600;
  videoMode.width = 800;
  this->window = new sf::RenderWindow(videoMode, "My Game",
                                      sf::Style::Titlebar | sf::Style::Close);

  this->window->setFramerateLimit(60);
}

void Game::initEnemies() {
  //
  this->enemy.setPosition(10.f, 10.f);
  this->enemy.setSize(sf::Vector2f(100.f, 100.f));
  this->enemy.setScale(2.f, 1.f);
  this->enemy.setFillColor(sf::Color::Cyan);
  this->enemy.setOutlineColor(sf::Color::Green);
  this->enemy.setOutlineThickness(3.f);
}

// Constructor
Game::Game(/* args */) {
  //
  this->initVariable();
  this->initWindow();
  this->initEnemies();
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

  // window relative
  std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << ", "
            << sf::Mouse::getPosition().y << std::endl;

  // view relative
  this->pollEvents();
  std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << ", "
            << sf::Mouse::getPosition(*this->window).y << std::endl;
}

void Game::render() {
  /*
    @return void
    - clear old frame
    - render objects
    - display frame in window
    Renders the game object
  */
  this->window->clear();

  // Draw game Objects
  this->window->draw(this->enemy);

  this->window->display();
}
