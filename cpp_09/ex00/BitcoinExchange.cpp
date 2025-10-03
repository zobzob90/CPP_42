/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:42:34 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/03 17:47:38 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*PARSING PART*/
bool	Btc::isValidDate(const std::string& date) const
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

	int year 	= atoi(date.substr(0, 4).c_str());
	int month	= atoi(date.substr(5, 2).c_str());
	int day 	= atoi(date.substr(8, 2).c_str());
	
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

bool Btc::isValidExtent(const std::string& extension) const
{
	if (extension != ".txt" && extension != ".csv")
		return (false);
	return (true);
}

bool	Btc::isValidValue(double value) const
{
	if (value < 0)
	{
		std::cerr << "Error : value is negative" << std::endl;
		return (false); 
	}
	else if (value > 1000)
	{
		std::cerr << "Error : value is too big" << std::endl;
		return (false);
	}
	else
		return (true);
}

std::string Btc::trim(const std::string& str) const
{
	size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, (last - first + 1));
}

double	Btc::getRateForDate(const std::string& date) const
{
	// chercher un match exact
	std::map<std::string, double>::const_iterator search = _ctnrRates.find(date);
	if (search != _ctnrRates.end())
		return search->second; // second renvoi la rate (first est donc la date)
	// chercher une date correspondante
	std::map<std::string, double>::const_iterator occ = _ctnrRates.lower_bound(date); // lower_bound permet de trouver une correspondance a date
	if (occ == _ctnrRates.begin())
		throw std::runtime_error("No Rate for the date before : " + date);
	--occ;
	return occ->second;
}

/*MAIN FUNCTION*/
void	Btc::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error opening " + filename);
	std::string extension = filename.substr(filename.find_last_of('.'));
	if (!isValidExtent(extension))
		throw std::runtime_error("Invalid extension for " + filename);
	std::string line; // contiendra les lignes lue
	std::getline(file, line); // ignore la premiere ligne
	while (std::getline(file, line))
	{
		size_t separator = line.find(',');
		if (separator == std::string::npos)
			continue; // ligne invalide
		std::string date = line.substr(0, separator);
		double rate = atof(line.substr(separator + 1).c_str());
		_ctnrRates[date] = rate;	
	}
}

void	Btc::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error opening " + filename);
	std::string exstention = filename.substr(filename.find_last_of('.'));
	if (!isValidExtent(exstention))
		throw std::runtime_error("Invalid extension for " + filename);
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t separator = line.find('|');
		if (separator == std::string::npos)
		{
			std::cerr << "Error: invalid line => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, separator));
		if (!isValidDate(date))
		{
			std::cerr << "Error invalid date format => " << date << std::endl;
			std::cerr << "Date should be like this YYYY-MM-DD" << std::endl;
			continue;
		}
		std::string valueStr = trim(line.substr(separator + 1));
		double value = atof(valueStr.c_str());
		if (!isValidValue(value))
		{
			std::cerr << "Error invalid value format => " << value << std::endl;
			continue;
		}
		double rate = getRateForDate(date);
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
}
