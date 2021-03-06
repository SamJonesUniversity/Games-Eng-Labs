#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
protected:
	sf::IntRect _sprite;
	//Default constructor is hidden
	Ship();
public:
	//Constructor that takes a sprite
	explicit Ship(sf::IntRect ir);
	//Pure virtual deconstrictor -- makes this and abstract class
	virtual ~Ship() = 0;
	//Update virtual so can be overriden but not pure virtual
	virtual void Update(const float &dt);
};

class Invader : public Ship {
public:
	static bool direction;
	static float speed;
	Invader(sf::IntRect ir, sf::Vector2f pos);
	Invader();
	void Update(const float &dt) override;
};