#include "camera.h"

int main()
{
	using namespace world;
	using namespace types;
	sf::Image green;
	sf::Image cyan;
	green.loadFromFile("green.png");
	cyan.loadFromFile("cyan.png");
	tileset_t t{green, cyan};
	sf::Texture asdf;
	asdf.loadFromImage(t[0]);
	sf::Sprite s;
	s.setTexture(asdf);
	level_t l{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		};
	world::tilemap tmap (t, l, 32);
	sf::RenderWindow idk(sf::VideoMode(352, 320), "asdf");

	tmap.render();
	while(true){idk.clear();tmap.draw(&idk);idk.display();}
}