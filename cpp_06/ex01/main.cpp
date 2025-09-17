/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:46:48 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/17 14:57:55 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <stdint.h>

int main(void)
{
	Data test(42, 'A', 75);

	std::cout << "===== DONNEES ORIGINALE =====" << std::endl;
	std::cout << "Value of Int : " << test.ValueOfInt << std::endl;
	std::cout << "Value of Char : " << test.ValueOfChar << std::endl;
	std::cout << "Value of Double : " << test.ValueOfDouble << std::endl;
	std::cout << std::endl;
	
	// Serialization pointeur vers entier
	uintptr_t	raw = Serializer::serialize(&test);
	// Deserialization entier vers pointeur
	Data*	 	ptr = Serializer::deserialize(raw);

	std::cout << "Original Adress : " << &test << std::endl;
	std::cout << "Adress after Serialize / Deserialize : " << ptr << std::endl;

	if (ptr == &test)
		std::cout << "Test successfull ! ✅" << std::endl;
	else
		std::cout << "Test Failed ! ❌" << std::endl;

	return (0);
}
