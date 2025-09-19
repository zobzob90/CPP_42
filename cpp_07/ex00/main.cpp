/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:29:05 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/19 16:39:24 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;
	std::cout << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a , b);
	std::cout << "Apres Swap : " << "a = " << a << ", b  = " << b << std::endl;
	std::cout << "min (a , b) = " << ::min(a, b) << std ::endl;
	std::cout << "max (a , b) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine 1";
	std::string d = "chaine 2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(a, b);
	std::cout << "Apres Swap : " << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min (c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max (c, d) = " << ::max(c, d) << std::endl;
	std::cout << std::endl;

	return (0);
}
