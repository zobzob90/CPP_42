/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:46:13 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/13 11:14:35 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename F> // T pour les variables, F pour la fonction
void	iter(T *array, int length, F function)
{
	if (length <= 0 || array == NULL)
		return ;
	for (int i = 0; i < length; i++)
		function(array[i]);
}

#endif