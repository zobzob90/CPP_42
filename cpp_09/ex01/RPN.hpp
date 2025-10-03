/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:07:11 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/03 18:55:07 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

class RPN
{
	private:
		std::stack<int> _stack;
 	public:
		RPN() {}
		RPN(const RPN& src) {}
		RPN& operator=(const RPN& src) {}
		~RPN () {}
} ;

#endif