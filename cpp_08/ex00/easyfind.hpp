/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:58:19 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/15 16:48:13 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector> // pour definir un container de int
#include <algorithm> // pour utiliser find
 
template <typename T>
typename T::const_iterator	easyFind(const T& container, int value)
{
	typename T::const_iterator iterator;

	iterator = std::find(container.begin(), container.end(), value);
	if (iterator == container.end()) // si l'iteration arrive a la fin du container sans rien trouver on lance l'exception
		throw std::runtime_error("Value not find in the container");
	return (iterator); 
}

// le retour est un typnemame T qui sera un iterateur constant vers un element du container;
// la fonction prend une reference de T nomme container et la valeur de l'int pour l'element recherche
// la fonction find sert a chercher la valeur dans le container en la parcourant du debut a la fin

#endif