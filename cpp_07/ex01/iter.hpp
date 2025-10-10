/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:46:13 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/10 15:51:42 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename F>
void	iter(T *array, int length, F func)
{
	if (length <= 0 || array == NULL)
		return ;
	for (int i = 0; i < length; i++)
		func(array[i]);
}

#endif