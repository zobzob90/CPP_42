/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:56:42 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 16:19:04 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int	N = 5;
	Zombie* Horde = zombieHorde(N, "The Horde");
	if (Horde)
	{
		for (int i = 0; i < N; ++i)
			Horde[i].announce();
		delete[] Horde;
	}
	else
		std::cout << "Can't create zombie Horde" << std::endl;
}
