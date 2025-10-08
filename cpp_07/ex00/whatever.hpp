/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:10:11 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/08 13:16:17 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>

// fonction generique swap qui marche avec un int, char ou autres, pas besoin d'une classe pour cet exo
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