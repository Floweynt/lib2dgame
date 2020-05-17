#include <SFML/Graphics.hpp>
#include "json/json/json.h"
#include "types.h"

namespace world
{
    struct sprite
    {
        size_t level;

        bool hashitbox;
        types::epos hb1;
        types::epos hb2;

        bool hascollisionbox;
        types::epos cb1;
        types::epos cb2;

        bool hasinteractbox;
        types::epos ib1;
        types::epos ib2;

        types::tpos size;
        types::epos pos;
    }
}