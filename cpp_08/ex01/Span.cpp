/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:38:07 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/02 13:38:17 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers for finding a span");
	std::vector<int> temp_copy = _numbers;
	std::sort(temp_copy.begin(), temp_copy.end());
	int minSpan = temp_copy[1] - temp_copy[0];
	for (size_t i = 1; i < temp_copy.size(); i++)
	{
		int diff = temp_copy[i] - temp_copy[i - 1];
			if (diff < minSpan)
				minSpan = diff;
	}
	return (minSpan);	
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers for finding a span");
	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
	return (maxVal - minVal);
}

std::ostream& operator<<(std::ostream& out, const Span& src)
{
	out << "[ ";
	for (size_t i = 0; i < src.getNumbers().size(); i++)
	{
		out << src.getNumbers()[i];
		if (i < src.getNumbers().size() - 1)
			out << ", ";
	}
	out << " ]";
	return (out);
}