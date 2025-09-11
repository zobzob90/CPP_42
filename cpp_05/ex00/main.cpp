/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:33 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/11 11:39:03 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	// valid Bureaucrat
	try
	{
		Bureaucrat a("Norbert", 100);
		if (a.getName() == "Norbert" && a.getGrade() == 100)
			std::cout << "Test 1 is passed" << std::endl;
		else
			std::cout << "Test 1 is failed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Test 1 failed:  " << e.what() << std::endl;	
	}
	std::cout << std::endl;
	// invalid bureaucrat grade too high
	try
	{
		Bureaucrat b("Gerard", 0);
		if (b.getName() == "Gerard" && b.getGrade() == 0)
			std::cout << "Test 2 failed:  Exception not thrown" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Test 2 passed : " << e.what() << std::endl;	
	}
	std::cout << std::endl;
	//invalid bureaucrat grade too low
	try
	{
		Bureaucrat c("Geraldine", 151);
		if (c.getName() == "Geraldine" && c.getGrade() == 151)
			std::cout << "Test 3 failed:  Exception not thrown" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Test 3 passed : " << e.what() << std::endl;	
	}
	std::cout << std::endl;
	// bureaucrat with increment
	try
	{
		Bureaucrat d ("Gustave", 50);
		d.incrementGrade();
		if (d.getName() == "Gustave" && d.getGrade() == 49)
			std::cout << "Test 4.1 passed" << std::endl;
		else
			std::cout << "Test 4.1 failed" << std::endl;
		d.decrementGrade();
		if (d.getName() == "Gustave" && d.getGrade() == 50)
			std::cout << "Test 4.2 passed" << std::endl;
		else
			std::cout << "Test 4.2 failed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Test 4 failed :" << e.what() << std::endl;	
	}
	return (0);
}
