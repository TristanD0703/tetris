#pragma once
#include "Block.h"
#include "Tetrimino.h"
#include <stdlib.h>
#include <vector>
#include <SDL3/SDL.h>

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
	bool m_isRunning;

	/*
	* Array of blocks that represent the current state of the grid
	*/
	std::vector<Block> m_grid;
	std::vector<TetriminoType> m_tetriminoQueue;

	SDL_Window* m_window = nullptr;
	SDL_Surface* m_windowSurface = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	const int WIDTH = 400;
	const int HEIGHT = 600;

	void handleEvents();
	void render();
	void drawBoard();
};