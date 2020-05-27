#include "lib2dgame.h"
#include <iostream>

using namespace world; 				// using namespaces for convenience
using namespace types;

int main()
{
	double x = 0; 
	double y = 0;

	sf::Image grass1;			// example tile image
	sf::Image grass2;				// another tile for testing
	
	grass1.loadFromFile("assets/tiles/grass_var1.png");	// load from file
	grass2.loadFromFile("assets/tiles/path_var2.png");

	
	tileset_t t{grass1, grass2};		// create tileset
	level_t l{				// create levels, which tells tilemap which tile to use
		{0, 0, 0, 1, 1, 0, 0, 0}, 
		{0, 0, 0, 1, 1, 0, 0, 0}, 
		{0, 0, 0, 1, 1, 0, 0, 0}, 
		{1, 1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 1, 1, 0, 0, 0}, 
		{0, 0, 0, 1, 1, 0, 0, 0}, 
		{0, 0, 0, 1, 1, 0, 0, 0}, 
		};

	world::sprite s;
	s.pos = {1,1};
	s.stile_number = 0;

	sf::Image test;
	test.loadFromFile("assets/sprites/slime_lightLeft_idle.png");

	world::room tmap (t, l, {test}, {s});		// create tilemap; 32 is the size of the tiles
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "tilemap example");

	tmap.render(); 				// render tilemap and store to internal buffer
	while (window.isOpen())
    {
    	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            y+=0.002;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            x-=0.002;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            y-=0.002;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            x+=0.002;
    
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
