#ifndef __LIB2DGAME_TYPES_H__
#define __LIB2DGAME_TYPES_H__
#include <vector>
#include <SFML/Graphics.hpp>
namespace world
{
    namespace types
    {
        typedef std::vector<sf::Image> tileset_t;
        typedef std::vector<std::vector<size_t>> level_t;

		template<typename T>
		struct pos
		{
			T x;
			T y;
			pos operator*(T rhs)
			{
				pos<T> newpos;
				newpos.x = x * rhs;
				newpos.y = y * rhs;
				return newpos;
			}
			pos operator+(pos<T> second) 
			{
				pos<T> newpos;
				newpos.x = x + second.x;
				newpos.y = y + second.y;
				return newpos;
			}
		};

		typedef pos<int> tpos;
		typedef pos<double> epos;
    }
}
#endif