/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:46:13 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/19 17:46:52 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T>
void	iter(T *array, int lenght, void(*f) (T const &))
{
	if (lenght <= 0 || array == NULL)
		return ;
	for (int i = 0; i < lenght; i++)
		f(array[i]);
}

#endif