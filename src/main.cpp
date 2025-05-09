#include "FrameRate.h"
#include "Map.h"
#include "Player.h"
#include "Skeleton.h"
#include <SFML/Graphics.hpp>

template <typename T> void println(T t) { std::cout << t << std::endl; }

int main() {

  // Create the window
  //------------ Initialize ------------

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(1280, 720), "RPG-Game V0.0.1",
                          sf::Style::Default, settings);
  // vsync on // not a good way to do it
  // but we should use combination with delta time
  // delta time is the time between two frames
  window.setVerticalSyncEnabled(true);
  // window.setFramerateLimit(360);
  //------------ Initialize ------------

  sf::Text frameReteText;
  sf::Font font;

  FrameRate frameRate;
  Player player;
  Skeleton skeleton;
  Map map;
  frameRate.Initialize();
  map.Initialize();
  player.Initialize();
  skeleton.Initialize();

  //------------ Initialize ------------
  //------------ Load ------------

  frameRate.Load();
  map.Load();
  player.Load();
  skeleton.Load();
  //------------ Load ------------

  sf::Clock clock;
  // Start the game loop
  while (window.isOpen()) {
    sf::Time time = clock.restart();

    /* --------- UPDATE --------- */
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

    double deltaTime = time.asMicroseconds() / 1000.0;
    frameRate.Update(deltaTime);
    map.Update(deltaTime);
    player.Update(deltaTime, skeleton, mousePosition);
    skeleton.Update(deltaTime);

    /* --------- UPDATE --------- */

    /* --------- DRAW --------- */
    window.clear(sf::Color::Black);

    map.Draw(window);
    skeleton.Draw(window);
    player.Draw(window);
    frameRate.Draw(window);
    window.display();
    /* --------- DRAW --------- */
  }

  return 0;
}
