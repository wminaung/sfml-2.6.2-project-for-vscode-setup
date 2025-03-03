#include "FrameRate.h"
#include <iostream>
#include <string>

// if sometime it can force to do it that way
// it called constructor list intialization
FrameRate::FrameRate() : timer(0.f) {}

FrameRate::~FrameRate() {
  std::cout << "I am dristroy FramRate object" << std::endl;
}

void FrameRate::Initialize() {}

void FrameRate::Load() {
  if (font.loadFromFile("Assets/Fonts/Roboto.ttf")) {
    frameReteText.setFont(font);
    frameReteText.setCharacterSize(24);
    std::cout << "Font loaded" << std::endl;
  } else {
    std::cout << "Font not loaded" << std::endl;
  }
}

void FrameRate::Update(double deltaTime) {

  timer += deltaTime;
  if (timer >= 300.f) {
    double fps = (double)1000.0 / deltaTime; // Convert ms to FPS

    std::string fpsString = "FPS: " + std::to_string((int)fps) +
                            " DELTA TIME: " + std::to_string((int)deltaTime);
    frameReteText.setString(fpsString);
    timer = 0.f;
  }
}

void FrameRate::Draw(sf::RenderWindow &window) { window.draw(frameReteText); }
