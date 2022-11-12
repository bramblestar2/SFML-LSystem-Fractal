#include "Window.h"

Window::Window()
{
	initWindow();

	steps = 2;
	zoom = 1;

	startFractal();

	v1.setCenter(window->getSize().x/2, window->getSize().y/2);
	v1.setSize(window->getSize().x, window->getSize().y);
	window->setView(v1);

	setLines();

	//for (int i = 0; i < vertices.size(); i++)
	//	std::cout << vertices.at(i).x << " - " << vertices.at(i).y << std::endl;
}

Window::~Window()
{
	delete window;
}

void Window::run()
{
	while (window->isOpen())
	{
		update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}

void Window::render()
{
	window->clear();

	window->draw(lines);

	window->display();
}

void Window::update()
{
}

void Window::updateDt()
{
	dt = dtClock.restart().asSeconds();
}

void Window::updateSFMLEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed ||
			event.key.code == sf::Keyboard::Escape)
			window->close();

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				startMouse = sf::Mouse::getPosition();
			}

		}

		if (event.type == sf::Event::MouseMoved)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i endMouse = sf::Mouse::getPosition();
				v1.move((startMouse.x - endMouse.x) * zoom, (startMouse.y - endMouse.y) * zoom);
				startMouse = sf::Mouse::getPosition();

				window->setView(v1);
			}
		}

		if (event.type == sf::Event::MouseWheelScrolled)
		{
			if (event.mouseWheelScroll.delta == -1)
			{
				v1.zoom(0.9);
				zoom -= 0.1;
			}
			else if (event.mouseWheel.delta == 0)
			{
				v1.zoom(1.1);
				zoom += 0.1;
			}

			window->setView(v1);
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Left && steps > 0)
			{
				steps--;
				startFractal();
				setLines();
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				steps++;
				startFractal();
				setLines();
			}

			if (event.key.code == sf::Keyboard::W)
				v1.move(0, -5);
			else if (event.key.code == sf::Keyboard::S)
				v1.move(0, 5);

			if (event.key.code == sf::Keyboard::A)
				v1.move(-5, 0);
			else if (event.key.code == sf::Keyboard::D)
				v1.move(5, 0);

			window->setView(v1);
		}
	}
}

void Window::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(500, 500), "TITLE", sf::Style::Default);
	window->setFramerateLimit(60);
}

void Window::startFractal()
{
	window->setTitle("Loading...");

	//Terdragon
	RuleSet rs;
	rs.addRule("F", "F+F-F");

	LSystem lsys("F", rs);
	std::string lString = lsys.getString(steps);

	t.clear();
	t.setPosition(300, 200);
	t.setHeading(0);

	for (int i = 0; i < lString.length(); i++)
	{
		if (lString.at(i) == 'F')
			t.move(5);
		else if (lString.at(i) == '+')
			t.rt(120);
		else if (lString.at(i) == '-')
			t.lt(120);
	}

	vertices = t.getVertices();

	window->setTitle("TITLE");
}

void Window::setLines()
{
	lines = sf::VertexArray(sf::TrianglesStrip, vertices.size());

	int hue = 0;

	for (int i = 0; i < vertices.size(); i++)
	{
		hue = fmod(hue + 10, 360);

		float r = 0;
		float g = 0;
		float b = 0;

		HSVtoRGB(hue, 100, 100, r, g, b);

		lines[i] = (sf::Vertex(sf::Vector2f(vertices.at(i).x, vertices.at(i).y), sf::Color(r,g,b)));
	}
}


void Window::HSVtoRGB(float H, float S, float V, float& R, float& G, float& B) {
	if (H > 360 || H < 0 || S>100 || S < 0 || V>100 || V < 0) {
		std::cout << "The givem HSV values are not in valid range" << std::endl;
		return;
	}
	float s = S / 100;
	float v = V / 100;
	float C = s * v;
	float X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
	float m = v - C;
	float r, g, b;
	if (H >= 0 && H < 60) {
		r = C, g = X, b = 0;
	}
	else if (H >= 60 && H < 120) {
		r = X, g = C, b = 0;
	}
	else if (H >= 120 && H < 180) {
		r = 0, g = C, b = X;
	}
	else if (H >= 180 && H < 240) {
		r = 0, g = X, b = C;
	}
	else if (H >= 240 && H < 300) {
		r = X, g = 0, b = C;
	}
	else {
		r = C, g = 0, b = X;
	}
	R = (r + m) * 255;
	G = (g + m) * 255;
	B = (b + m) * 255;
}