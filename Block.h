#pragma once
#include <stdint.h>

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

struct Block {
public:
	/**
	* The x position of the block in the *grid* (not in pixels)
	*/
	int xPos;

	/**
	* The y position of the block in the *grid* (not in pixels)
	*/
	int yPos;

	Color color;
};

/*
* Compares 2 block structs. Positive if block 1 > block 2. Negative if 
* block1 < block2. 0 if equal.
*/
static int compareBlocks(Block* block1, Block* block2) {
	int block1Total = block1->xPos + block1->yPos;
	int block2Total = block2->xPos + block2->yPos;
	return block1Total - block2Total;
};

