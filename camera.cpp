#include "camera.h"
#include <algorithm>
#include <iostream>

namespace world
{
    void tilemap::init(types::tileset_t _tileset, types::level_t _levels, float _factor)
    {
        is_valid = false;
        is_init = false;

        if (_levels.size() == 0)
            return;
        else if (_levels[0].size() == 0)
            return;
        if (_tileset.size() == 0)
            return;

        tileset = _tileset;                     // set of all tiles to use
        levels = _levels;                       // which tiles to use
        tilesize = _tileset[0].getSize().x;     // set size of tiles (support for non-square tiles coming soon!)
        factor = _factor;
        is_valid = false;                       // you can't safely draw
        is_init = true;
    }

    int tilemap::render() // very memory and time heavy, use only once to load
    {
        if (levels.size() == 0) // nope! invalid size
        {
            is_valid = false;
            return -1;
        }

        if (!is_init)
        {
            is_valid = false;
            return -1;
        }

        const size_t ysize{levels.size()};      // get size for speed
        const size_t xsize{levels[0].size()};   // get size for speed

        sf::RenderTexture texturemapwin;                            // create RenderTexture: draws stuff to a texture because its easier
        texturemapwin.create(xsize * tilesize, ysize * tilesize);   // inits the RenderWindow


        // code to draw textures
        for (int i = 0; i < xsize; i++)
        {
            for (int j = 0; j < ysize; j++)
            {
                sf::Texture t;                                  // define the texture
                sf::Sprite s;                                   // define the sprite
                t.loadFromImage(tileset[levels[j][i]]);         // load correct image
                s.setTexture(t);                                // set sprite texture
                s.setPosition(i * tilesize, j * tilesize);      // set pos for RenderTexture, y starts at bottom not top
                texturemapwin.draw(s);
            }
        }

        texture = texturemapwin.getTexture();   // put texture into internal texture
        is_valid = true;
        return 0;
    }

    int tilemap::draw(sf::Texture texture, sf::RenderWindow* blurryvision, types::epos pos, float factor) //draw w/ pointer to RenderWindow
    {
        pos = pos * tilesize * factor;
        pos.y = blurryvision->getSize().y - pos.y;

        sf::Sprite s;
        s.setTexture(texture);
        s.setScale(factor, factor);
        s.setPosition(pos.x, pos.y);
        s.setOrigin(0, texture.getSize().y);
        blurryvision->draw(s);
        return 0;
    }

//int tilemap::draw(sf::Texture texture, sf::RenderWindow* blurryvision, types::epos pos) {
//    draw(sf::Texture texture, sf::RenderWindow* blurryvision, types::epos pos, 1.f);
//}

    int tilemap::draw(sf::RenderWindow* blurryvision, types::epos pos)  // draw with pointer to RenderWindow
    {
        if (!is_valid || !is_init)
            return -1;
        draw(texture, blurryvision, pos, factor);
        return 0;
    }
}
