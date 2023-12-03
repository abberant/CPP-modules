#include "Point.hpp"

int main(void)
{
	Point	a(0, 0);
	Point	b(0, 1);
	Point	c(1, 0);
	Point	point(0.5f, 0.5f);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "point: " << point << std::endl;
	std::cout << "bsp(a, b, c, point): " << bsp(a, b, c, point) << std::endl;
	return (0);
}