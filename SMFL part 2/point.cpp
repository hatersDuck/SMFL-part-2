#include "point.h"
#include <iostream>

point::point() {
	circle.setRadius(radius = 5.f);
	
	circle.setPosition(pos);
	circle.setFillColor(color);
}

void point::update(int w, int h) {
	move();
	bouX = false;
	if (checkBounce(w, h))
		bounce(bouX);
}

bool point::checkBounce(int w, int h) {
	if (((pos.x <= radius) && !right) || ((pos.x >= (w - radius)) && right)) {
		bouX = true;
		return true;
	}
	else if (((pos.y <= radius) && up) || (((pos.y >= (h - radius)) && !up))) {
		bouX = false;
		return true;
	}
	return false;
}

void point::move() {
	figure::move();
	circle. move(speed);
}

sf::CircleShape point::getPoint() {
	return circle;
}
