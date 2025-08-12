/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:01:38 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/12 15:53:48 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cerr << "USAGE : <filename> <s1> <s2> !" << std::endl;
		return (1);
	}
	else
	{
		if (!is_valid(av[1], av[2], av[3]))
		{
			std::cerr << "Impossible to replace the string !" << std::endl;
			return (1);
		}
		std::cout << "String is replace !" << std::endl;
	}
	return (0);
}
