/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:07:05 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/03 20:34:50 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << "'\' RPN EXPRESSION" << std::endl;
		return (1);
	}
	try
	{
		RPN rpn;
		int result = rpn.calculate(av[1]);
		std::cout << result << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}	
	return (0);
}