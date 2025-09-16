/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:06:56 by eric              #+#    #+#             */
/*   Updated: 2025/09/15 11:57:09 by eric             ###   ########.fr       */
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
	
	size_t i = 0;
	if (input[0] == '+' || input[0] == '-')
		i++;
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

}

