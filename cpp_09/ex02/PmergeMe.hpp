/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:43 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/08 15:49:05 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector> // for container vector
#include <deque> // for container deque
#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>

class Pmerge
{
	private:
	
		template<typename T>
		void	mergeSort(T& container)
		{
			if (container.size() <= 1) // deja trie
				return;
			
			//1. Diviser le container en deux partie
			
			//2. Appeler mergeSort sur chaque sous-partie

			//3. Fusionner les deux sous-parties tries
		
		}

		template<typename T>
		void	binaryInsert(T& mainChain, typename T::value_type value);

		std::vector<size_t>	generateJacobsthalSequence(size_t n) const;

	public:
		Pmerge() {}
		Pmerge(const Pmerge& src) 
		{
			*this = src;
		}
		Pmerge& operator=(const Pmerge& src) 
		{
			(void)src;
			return (*this);
		}
		~Pmerge() {}
		
		void	sortVector(std::vector<int>& Vector);
		void	sortDeque(std::deque<int>& Deque);
} ;

#endif