#include <SFML/Graphics.hpp>
#include "types.h"
#include "spriteloader.h"

namespace world
{
    class tilemap // very memory heavy, ONE per program, and maniplate
    {
        types::tileset_t tileset;   // tileset (set of tiles)
        types::tileset_t stileset;  // tileset for sprite
        std::vector<sprite> sprites;// all the sprites in a room 
        types::level_t levels;      // 2d array of tiles to use (change to array not vector?)
        size_t tilesize;            // size of each tile
        sf::Texture texture;        // internal texture buffer
        bool is_valid;              // is it valid?
        bool is_init;               // is it initalized?
public:
        inline tilemap() { is_valid = false; is_init = false; }
        inline tilemap(types::tileset_t _tileset, types::level_t _levels, size_t _tilesize) { this->init(_tileset, _levels, _tilesize); }
        void addsprite(sprite s);
        void init(types::tileset_t _tileset, types::level_t _levels, size_t _tilesize);
        int render(); // very memory and time heavy, use only once to load
        int draw(sf::RenderWindow* blurryvision, types::epos pos);
    };
}