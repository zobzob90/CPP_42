/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:10:11 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/19 16:30:49 by ertrigna         ###   ########.fr       */
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

#endif