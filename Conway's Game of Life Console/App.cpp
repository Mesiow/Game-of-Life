#include "App.h"

App::App(const std::string &name)
	:window(sf::VideoMode(width, height), name, sf::Style::Close | sf::Style::Resize),
	life()
{

}

App::~App()
{

}

void App::run()
{
	while (window.isOpen())
	{
		sf::Event e;
		pollEvents(e);

		input();
		update();

		clear();

		draw();
		
		display();
	}
}

void App::update()
{
	if (updte)
		life.update();
}

void App::pollEvents(sf::Event &e)
{
	while (window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window.close();

		case sf::Event::KeyPressed:
			updte = !updte;
			break;

		case sf::Event::Resized:
			sf::FloatRect visibleA(0, 0, e.size.width, e.size.height);
			window.setView(sf::View(visibleA)); //resize window so it does not stretch
			
		}
	}
}

void App::display()
{
	window.display();
}

void App::clear()
{
	window.clear();
}


void App::draw()
{
	life.draw(window);
}

void App::input()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		life.add(sf::Mouse::getPosition(window));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		window.setSize(sf::Vector2u(1920, 1080));
	}
}
