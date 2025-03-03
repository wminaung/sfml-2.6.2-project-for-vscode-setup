#pragma once
#include <SFML/Graphics.hpp>

class FrameRate {
private:
  sf::Text frameReteText;
  sf::Font font;
  double timer;

public:
  FrameRate();
  ~FrameRate();
  /*
   *  called per app start
   */
  void Initialize();
  /*
   *  called per app start
   */
  void Load();

  /*
   *  once per frame
   */
  void Update(double deltaTime);
  /*
   *  once per frame
   */
  void Draw(sf::RenderWindow &window);
};
