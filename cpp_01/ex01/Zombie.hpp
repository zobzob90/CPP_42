/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:35:02 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 15:52:44 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstring>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(); // constructeur
		~Zombie(); // destructeur
		void	setName(const std::string& name);
		void	announce()const;
};

Zombie* zombieHorde( int N, std::string name );

#endif