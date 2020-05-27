#ifndef __LIB2DGAME_SPRITELOADER_H__
#define __LIB2DGAME_SPRITELOADER_H__
#include <SFML/Graphics.hpp>
#include <vector>
#include "json/json/json.h"
#include "types.h"

namespace world
{
    struct sprite
    {
        types::epos pos;
        size_t stile_number;

        bool hashitbox;
        types::epos hb1;
        types::epos hb2;

        bool hascollisionbox;
        types::epos cb1;
        types::epos cb2;

        bool hasinteractbox;
        types::epos ib1;
        types::epos ib2;
    };

    /*struct stile
    {
        types::tpos size;
        sf::Image texture;
    };*/

    typedef std::vector<sf::Image> stileset_t;
    typedef std::vector<sprite> spritelist;
}
#endif