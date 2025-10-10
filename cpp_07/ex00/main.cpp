/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:29:05 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/10 11:43:03 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	int a = 2; // test type simple
	int b = 3;
	std::cout << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a , b);
	std::cout << "Apres Swap : " << "a = " << a << ", b  = " << b << std::endl;
	std::cout << "min (a , b) = " << ::min(a, b) << std::endl;
	std::cout << "max (a , b) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine 1"; // test STL complexe
	std::string d = "chaine 2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "Apres Swap : " << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min (c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max (c, d) = " << ::max(c, d) << std::endl;
	std::cout << std::endl;

	std::cout << "Test with a complex type" << std::endl;  // test STL perso
	Test t1(1, 2);
	Test t2(3, 4);
	std::cout << "t1 = " << t1 << ", t2 = " << t2 << std::endl;
	std::cout << "min(t1, t2) = " << ::min(t1, t2) << std::endl;
	std::cout << "max(t1, t2) = " << ::max(t1, t2) << std::endl;
	::swap(t1, t2);
	std::cout << "After Swap : t1 = " << t1 << ", t2 = " << t2 << std::endl; 

	return (0);
}
