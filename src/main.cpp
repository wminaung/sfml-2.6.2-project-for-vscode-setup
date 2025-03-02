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
  // but we can use delta time
  // delta time is the time between two frames
  // window.setVerticalSyncEnabled(true);
  //------------ Initialize ------------

  Player player;
  Skeleton skeleton;
  player.Initialize();
  skeleton.Initialize();
  //------------ Initialize ------------
  //------------ Load ------------
  player.Load();
  skeleton.Load();
  //------------ Load ------------

  sf::Clock clock;
  // Start the game loop
  while (window.isOpen()) {
    sf::Time time = clock.restart();
    float deltaTime = time.asSeconds() * 1000.0f;
    /* --------- UPDATE --------- */
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    player.Update(deltaTime, skeleton);
    skeleton.Update(deltaTime);

    /* --------- UPDATE --------- */

    /* --------- DRAW --------- */
    window.clear(sf::Color::Black);
    skeleton.Draw(window);
    player.Draw(window);
    window.display();
    /* --------- DRAW --------- */
  }

  return 0;
}
