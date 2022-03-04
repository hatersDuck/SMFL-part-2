#include "row.h"
#include <iostream>

row::row() {
	tangle.setPrimitiveType(sf::LinesStrip);
	tangle.resize(2);

	sizeA = 100 + rand() % 80;
	a.x = pos.x - sizeA / 2.f;
	a.y = pos.y, b.y = pos.y;
	b.x = pos.x + sizeA / 2.f;

	center = pos;
	tilt *= 0.01f;

	tangle[0].position = a;
	tangle[1].position = b;

	tangle[0].color = rnColor();
	tangle[1].color = rnColor();
	dt.restart();
}

void row::update(int w, int h) {
	move();
	rotate();
	if (checkBounce(2, w, h))
		bounce(bouX);
}

void row::move() {
	figure::move();
	center += speed;
}

void row::rotate() {
	float t = dt.getElapsedTime().asMilliseconds();
	for (int i = 0; i < 2; i++) {
		float x = center.x + pow(-1, i) * sizeA * 0.5 * cos(tilt * t);
		float y = center.y + pow(-1, i) * sizeA * 0.5 * sin(tilt * t);
		tangle[i].position = sf::Vector2f(x, y);
	}
}

bool row::checkBounce(int count, int w, int h) {
	for (int i = 0; i < count; i++) {
		float x = tangle[i].position.x;
		float y = tangle[i].position.y;
		if ((x <= 0 && !right) || (x >= w && right)) {
			bouX = 1;
			return true;
		}
		else if ((y <= 0 && up) || (y >= h && !up)) {
			bouX = 0;
			return true;
		}
	}
	return false;
}