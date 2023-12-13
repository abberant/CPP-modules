#include "AbstractAnimal.hpp"

AAnimal::AAnimal() : _type("Unlabeled")
{
	std::cout << "Default abstract animal constructed!" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Abstract animal of type " << type << " constructed!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "Abstract animal of type: " << _type << " copy-constructed!" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Abstract animal of type: " << _type << " destructed!" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string	AAnimal::getType() const
{
	return (_type);
}