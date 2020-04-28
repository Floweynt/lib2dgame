#include <vector>
#include <SFML/Graphics.hpp>

namespace world
{
    namespace types
    {
        typedef std::vector<sf::Image> tileset_t;
        typedef std::vector<std::vector<size_t> > level_t;
    }
}
