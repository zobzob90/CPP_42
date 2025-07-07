/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:30 by ertrigna          #+#    #+#             */
/*   Updated: 2025/07/07 14:32:35 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

std::string RES = "\033[0m";
std::string RED = "\033[31m";
std::string GREEN = "\033[32m";

int	main(int ac, char *av[])
{
	int	i = 1;
	
	if (ac == 1)
	{
		std:: cout << RED << "* LOUD AND UNBEARABLE FEADBACK NOISE *" << RES << std::endl;
		return (0);	
	}
	else
	{
		while (i < ac)
		{
			int j = 0;
			while (av[i][j])
			{
				std::cout << GREEN << (char)toupper(av[i][j]) << RES;
				j++;		
			}
			if (i < ac - 1)
				std::cout << " ";
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
