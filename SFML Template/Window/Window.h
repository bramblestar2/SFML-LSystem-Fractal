#pragma once
#include <SFML/Graphics.hpp>
#include "../LSystem.h"
#include "../Turtle.h"

class Window
{
public:
	Window();
	//Free memory
	virtual ~Window();

	void run();
	void render();
	void update();
	void updateDt();
	void updateSFMLEvents();
private:
	void HSVtoRGB(float H, float S, float V, float& R, float& G, float& B);

	void initWindow();
	
	sf::Clock dtClock;
	double dt;

	sf::RenderWindow* window;
	sf::Event event;

	Turtle t;
	std::vector<Vec2f> vertices;

	void startFractal();

	sf::VertexArray lines;
	void setLines();

	sf::View v1;
	float zoom;

	sf::Vector2i startMouse;

	int steps;
};

