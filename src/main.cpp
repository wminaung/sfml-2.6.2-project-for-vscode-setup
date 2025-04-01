
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void Update(RectangleShape &square, RenderWindow &window);
void Draw(RenderWindow &window, RectangleShape &square);

int main() {
  int keyTime = 8;

  RenderWindow window(VideoMode(800, 600), "Simple Square Swag",
                      Style::Default);
  window.setFramerateLimit(144);

  RectangleShape square(Vector2f(100.f, 100.f));
  square.setFillColor(Color::Red);
  square.setPosition(window.getSize().x / 2, window.getSize().y / 2);
  ///////
  Event event;
  while (window.isOpen()) {
    while (window.pollEvent(event)) { // Proper event handling
      if (event.type == Event::Closed) {
        window.close();
      }

      if (event.KeyPressed) {
        if (event.key.code == Keyboard::Escape) {
          window.close();
        }
      }
    }
    /////////////////////////

    /////////////
    Update(square, window);
    Draw(window, square);
    // end game loop
  }
  return 0;
}

void Update(RectangleShape &square, RenderWindow &window) {

  if (Keyboard::isKeyPressed(Keyboard::A) && square.getPosition().x > 0) {
    square.move(-5.f, 0.f);
  }
  if (Keyboard::isKeyPressed(Keyboard::D) &&
      square.getPosition().x + square.getSize().x < window.getSize().x) {
    square.move(5.f, 0.f);
  }
  if (Keyboard::isKeyPressed(Keyboard::W)) {
    square.move(0.f, -5.f);
  }
  if (Keyboard::isKeyPressed(Keyboard::S)) {
    square.move(0.f, 5.f);
  }
  if (Mouse::isButtonPressed(Mouse::Left)) {
    square.setFillColor(Color::Blue);
  }
}

void Draw(RenderWindow &window, RectangleShape &square) {
  window.clear();

  // Draw stuff
  window.draw(square);
  window.display();
};
