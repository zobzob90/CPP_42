/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:46:10 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/08 15:27:24 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	printElement(const T& x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	int		intArr[4] = {1, 2 ,3 ,4};
	char	charArray[6] = "Hello";
	
	std::cout << "=== Testing with int array ===" << std::endl;
	iter(intArr, 4, printElement);
	std::cout << "\n=== Testing with char array ===" << std::endl;
	iter(charArray, 5, printElement);
	
	return (0);
}
