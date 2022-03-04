#pragma once
#include "figure.h"

class point : public figure
{
public:
	point();
	sf::CircleShape getPoint();

	void update(int, int);

protected:
	sf::CircleShape circle;

	bool checkBounce(int, int);
	void move();
};

