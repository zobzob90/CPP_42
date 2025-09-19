/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:10:07 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/19 15:24:45 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	std::cout << "===== TESTING =====" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		Base* instance = generate();
		
		std::cout << "Test #" << (i + 1) << std::endl;

		std::cout << "Identify for pointers :" << std::endl;
		identify(instance);

		std::cout << "Identify by reference :" << std::endl;
		identify(*instance);
		
		std::cout << "Test Done !" << std::endl;
		std::cout << std::endl;
		delete (instance);
	}
	return (0);
}
