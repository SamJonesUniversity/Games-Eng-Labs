#pragma once
#include <SFML/Graphics.hpp>

constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;
constexpr uint16_t invaders_rows = 5;
constexpr uint16_t invaders_colums = 12;

std::vector<Ship *> ships;
sf::Texture spritesheet;