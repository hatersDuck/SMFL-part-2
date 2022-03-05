#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class figure
{
public:
	
	virtual void drawFigure(sf::RenderWindow& wind) {
		std::cout << "Failed\n";
	}
	virtual void update();

	static void setScreenSize(int w, int h) {
		screenWeight = w;
		screenHeight = h;
	}

protected:

	static int screenWeight;
	static int screenHeight;
	figure();
	//main math vectors
	sf::Vector2f pos, speed;
	sf::Color color;
	
	// defoult par
	float tilt, scale = 1.f;
	bool up, right, bouX = false;
	float cs;
	float radius;

	// static


	//random fun
	sf::Vector2f rnVector(int min = 50, int max = 125, bool x = true, bool y = true);
	sf::Color rnColor();

	void bounce(bool x = false);

	void move();




private:
	sf::Time cooldown = sf::seconds(0.3f);
	sf::Clock checkCD;
	void antiSinhr();

};