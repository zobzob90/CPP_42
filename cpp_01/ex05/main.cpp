/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:15:12 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/12 16:56:15 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	harl;
	
	std::cout << "🔍 Testing DEBUG:" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "📄 Testing INFO:" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "⚠️ Testing WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "💥 Testing ERROR:" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	
	std::cerr << "You're testing the wrong lvl you fool !" << std::endl;
	harl.complain("lol");
	return (0);
}
