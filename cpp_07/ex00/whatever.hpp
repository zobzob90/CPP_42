/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:10:11 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/10 11:41:23 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const& min(T const& a, T const &b)
{
	if (a == b)
		return (a);
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T const& max(T const&a, T const &b)
{
	if (a == b)
		return (a);
	if (a > b)
		return (a);
	else
		return (b);
}

// Class pour les types complexe utile pour le main
class Test
{
	public :
	int x, y;
	Test(int x =0, int y = 0) : x(x), y(y) {}
	
	bool operator<(const Test& src) const
	{
		return (x + y) < (src.x + src.y);
	}

	bool operator>(const Test& src) const
	{
		return (x + y) > (src.x + src.y);
	}

	bool operator==(const Test& src) const
	{
		return x == src.x && y == src.y;
	}
} ;

std::ostream& operator<<(std::ostream& os, const Test& p)
{
	return os << "(" << p.x << "," << p.y << ")";
}

#endif