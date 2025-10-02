/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:42:34 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/02 19:25:12 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*PARSING PART*/
bool Btc::isValidDate(const std::string& date) const
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7) // si i est a egale a 4 ou 7 alors on continue parce que ce sont les '-'
			continue;
		if (!isdigit(date[i]))
			return (false);
	}
	int year 	= std::stoi(date.substr(0, 4));
	int month	= std::stoi(date.substr(5, 2));
	int day 	= std::stoi(date.substr(8, 2));
	
	if (month < 1 || month > 12)
		return (false);
	int	monthDays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (leap)
		monthDays[2] = 29;
	if (day < 1 || day > monthDays[month])
		return (false);
	return (true);
}


bool Btc::isValidValue(double value) const
{
	if (value < 0 || value > 1000)
		return (false);
	return (true);
}

double Btc::getRateForDate(const std::string& date) const
{
	
}

// main function
void Btc::loadDatabase(const std::string& filename)
{
	
}

void Btc::processInput(const std::string& filename)
{
	
}