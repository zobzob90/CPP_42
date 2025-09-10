#include "Salade.hpp"

//constructeur
Salade::Salade() : AMateria("salade")
{
	// std::cout << "Salade Constructor Called" << std::endl;
}

Salade::Salade(const Salade& src) : AMateria(src)
{
	// std::cout << "Salade Copy constructor Called" << std::endl;
}

//operateur
Salade &Salade::operator=(const Salade& src)
{
	// std::cout << "Salade operator called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

//destructeur
Salade::~Salade()
{
	// std::cout << "Salade Destructor Called" << std::endl;
}

AMateria* Salade::clone() const
{
	return new Salade(*this);
}

void Salade::use(ICharacter& target)
{
	std::cout << "* use salade de phalange" << target.getName() << " *" << std::endl;
}
