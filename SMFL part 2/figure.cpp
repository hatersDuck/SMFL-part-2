#include "figure.h"
#include <iostream>

using namespace std;

figure::figure() {
	color = rnColor();
	screenWeight = 1280;
	screenHeight = 720;
	speed = rnVector(-50, 50);
	antiSinhr();

	pos = rnVector(10000, 50000);
	tilt = (1 + rand() % 10) / 100.f;
	
	checkCD.restart();

}

int figure::screenHeight;
int figure::screenWeight;

void figure::antiSinhr() {
	cs = speed.x / (sqrt(pow(speed.x, 2) + pow(speed.y, 2)));
	right = speed.x > 0 ? 1 : 0;
	up = speed.y < 0 ? 1 : 0;
}

void figure::move() {
	pos += speed;
}

void figure::bounce(bool x) {
	if (checkCD.getElapsedTime().asSeconds() > cooldown.asSeconds()) {
		if (x)
			speed.x *= -1;
		else
			speed.y *= -1;
		antiSinhr();
		checkCD.restart();
	}
}

void figure::update() {
	std::cout << "Check\n";
}

sf::Vector2f figure::rnVector(int min, int max, bool x, bool y) {
	return sf::Vector2f(
		x * (min + rand() % (max - min)) / 100.f,
		y * (min + rand() % (max - min)) / 100.f);
}

sf::Color figure::rnColor() {
	return sf::Color(
		100 + rand() % 155,
		100 + rand() % 155,
		100 + rand() % 155);
}