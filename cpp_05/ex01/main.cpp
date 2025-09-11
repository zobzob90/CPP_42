/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:32:00 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/11 15:54:12 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== TEST 1: Valid Form Creation ===" << std::endl;
	try
	{
		Form f1("Contract A", 50, 25);
		std::cout << f1 << std::endl;
		std::cout << "✓ Form created successfully" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "✗ Test 1 failed: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 2: Invalid Form (grade too high) ===" << std::endl;
	try
	{
		Form f2("Invalid Form", 0, 25);
		std::cout << "✗ Test 2 failed: Exception not thrown" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "✓ Test 2 passed: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 3: Invalid Form (grade too low) ===" << std::endl;
	try
	{
		Form f3("Invalid Form", 50, 151);
		std::cout << "✗ Test 3 failed: Exception not thrown" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "✓ Test 3 passed: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 4: Successful Form Signing ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 10);
		Form contract("Important Contract", 50, 25);
		
		std::cout << "Before signing: " << contract << std::endl;
		boss.signForm(contract);
		std::cout << "After signing: " << contract << std::endl;
		std::cout << "✓ Test 4 passed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "✗ Test 4 failed: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 5: Failed Form Signing (insufficient grade) ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		Form topSecret("Top Secret", 10, 5);
		
		std::cout << "Before signing attempt: " << topSecret << std::endl;
		intern.signForm(topSecret);
		std::cout << "After signing attempt: " << topSecret << std::endl;
		std::cout << "✓ Test 5 passed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "✗ Test 5 failed: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 6: Form Copy Constructor ===" << std::endl;
	try
	{
		Form original("Original", 42, 21);
		Form copy(original);
		
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
		std::cout << "✓ Test 6 passed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "✗ Test 6 failed: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== TEST 7: beSigned direct call ===" << std::endl;
	try
	{
		Bureaucrat manager("Manager", 30);
		Form permit("Building Permit", 40, 20);
		
		std::cout << "Before beSigned: " << permit << std::endl;
		permit.beSigned(manager);
		std::cout << "After beSigned: " << permit << std::endl;
		std::cout << "✓ Test 7 passed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "✗ Test 7 failed: " << e.what() << std::endl;
	}

	return 0;
}
