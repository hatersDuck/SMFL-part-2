#pragma once
#include "figure.h"
class row : public figure
{
public:
	row();
	void update(int, int);

	sf::VertexArray getVertex() {
		return tangle;
	}

protected:
	sf::VertexArray tangle;

	sf::Vector2f a, b;

	float sizeA, sizeB;

	void move();
	void rotate();
	bool checkBounce(int, int, int);

	sf::Clock dt;
};

