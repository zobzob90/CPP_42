/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:54:52 by eric              #+#    #+#             */
/*   Updated: 2025/08/27 10:30:31 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(const std::string Name);
		ScavTrap(const ScavTrap& src);
		ScavTrap &operator=(const ScavTrap& src);
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
} ;

#endif