/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:38 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/08 15:45:27 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <set>

bool isNumber(const std::string& str)
{
	if (str.empty())
		return (false);
	if (str[0] == '-')
	{
		std::cerr << "Error : Cannot accept negative number" << std::endl;
		return (false);	
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}


int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "Error : Cannot accept 1 Arguments" << std::endl;
		return (1);
	}
	std::vector<int> v;
	std::set<int> seen;
	for (int i = 1; i < ac; i++)
	{
		if (!isNumber(av[i]) || atoi(av[i]) < 0 || atoi(av[i]) > 3000)
		{
			std::cerr << "Error: invalid argument : " << av[i] << std::endl;
			return (1);
		}
		if (!seen.insert(atoi(av[i])).second) // gere les doublons
		{
			std::cerr << "Error: duplicate number : " << av[i] << std::endl;
			return (1);
		}
		v.push_back(atoi(av[i]));
	}
	Pmerge p;
	std::cout << std::endl;
	return (0);
}