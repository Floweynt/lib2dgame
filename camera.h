#ifndef __LIB2DGAME_CAMERA_H__
#define __LIB2DGAME_CAMERA_H__

#include <SFML/Graphics.hpp>
#include "types.h"

namespace world
{
    class tilemap // very memory heavy, ONE per program, and maniplate
    {
    protected:
        types::tileset_t tileset;   // tileset (set of tiles)
        types::level_t levels;      // 2d array of tiles to use (change to array not vector?)
        size_t tilesize;            // size of each tile
        float factor;               // wanted size / tilesize
        sf::Texture texture;        // internal texture buffer
        bool is_valid;              // is it valid?
        bool is_init;               // is it initalized?
        virtual int draw(sf::Texture, sf::RenderWindow* blurryvision, types::epos pos);
    public:
        inline tilemap() { is_valid = false; is_init = false; }
        inline tilemap(types::tileset_t _tileset, types::level_t _levels) { this->init(_tileset, _levels); }
        virtual void init(types::tileset_t _tileset, types::level_t _levels);
        virtual int render(); // very memory and time heavy, use only once to load
        virtual int draw(sf::RenderWindow* blurryvision, types::epos pos);
    };
}
#endif
