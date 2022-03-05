#pragma once
#include "figure.h"

class point : public figure
{
public:
	point();

	void drawFigure(sf::RenderWindow& wind) {
		wind.draw(circle);
	}

	void update();

protected:
	sf::CircleShape circle;

	bool checkBounce();
};

