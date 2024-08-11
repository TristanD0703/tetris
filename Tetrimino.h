#pragma once

#include <vector>
#include "Block.h"

enum TetriminoType {
	Line,
	Square,
	S,
	SMirror,
	L,
	LMirror,
	Pyramid
};

class Tetrimino {
public:
	Tetrimino();
	~Tetrimino();

	/*
	Updates all of the currently associated blocks. Returns true if there is an adjacent piece, false otherwise.
	*/
	bool tick();

	/*
	Resets the tetrimino back to the top, and constructs new blocks that makes up the tetrimino type given.
	Appends these Blocks to the provided state.
	*/
	void reset(TetriminoType type, std::vector<Block>* currState);

	void rotateClockwise();

	void rotateCounterClockwise();
private:
	std::vector<Block*> m_blockPtrs;
	int m_xPos;
	int m_yPos;
};