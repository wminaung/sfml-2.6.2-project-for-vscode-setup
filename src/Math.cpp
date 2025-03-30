#include "Math.h"
#include <iostream>
#include <math.h>

/**
 * Normalizes a given 2D vector.
 *
 * This function calculates the magnitude of the input vector and
 * returns a new vector with the same direction but a magnitude of 1.
 *
 * @param vector The 2D vector to be normalized.
 * @return A normalized 2D vector with a magnitude of 1.
 */

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector) {
  float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
  std::cout << ">>> m : " << m << std::endl;
  sf::Vector2f normalizedVector;
  normalizedVector.x = vector.x / m;
  normalizedVector.y = vector.y / m;
  return normalizedVector;
}

bool Math::DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2) {

  if (rect1.left < rect2.left + rect2.width &&
      rect1.left + rect1.width > rect2.left &&
      rect1.top < rect2.top + rect2.height &&
      rect1.top + rect1.height > rect2.top) {
    return true;
  }

  return false;
}
