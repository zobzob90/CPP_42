/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:43 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/17 11:14:42 by ertrigna         ###   ########.fr       */
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
	
		mutable size_t comparisons;
		
		template<typename T>
		void	mergeSort(T& container);
		
		template<typename T>
		void	binaryInsert(T& mainChain, typename T::value_type value);
		
		template<typename T>
		void	binaryInsertMaxPos(T& mainChain, typename T::value_type value, size_t maxPos);

		std::vector<size_t>	generateJacobsthalSequence(size_t n) const;

	public:
		Pmerge() : comparisons(0) {}
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
		
		size_t getComparisons() const {return comparisons;}
		void resetComparisons() { comparisons = 0; }

		void	sortVector(std::vector<int>& Vector);
		void	sortDeque(std::deque<int>& Deque);
		void	printJacobsthalSequence(size_t n) const;
		void	printJacobsthalWithValues(const std::vector<int>& container) const;
} ;

#include "PmergeMe.tpp"

#endif
