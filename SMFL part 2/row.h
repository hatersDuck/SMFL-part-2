#pragma once
#include "figure.h"


class row : public figure
{
public:
	row();
	void update();

	void drawFigure(sf::RenderWindow& wind) {
		wind.draw(tangle);
	}

protected:
	sf::VertexArray tangle;

	sf::Vector2f a, b;

	float sizeA, sizeB;

	void rotate();
	bool checkBounce(int);

	sf::Clock dt;
};

