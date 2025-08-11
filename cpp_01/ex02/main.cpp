/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:33:16 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/11 16:44:09 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string str = "Hi this is brain.";
	std::string* str_ptr = &str;
	std::string& str_ref = str;

	std::cout << "Memory adress of the string variable " << &str << std::endl;
	std::cout << "Memory adress held by the str_ptr " << str_ptr << std::endl;
	std::cout << "Memory adress held by str_ref " << &str_ref << std::endl;
	
	std::cout << std::endl;

	std::cout << "Value of the variable " << str << std::endl;
	std::cout << "Value pointed to by str_ptr " << *str_ptr << std::endl;
	std::cout << "Value pointed to by str_ref " << str_ref << std::endl;
}
