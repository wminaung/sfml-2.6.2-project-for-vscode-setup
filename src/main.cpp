
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void Update(RectangleShape &square, RenderWindow &window);
void Draw(RenderWindow &window, RectangleShape &square);

int main() {
  int keyTime = 8;

  RenderWindow window(VideoMode(800, 600), "Simple shoot the target",
                      Style::Default);
  window.setFramerateLimit(144);

  CircleShape hoop;
  hoop.setFillColor(Color::Black);
  CircleShape ball;

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
    window.clear(Color::White);

    // Draw stuff
    window.draw(hoop);
    window.display();
    /////////////

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
