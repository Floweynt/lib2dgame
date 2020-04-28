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
			pos& operator*(int rhs)
			{
				x *= rhs;
				y *= rhs;
				return *this;
			}
		};

		typedef pos<int> tpos;
		typedef pos<double> epos;
    }
}
