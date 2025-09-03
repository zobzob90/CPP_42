/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:15:06 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/03 11:26:19 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << "🐛 lvl: " << "I love having extra bacon for my 7XL double cheese triple pickle special ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "ℹ️ lvl: " << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "⚠️ lvl: " << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;	
}

void	Harl::error(void)
{
	std::cout << "⛔ lvl: " << "This is unacceptable! I want to speak to the manager now !" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*complaints[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (lvls[i] == level)
		{
			switch (i)
			{
				case 0:
					(this->*complaints[0])();
					return;
				case 1:
					(this->*complaints[1])();
					return;
				case 2:
					(this->*complaints[2])();
					return;
				case 3:
					(this->*complaints[3])();
					return;
			}
		}
	}
	std::cerr << "Error: Invalid level" << std::endl;
}
