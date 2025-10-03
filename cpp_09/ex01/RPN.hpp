/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:07:11 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/03 20:22:11 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream> // pour iss

class RPN
{
	private:
		std::stack<int> _stack;
		bool	isOp(char c) const;
		int		applyOp(char op, int a, int b) const;

 	public:
		RPN() {}
		RPN(const RPN& src) : _stack(src._stack) {}
		RPN& operator=(const RPN& src) {
			if (this != &src)
				_stack = src._stack;
			return (*this);
		}
		~RPN () {}
	
	int		calculate(const std::string& args);
} ;

#endif