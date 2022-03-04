#pragma once
#include <SFML/Graphics.hpp>

class figure
{

protected:
	figure();
	//main math vectors
	sf::Vector2f pos, speed;
	sf::Color color;
	sf::Vector2f center;
	
	// defoult par
	float tilt, scale = 1.f;
	bool up, right, bouX = false;
	float cs;
	float radius;

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

