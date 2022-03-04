#include <SFML/Graphics.hpp>
#include "ellipse.h"
#include "krug.h"
#include "triengale.h"
#include "rhomb.h"
#include <iostream>
using namespace sf;

//config
const Time TimePerFrame = seconds(1.f / 500.f); // FPS
const int scale[2] = { 1280, 720 }; // x, y
const int countPoints = 100;

int main()
{
	srand(time(NULL));
	//Create class
	row* rows[4]= {new row, new rect, new rhomb, new triengale};
	point* points[4]= {new point, new krug, new ellipse, new ellipse};
	//Create window and tick;
	RenderWindow window(VideoMode(scale[0], scale[1]), "laba 5");
	//system("cls");
	Clock clk;
	Time timeSinceLastUpdate = Time::Zero;
	//Run
	
	while (window.isOpen())
	{
		Time dt = clk.restart();
		timeSinceLastUpdate += dt;
		Event event;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			//update
			if (!Keyboard::isKeyPressed(Keyboard::Space)) {
				for (int i = 0; i < 4; i++) {
					rows[i]->update(scale[0], scale[1]);
					points[i]->update(scale[0], scale[1]);
				}
			}           
		}
		window.clear();
		//draw
		for (int i = 0; i < 4; i++) {
			window.draw(rows[i]->getVertex());
			window.draw(points[i]->getPoint());
		}
		window.display();
	}
	return 0;
}
