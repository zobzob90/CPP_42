/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:42:40 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/03 16:51:16 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		Btc btc;

		btc.loadDatabase("data.csv");
		btc.processInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exeception : " << e.what() << '\n';
		return (1);
	}
	return (0);
}
