#include "Game_Of_Life.h"
#include <random>
#include <Windows.h>

Game_Of_Life::Game_Of_Life()
	:running(true)
{
	cell.setSize(sf::Vector2f(size, size));
	cell.setFillColor(sf::Color::White);
	tenCellRow();
	glider();
}

Game_Of_Life::~Game_Of_Life()
{

}

void Game_Of_Life::run()
{

}

void Game_Of_Life::draw(sf::RenderTarget &target)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (cells[i][j] == true)
			{
				cell.setPosition(sf::Vector2f(i * size, j * size));
				target.draw(cell);
			}
				
		}
	}
}

void Game_Of_Life::add(const sf::Vector2i &pos)
{
	cells[(int)pos.x / size][(int)pos.y / size] = true;
}

void Game_Of_Life::update()
{
		bool newCells[row][column];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				int count = getNeighborCount(i, j);
				if (cells[i][j] == true) //alive
				{
					if (count < 2)
						newCells[i][j] = false; //cell dies due to underpopulation
					else if (count == 2 || count == 3)//cell lives on to next gen
						newCells[i][j] = true;
					else if (count > 3) //cell dies due to overpopulation
						newCells[i][j] = false;
				}
				else //cell becomes alive due to reproduction
				{
					if (count == 3)
						newCells[i][j] = true;
				}
			}
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cells[i][j] = false;
				cells[i][j] = newCells[i][j];
			}
		}
}

int Game_Of_Life::getNeighborCount(int row, int col)
{
	int count = 0;

	if (cells[row - 1][col] == true) //check cells' all eight neighbors
		count++;
	if (cells[row - 1][col - 1] == true)
		count++;
	if (cells[row][col - 1] == true)
		count++;
	if (cells[row + 1][col - 1] == true)
		count++;
	if (cells[row + 1][col] == true)
		count++;
	if (cells[row + 1][col + 1] == true)
		count++;
	if (cells[row][col + 1] == true)
		count++;
	if (cells[row - 1][col + 1] == true)
		count++;

	return count;
}

void Game_Of_Life::tenCellRow()
{
	for (int i = 0; i < 10; i++)
	{
		cells[40 + i][25] = true;
	}
}

void Game_Of_Life::glider()
{
	cells[20][25] = false;
	cells[20 - 1][25] = true;
	cells[20][25 + 1] = true;
	cells[20 + 1][25 + 1] = true;
	cells[20 + 1][25] = true;
    cells[20 + 1][25 - 1] = true;
}
