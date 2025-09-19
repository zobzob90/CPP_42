/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:46:10 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/19 17:47:13 by ertrigna         ###   ########.fr       */
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
	int intArr[4] = {1, 2 ,3 ,4};
	
	iter(intArr, 4, printElement);
	
	return (0);
}
