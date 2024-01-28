#include "Base.hpp"
#include "Identify.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	Base *base = generate();
	std::cout << YELLOW << "identify(Base* p): " << RESET;
	identify(base);
	std::cout << YELLOW << "identify(Base& p): " << RESET;
	identify(*base);
	delete base;
	return (0);
}