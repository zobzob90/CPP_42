/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:41:59 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 15:04:08 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *HeapZombie = newZombie("The Heap Zombie");
	HeapZombie->announce();
	delete HeapZombie;
	
	std::cout << std::endl;
	randomChump("The Stack Zombie");
	return (0);
}
