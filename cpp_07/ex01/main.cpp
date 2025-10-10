/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:46:10 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/10 11:19:51 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	printElement(const T& x)
{
	std::cout << x;
}

template<typename T>
void	isEvenOrOdd(const T& x)
{
	if (x % 2 == 0)
		std::cout << x << " is even" << std::endl;
	else if (x % 3 == 0)
		 std::cout << x << " is odd" << std::endl;
}

int main(void)
{
	int		intArr[4] = {1, 2 ,3 ,4};
	char	charArray[6] = "Hello";
	double	doubleArr[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
	int		evenArr[1] = {4};
	int		oddArr[1] = {3};
	
	std::cout << "=== Testing with int array ===" << std::endl;
	iter(intArr, 4, printElement);
	std::cout << "\n=== Testing with char array ===" << std::endl;
	iter(charArray, 6, printElement);
	std::cout << "\n=== Testing with double array ===" << std::endl;
	iter(doubleArr, 10, printElement);
	std::cout << std::endl;

	std::cout << "=== TESTING ODD OR EVEN ===" << std::endl;
	iter(evenArr, 1, isEvenOrOdd);
	iter(oddArr, 1, isEvenOrOdd);
	
	return (0);
}
