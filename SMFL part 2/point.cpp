#include "point.h"
#include <iostream>

point::point() {
	circle.setRadius(radius = 5.f);
	
	circle.setPosition(pos);
	circle.setFillColor(color);
}

void point::update() {
	move();
	circle.move(speed);
	bouX = false;
	if (checkBounce())
		bounce(bouX);
}

bool point::checkBounce() {
	if (((pos.x <= radius) && !right) || ((pos.x >= (screenWeight - radius)) && right)) {
		bouX = true;
		return true;
	}
	else if (((pos.y <= radius) && up) || (((pos.y >= (screenHeight - radius)) && !up))) {
		bouX = false;
		return true;
	}
	return false;
}