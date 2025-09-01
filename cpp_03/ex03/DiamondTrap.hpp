/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:02:06 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/01 13:43:24 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;208m"
#define BLUE "\033[34m"
#define GREY "\033[90m"
#define CYAN "\033[36m"
#define GOLD "\033[33;1m"
#define PINK "\033[35m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

class DiamondTrap : public ScavTrap
{
	private :
		std::string Name;
	public :
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap& operator=(const DiamondTrap& src);
		~DiamondTrap();
		void	whoAmI();
} ;

#endif