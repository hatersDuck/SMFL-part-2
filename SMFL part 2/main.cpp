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
	ellipse po;
	krug ro;
	row rr;
	rect re;
	triengale tr(false);
	rhomb rh;
	//Create window and tick;
	RenderWindow window(VideoMode(scale[0], scale[1]), "laba 4");
	//system("cls");
	Clock clk;
	Time timeSinceLastUpdate = Time::Zero;

	// no texture coordinates here, we'll see that later
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
				po.update(scale[0], scale[1]);
				ro.update(scale[0], scale[1]);
				rr.update(scale[0], scale[1]);
				tr.update(scale[0], scale[1]);
				re.update(scale[0], scale[1]);
				rh.update(scale[0], scale[1]);
			}           
		}
		window.clear();
		//draw
		window.draw(po.getPoint());
		window.draw(ro.getPoint());
		window.draw(rr.getVertex());
		window.draw(tr.getVertex());
		window.draw(re.getVertex());
		window.draw(rh.getVertex());
		window.display();
	}
	return 0;
}
