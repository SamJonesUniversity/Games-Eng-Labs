// main.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Vector2f ballVelocity;
bool server = false;

const Keyboard::Key controls[4] = 
{
	Keyboard::A, //P1 UP
	Keyboard::Z, //P1 DOWN
	Keyboard::Up, //P2 Up
	Keyboard::Down //P2 DOWN
};

const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;

CircleShape ball;
RectangleShape paddles[2];

void Load()
{
	ballVelocity = {(server ? 100.0f : -100.0f), 60.0f};

	for (auto &p : paddles)
	{
		p.setSize(paddleSize - Vector2f(3, 3));
		p.setOrigin(paddleSize / 2.f);
	}
	//Size and origin of ball
	ball.setRadius(ballRadius-3);
	ball.setOrigin(ballRadius/2, ballRadius/2);
	//reset paddle pos
	paddles[0].setPosition(10+paddleSize.x/2, gameHeight/2);
	paddles[1].setPosition(770+paddleSize.x/2, gameHeight/2);
	//reset ball pos
	ball.setPosition(gameWidth/2, gameHeight/2);
}

void Update(RenderWindow &window)
{
	//Reset clock
	static Clock clock;
	float dt = clock.restart().asSeconds();
	ball.move(ballVelocity * dt);
	//check events
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}
	}

	//Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}

	//handle paddle movement
	float direction = 0.0f;
	if (Keyboard::isKeyPressed(controls[0]))
	{
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1]))
	{
		direction++;
	}
	paddles[0].move(0, direction * paddleSpeed * dt);
}

void Render(RenderWindow &window)
{
	//Draw everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
}

int main()
{
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while (window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}
