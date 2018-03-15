#include "ship.h"
#include "game.h"
#include <iostream>

using namespace sf;
using namespace std;

//sf::Texture spritesheet;
sf::Sprite invader;

void Load() {
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}

	invader.setTexture(spritesheet);
	invader.setTextureRect(sf::IntRect(0, 0, 32, 32));

	Invader* inv = new Invader(sf::IntRect(0, 0, 32, 32), {100, 100});
	ships.push_back(inv);

	/*for (int r = 0; r < invaders_rows; r++) {
		auto rect = IntRect(...);
		for (int c = 0; c < invaders_coloumns; c++) {
			Vector2f position = ...;
			auto inv = new Invader(rect, position);
			ships.push_back(inv);
		}
	}*/
}

void Update() {
	static Clock clock;
	float dt = clock.restart().asSeconds();

	for (auto &s : ships) {
		s->Update(dt);
	};
}

void Render(RenderWindow &window) {
	window.display();
	window.draw(invader);

	for (const auto s : ships) {
		window.draw(*s);
	}
}