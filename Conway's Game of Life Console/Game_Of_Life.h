#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class NonCopyable
{
public:
	NonCopyable() = default;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable(NonCopyable&&) = delete;
	NonCopyable &operator=(const NonCopyable&) = delete;
};

/*Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.*/

class Game_Of_Life : public NonCopyable
{
public:
	Game_Of_Life();
	~Game_Of_Life();

public:
	void run();
	void draw(sf::RenderTarget &target);
	void update();
	void add(const sf::Vector2i &pos);

private:
	void initCells();
	int getNeighborCount(int row, int col);

private:
	void tenCellRow();
	void glider();

private:
	const int size = 10;
	static constexpr int row = 800;
	static constexpr int column = 600;
	bool cells[row][column]; //state of cells
	sf::RectangleShape cell;

private:
	bool running;
};