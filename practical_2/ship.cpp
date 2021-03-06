#include "ship.h"
#include "game.h"

using namespace sf;
using namespace std;

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite() {
		_sprite = ir;
		setTexture(spritesheet);
		setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

//Define the ship deconstructor.
//Although we set to pure vitrual, we still have to define.
Ship::~Ship() = default;

Invader::Invader() : Ship() {}
bool Invader::direction;
float Invader::speed;

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
}

void Invader::Update(const float &dt) {
	Ship::Update(dt);

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

	if ((direction && getPosition().x > gameWidth - 16) ||
		(!direction && getPosition().x < 16)) {
			direction = !direction;
			for (int i = 0; i < ships.size(); i++) {
					ships[i]->move(0,24);
			}
	}
}