#ifndef SALADE_HPP
#define SALADE_HPP

#include <iostream>
#include "AMateria.hpp"

class Salade : public AMateria
{
	public:
		Salade();
		Salade(const Salade& src);
		Salade &operator=(const Salade& src);
		virtual ~Salade();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
} ;

#endif