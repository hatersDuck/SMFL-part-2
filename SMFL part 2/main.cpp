#include <SFML/Graphics.hpp>

#include "figure.h"
#include "ellipse.h"
#include "krug.h"
#include "triengale.h"
#include "rhomb.h"

#include <iostream>
using namespace sf;

//config
const Time TimePerFrame = seconds(1.f / 500.f); // FPS
const int scale[2] = { 1280, 720 }; // x, y

int main()
{
	
	srand(time(NULL));
	//Create window and tick;

	//system("cls");
	Clock clk;
	Time timeSinceLastUpdate = Time::Zero;
	//Create class
	figure* figures[9] = {new row, new rect(200.10,100.20), new rect, new rhomb, new triengale,
							new point, new krug, new ellipse, new ellipse};

	figure::setScreenSize(scale[0], scale[1]);

	RenderWindow window(VideoMode(scale[0], scale[1]), "laba 6");
	//Run
	while (window.isOpen())
	{
		Time dt = clk.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			//update
			if (!Keyboard::isKeyPressed(Keyboard::Space)) {
				for (int i = 0; i < 9; i++)
					figures[i]->update();
			}           
		}
		window.clear();
		//draw
		for (int i = 0; i < 9; i++)
			figures[i]->drawFigure(window);
		window.display();
	}
	return 0;
}
