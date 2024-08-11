#pragma once
#include "Block.h"
#include <vector>

class Game {
public:
	Game(int boardWidth, int boardHeight, int queueCount, int initialDropSpeed);

	~Game();

	void start();

private:
	int m_boardWidth;
	int m_boardHeight;
	int m_queueCount;
	int m_dropSpeed;

	/*
	* Array of blocks that represent the current state of the grid
	*/
	std::vector<Block> m_grid;
};