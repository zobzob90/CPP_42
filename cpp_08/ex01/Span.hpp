/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:52:55 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/01 17:44:03 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

class Span
{
	private :
		unsigned int _N; // represente sa capacite max
		std::vector<int> _numbers; // stock les nombres
	public :
		Span(unsigned int N) : _N(N), _numbers() {}
		Span(const Span& src) : _N(src._N), _numbers(src._numbers) {}
		Span& operator=(const Span& src)
		{
			if (this != &src)
			{
				_N = src._N;
				_numbers = src._numbers;
			}
			return *this;
		}
		~Span() {}
		
		//ajoute un seul nombre
		void addNumber(int n)
		{
			if (_numbers.size() >= _N)
				throw std::out_of_range("Span is already full");
			_numbers.push_back(n);
		}

		// ajoute une plage de nombre via un template
		template<typename inputIterator>
		void addNumber(inputIterator begin, inputIterator end)
		{
			if (_numbers.size() + std::distance(begin -end) > _N)
				throw std::out_of_range("Not enough space to add");
			_numbers.insert(_numbers.end(), begin, end);
		}
		
		int shortestSpan() const;
		int longestSpan() const;
} ;

#endif