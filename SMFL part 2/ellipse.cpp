#include "ellipse.h"
#include <iostream>
#include <Windows.h>
using namespace std;

ellipse::ellipse() {
	circle.setRadius(radius = 75.f);
	circle.setScale(1.f , scale = 0.5f);
	circle.setOrigin(sf::Vector2f(radius, radius));

	b = radius * scale;
	p = pow(b, 2) / radius;
	c = sqrt(pow(radius, 2) - b * b);
	p = sqrt(pow(c, 2) + (p, 2));
}

void ellipse::update() {
	move();
	circle.move(speed);
	circle.rotate(tilt);

	int angle = int(circle.getRotation())%180;
	bool check = checkBounce();
	bool temp = bouX;
	float rate = p * pow(cos(angle),2);
	int h = screenHeight;
	int w = screenWeight;
	//blue
	if (angle <= 35 || angle >= 145) {
		if (angle <= 15 || angle >= 165) {
			if (((pos.y <= b) && up) ||
				((pos.y >= h - b) && !up)) {
				bounce();
				check = false;
			}
		}
		else {
			if (((pos.y <= rate) && up) ||
				((pos.y >= h - rate) && !up)) {
				bounce();
				check = false;
			}
		}
		temp = true;
	}
	// yellow
	else if (angle >= 70 && angle <= 130) {
		if (angle >= 85 && angle <= 110) {
			if (((pos.x <= b) && !right) ||
				((pos.x >= w - b) && right)) {
				bounce(1);
				check = false;
			}
		}
		else {
			if (((pos.x <= rate) && !right) ||
				((pos.x >= w - rate) && right)) {
				bounce(1);
				check = false;
			}
		}
		temp = false;
	}
	// red
	if (check) {
		if (bouX && temp)
			bounce(1);
		else if (!bouX && !temp)
			bounce();
	}
}
