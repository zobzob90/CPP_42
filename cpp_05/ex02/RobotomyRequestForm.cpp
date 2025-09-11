/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:56:06 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/11 21:38:14 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

Robotomy::Robotomy() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "Robotomy Constructor Called" << std::endl;
}

Robotomy::Robotomy(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
	std::cout << "Robotomy Param Called" << std::endl;	
}

Robotomy::Robotomy(const Robotomy& src) : AForm(src), _target(src._target)
{
	std::cout << "Robotomy Copy Constructor Called" << std::endl;
}

Robotomy &Robotomy::operator=(const Robotomy& src)
{
	std::cout << "Robotomy Operator Called" << std::endl;

	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

Robotomy::~Robotomy()
{
	std::cout << "Robotomy Destructor Called" << std::endl;
}

const std::string& Robotomy::getTarget() const
{
	return _target;
}

void Robotomy::executeAction() const
{
	std::cout << "**** LOUD AND UNBEARABLE DRILLING NOISE ****" << std::endl;

	static bool seededGen = false;

	if (!seededGen)
	{
		std::srand(std::time(NULL));
		seededGen = true;
	}
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << " !" << std::endl;
}
