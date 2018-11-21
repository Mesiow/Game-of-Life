#pragma once
#include <SFML/Graphics.hpp>
#include "Game_Of_Life.h"


class App
{
public:
	App(const std::string &name);
	~App();
	App(const App&) = delete;
	App(App&&) = delete;
	App &operator=(const App&) = delete;

public:
	void run();
	void pollEvents(sf::Event &e);
	void display();
	void draw();
	void input();
	void clear();
	void update();

private:
	sf::RenderWindow window;
	static constexpr int width = 800;
	static constexpr int height = 600;
	bool updte = false;

private:
	Game_Of_Life life;
};