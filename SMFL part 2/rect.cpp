#include "rect.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

rect::rect() {
	tangle.setPrimitiveType(sf::Quads);
	tangle.resize(4);

	sizeB = 30 + rand() % 30;
	tangle[2].position.x = tangle[1].position.x;
	tangle[2].position.y = tangle[1].position.y - sizeB;
	tangle[3].position.x = tangle[0].position.x;
	tangle[3].position.y = tangle[0].position.y - sizeB;

	pos.x = tangle[0].position.x + sizeA * 0.5f;
	pos.y = tangle[0].position.y - sizeB*0.5f;

	radius = sqrt(pow(sizeA, 2) + pow(sizeB, 2)) * 0.5;
	angle[1] = 180 - 2 * asin(sizeB / (radius * 2)) * (180 / M_PI);
	angle[0] = 0;
	tangle[2].color = rnColor();
	tangle[3].color = rnColor();
	// not rhomb
	check = false;
}

rect::rect(float A, float B) {
	sizeA = B;
	sizeB = A;
	tangle.setPrimitiveType(sf::Quads);
	tangle.resize(4);
	tangle[2].position.x = tangle[1].position.x;
	tangle[2].position.y = tangle[1].position.y - sizeB;
	tangle[3].position.x = tangle[0].position.x;
	tangle[3].position.y = tangle[0].position.y - sizeB;

	pos.x = tangle[0].position.x + sizeA * 0.5f;
	pos.y = tangle[0].position.y - sizeB * 0.5f;

	radius = sqrt(pow(sizeA, 2) + pow(sizeB, 2)) * 0.5;
	angle[1] = 180 - 2 * asin(sizeB / (radius * 2)) * (180 / M_PI);
	angle[0] = 0;
	tangle[2].color = rnColor();
	tangle[3].color = rnColor();
	// not rhomb
	check = false;
}

void rect::update() {
	move();
	rotate();
	if (checkBounce(4))
		bounce(bouX);
}

void rect::rotate() {
	float t = dt.getElapsedTime().asMilliseconds();

	for (int i = 0, j = 0; i < 4; i++, j++) {
		//rhomb
		if (check) {
			if (radius != sizeB / 2.f)
				radius = sizeB / 2.f;
			else
				radius = sizeA / 2.f;
		}

		float x = pos.x + (i < 2 ? 1 : -1) * radius * cos(tilt * t + angle[j % 2]);
		float y = pos.y + (i < 2 ? 1 : -1) * radius * sin(tilt * t + angle[j % 2]);
		tangle[i].position = sf::Vector2f(x, y);
	}
}