#pragma once
#include <stdint.h>

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

class Block {
public:
	Block(int xPos, int yPos, Color color);
	~Block();

	void updatePos(int xPos, int yPos);
	void changeColor(Color color);

	void render();
private:
	int m_xPos;
	int m_yPos;
	Color m_color;
};