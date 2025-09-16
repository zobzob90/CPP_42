/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:06:56 by eric              #+#    #+#             */
/*   Updated: 2025/09/16 16:45:42 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(){}

Scalar::Scalar(const Scalar& src)
{
	(void)src;
}

Scalar& Scalar::operator=(const Scalar& src)
{
	(void)src;
	return (*this);
}

Scalar::~Scalar(){}

/*Boolean for detecting the type*/

bool Scalar::isChar(const std::string& input)
{
	return (input.length() == 3 && input[0] == '\'' && input[2] == '\'');
}

bool Scalar::isInt(const std::string& input)
{
	if (input.empty())
		return (false);
	
	// Don't accept just a sign or just a dot
	if (input == "+" || input == "-" || input == ".")
		return (false);
		
	size_t i = 0;
	if (input[0] == '+' || input[0] == '-')
		i++;
		
	// Must have at least one digit after sign
	if (i >= input.length())
		return (false);
		
	for(; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool Scalar::isFloat(const std::string& input)
{
	if (input.empty())
		return (false);

	if (input == "nanf" || input == "+inff" || input == "-inff")
		return (true);

	if (input.length() < 2 || input[input.length() -1] != 'f')	
		return (false);

	bool	hasDecimal = false;
	size_t 	i = 0;

	if (input[0] == '+' || input[0] == '-')
		i++;
		
	// Must have at least one digit
	if (i >= input.length() - 1)
		return (false);
		
	for (; i < input.length() -1 ; i++)
	{
		if (input[i] == '.')
		{
			if (hasDecimal)
				return (false);
			hasDecimal = true;
		}
		else if (!std::isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool Scalar::isDouble(const std::string& input)
{
	if (input.empty())
		return (false);

	if (input == "nan" || input == "+inf" || input == "-inf")
		return (true);

	size_t i = 0;
	bool hasDecimal = false;
	bool hasE = false;

	if (input[0] == '+' || input[0] == '-')
		i++;
	
	// Must have at least one digit
	if (i >= input.length())
		return (false);
	
	for (; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			if (hasDecimal || hasE)
				return (false);
			hasDecimal = true;
		}
		else if (input[i] == 'e' || input[i] == 'E')
		{
			if (hasE)
				return (false);
			hasE = true;
			// After 'e', we can have +/- and then digits
			if (i + 1 < input.length() && (input[i + 1] == '+' || input[i + 1] == '-'))
				i++;
			// Must have at least one digit after e+/-
			if (i + 1 >= input.length() || !std::isdigit(input[i + 1]))
				return (false);
		}
		else if (!std::isdigit(input[i]))
			return (false);
	}
	
	// For normal numbers, require a decimal point OR scientific notation to distinguish from int
	return hasDecimal || hasE;
}

void Scalar::convertChar(const std::string& input)
{
	char c = input[1];

	std::cout << "Char : '" << c << "'" << std::endl;
	std::cout << "Int : " << static_cast<int> (c) << std::endl;
	std::cout << "Float : " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double : " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void Scalar::convertInt(const std::string& input)
{
	// Additional safety check - this should never be reached if isInt() works correctly
	if (!isInt(input))
	{
		std::cout << "Invalid Input, please try again" << std::endl;
		return;
	}
	
	int value;
	std::istringstream iss(input);
	iss >> value;
	
	if (iss.fail() || !iss.eof())
	{
		std::cout << "Char :	Impossible" << std::endl;
		std::cout << "Int :		Impossible" << std::endl;
		std::cout << "Float:	Impossible" << std::endl;
		std::cout << "Double:	Impossible" << std::endl;
		return ;
	}
	
	if (value < 0 || value > 127)
		std::cout << "Char : Value Impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "Char : Value non displayable" << std::endl;
	else
		std::cout << "Char : " << static_cast<char>(value) << std::endl;
	
	std::cout << "Int : " << value << std::endl;
	std::cout << "Float : " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "Double : " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;  	
}

void Scalar::convertFloat(const std::string& input)
{
	// Additional safety check
	if (!isFloat(input))
	{
		std::cout << "Invalid Input, please try again" << std::endl;
		return;
	}
	
	float value;

	if (input == "nanf")
		value = std::numeric_limits<float>::quiet_NaN();
	else if (input == "+inff")
		value = std::numeric_limits<float>::infinity();
	else if (input == "-inff")
		value = -std::numeric_limits<float>::infinity();
	else
	{
		std::istringstream iss(input.substr(0, input.length() - 1));
		iss >> value;
		if (iss.fail())
		{
			std::cout << "Char :	Impossible" << std::endl;
			std::cout << "Int :		Impossible" << std::endl;
			std::cout << "Float:	Impossible" << std::endl;
			std::cout << "Double:	Impossible" << std::endl;
			return ;	
		}
	}

	//FOR CHAR CONVERSION
	if (std::isnan(value) || std::isinf(value))
		std::cout << "Char : Impossible" << std::endl;
	else if (value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "Char : Impossible" << std::endl;
	else if (static_cast<int>(value) < 32 || static_cast<int>(value) > 126)
		std::cout << "Char : Non displayable" << std::endl;
	else
		std::cout << "Char : '" << static_cast<char>(value) << "'" << std::endl;

	//FOR INT CONVERSION
	if (std::isnan(value) || std::isinf(value) || value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX))
		std::cout << "Int : Impossible" << std::endl;
	else
		std::cout << "Int : " << static_cast<int>(value) << std::endl;		

	std::cout << "Float : " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	std::cout << "Double : " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;  	
}

void Scalar::convertDouble(const std::string& input)
{
	// Additional safety check
	if (!isDouble(input))
	{
		std::cout << "Invalid Input, please try again" << std::endl;
		return;
	}
	
	double value;

	if (input == "nan")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (input == "+inf")
		value = std::numeric_limits<double>::infinity();
	else if (input == "-inf")
		value = -std::numeric_limits<double>::infinity();
	else
	{
		std::istringstream iss(input);
		iss >> value;
		if (iss.fail())
		{
			std::cout << "Char :	Impossible" << std::endl;
			std::cout << "Int :		Impossible" << std::endl;
			std::cout << "Float:	Impossible" << std::endl;
			std::cout << "Double:	Impossible" << std::endl;
			return ;	
		}
	}
	//FOR CHAR CONVERSION
	if (std::isnan(value) || std::isinf(value))
		std::cout << "Char : Impossible" << std::endl;
	else if (value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "Char : Impossible" << std::endl;
	else if (static_cast<int>(value) < 32 || static_cast<int>(value) > 126)
		std::cout << "Char : Non displayable" << std::endl;
	else
		std::cout << "Char : '" << static_cast<char>(value) << "'" << std::endl;

	//FOR INT CONVERSION
	if (std::isnan(value) || std::isinf(value) || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "Int : Impossible" << std::endl;
	else
		std::cout << "Int : " << static_cast<int>(value) << std::endl;		

	std::cout << "Float : " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double : " << std::fixed << std::setprecision(1) << value << std::endl;
}

void Scalar::convert(const std::string& input)
{
	if (isChar(input))
		convertChar(input);
	else if (isFloat(input))
		convertFloat(input);
	else if (isDouble(input))
		convertDouble(input);
	else if (isInt(input))
		convertInt(input);
	else
		std::cout << "Invalid Input, please try again" << std::endl ;
}
