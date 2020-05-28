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
			pos() {}
			pos(T _x, T _y) 
			{
				x = _x;
				y = _y;
			}
			pos operator*(T rhs)
			{
				pos<T> newpos(x * rhs, y * rhs);
				return newpos;
			}
			pos operator+(pos<T> second) 
			{
				pos<T> newpos(x + second.x, y + second.y);
				return newpos;
			}
			pos operator-(pos<T> second) 
			{
				pos<T> newpos = *this + (second * -1);
				return newpos;
			}
		};

		typedef pos<int> tpos;
		typedef pos<double> epos;
    }
}
#endif