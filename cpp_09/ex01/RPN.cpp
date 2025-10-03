/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:07:08 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/03 20:29:14 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	RPN::isOp(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int		RPN::applyOp(char op, int a, int b) const
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/' :
			if (b == 0)
				throw std::runtime_error("Error : no division by 0 !");
			return a / b;
		default:
			throw std::runtime_error("Error : Unknown Operator");
	}
}

int	RPN::calculate(const std::string& args)
{
	std::istringstream	iss(args);
	std::string 		token;

	while (iss >> token) // tant que iss est extrait de token on lance la boucle
	{
		if (token.size() == 1 && isOp(token[0]))
		{
			if(_stack.size() < 2)
				throw std::runtime_error("Error: Not enough operator !");
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			_stack.push(applyOp(token[0], a, b));	
		}
		else
		{
			for (size_t i = 0; i < token.size(); i++)
			{
				if (!isdigit(token[i]) && !(i == 0 && token[i] == '-'))
					throw std::runtime_error("Error : invalid arguments !");
			}
			int value = atoi(token.c_str());
			_stack.push(value);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error : Invalid expression !");
	return _stack.top();
}
