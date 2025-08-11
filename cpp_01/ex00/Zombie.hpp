/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:49:18 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 15:02:02 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cctype>

class Zombie
{
	private:
		std::string name; //nom du Zombie en prive
	public:
		Zombie(const std::string& name); // constructeur
		~Zombie(); // destructeur
		void	announce() const;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif