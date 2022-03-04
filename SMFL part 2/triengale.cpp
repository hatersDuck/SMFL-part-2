#include "triengale.h"
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>


triengale::triengale() {
	tangle.setPrimitiveType(sf::Triangles);
	tangle.resize(3);
	tangle[2].position = tangle[1].position + rnVector(200,sizeA*2);

	std::cout << "BBBB";
	float lenght[3] = {
		sqrt(pow(tangle[1].position.x - tangle[0].position.x, 2) + pow(tangle[1].position.y - tangle[0].position.y, 2)),
		sqrt(pow(tangle[2].position.x - tangle[1].position.x, 2) + pow(tangle[2].position.y - tangle[1].position.y, 2)),
		sqrt(pow(tangle[0].position.x - tangle[2].position.x, 2) + pow(tangle[0].position.y - tangle[2].position.y, 2))
	};
	angle[0] = acos((pow(lenght[0], 2) + pow(lenght[2], 2) - pow(lenght[1], 2)) / (2 * lenght[0] * lenght[2]));
	angle[1] = acos((pow(lenght[0], 2) + pow(lenght[1], 2) - pow(lenght[2], 2)) / (2 * lenght[0] * lenght[1]));
	angle[2] = acos((pow(lenght[2], 2) + pow(lenght[1], 2) - pow(lenght[0], 2)) / (2 * lenght[2] * lenght[1]));
	for (int i = 0; i < 3; i++)
		angle[i] *= (180 / M_PI);

	center.x = (tangle[0].position.x + tangle[1].position.x + tangle[2].position.x) / 3.f;
	center.y = (tangle[0].position.y + tangle[1].position.y + tangle[2].position.y) / 3.f;

	r[0] = sqrt(pow(center.x - tangle[0].position.x, 2) + pow(center.y - tangle[0].position.y, 2));
	r[1] = sqrt(pow(center.x - tangle[1].position.x, 2) + pow(center.y - tangle[1].position.y, 2));
	r[2] = sqrt(pow(center.x - tangle[2].position.x, 2) + pow(center.y - tangle[2].position.y, 2));

	tangle[0].color = color;
	tangle[1].color = rnColor();
	tangle[2].color = rnColor();
}

void triengale::update(int w, int h) {
	move();
	rotate();
	if (checkBounce(3, w, h))
		bounce(bouX);
}

void triengale::rotate() {
	float t = dt.getElapsedTime().asMilliseconds();
	for (int i = 0; i < 3; i++) {
		float x = center.x + r[i] * cos(tilt * t + angle[i]);
		float y = center.y + r[i] * sin(tilt * t + angle[i]);
		tangle[i].position = sf::Vector2f(x, y);
	}
}
