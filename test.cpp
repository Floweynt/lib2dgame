#include "camera.h"
#include <iostream>

using namespace world; 				// using namespaces for convenience
using namespace types;

int main()
{
	double x = 0; 
	double y = 0;

	sf::Image green;			// example tile image
	sf::Image cyan;				// another tile for testing
	
	green.loadFromFile("green.png");	// load from file
	cyan.loadFromFile("cyan.png");

	
	tileset_t t{green, cyan};		// create tileset
	level_t l{				// create levels, which tells tilemap which tile to use
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 1, 1, 1, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 1, 1, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 1, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		};
	world::tilemap tmap (t, l);		// create tilemap; 32 is the size of the tiles
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "tilemap example");

	tmap.render(); 				// render tilemap and store to internal buffer
	while (window.isOpen())
    	{
    		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    	y-=0.01;
        	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                	x-=0.01;
        	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    	y+=0.01;
        	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    	x+=0.01;
    
        	// check all the window's events that were triggered since the last iteration of the loop
        	sf::Event event;
        	while (window.pollEvent(event))
        	{
        		// "close requested" event: we close the window
        		if (event.type == sf::Event::Closed)
        		    	window.close();
        	}

		window.clear();			// clear screen
		std::cout << "\r" << x << ", " << y << "           "; // update pos
		tmap.draw(&window, {x, y});	// redraw the tilemap (very fast)
		window.display();		// update screen
    	}		  	
}
