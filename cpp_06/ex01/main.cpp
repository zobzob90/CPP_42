/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:48 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/06 14:36:23 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <stdint.h>

int main(void)
{
	Data test(20, 'A', 50);

	std::cout << "===== DONNEES ORIGINALE =====" << std::endl;
	std::cout << "Value of Int : " << test.ValueOfInt << std::endl;
	std::cout << "Value of Char : " << test.ValueOfChar << std::endl;
	std::cout << "Value of Double : " << test.ValueOfDouble << std::endl;
	std::cout << std::endl;
	
	// Serialization pointeur vers entier
	uintptr_t	raw = Serializer::serialize(&test);
	// Deserialization entier vers pointeur
	Data*	 	ptr = Serializer::deserialize(raw);

	std::cout << "===== SERIALIZATION =====" << std::endl;
	std::cout << "Original Address : " << &test << std::endl;
	std::cout << "Serialized Value : " << raw << std::endl;
	std::cout << "Deserialized Address : " << ptr << std::endl;
	std::cout << std::endl;

	if (ptr == &test)
		std::cout << "Test successfull ! ✅" << std::endl;
	else
		std::cout << "Test Failed ! ❌" << std::endl;

	return (0);
}
