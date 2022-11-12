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


	LSystem lsys;
	void startFractal();
	void newLSystem(std::string);
	std::vector<std::string> lSystemFiles;
	int selectedLSystem;

	sf::VertexArray lines;
	void setLines();

	sf::View v1;
	sf::Vector2f viewScale;
	float zoom;
	void changeViewScale();

	sf::Vector2i startMouse;
	sf::Vector2f smoothMove;

	int steps;


	float lerp(float, float, float);
};

