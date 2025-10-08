/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:40 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/08 15:42:31 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<size_t> Pmerge::generateJacobsthalSequence(size_t n) const
{
	
}

void	Pmerge::sortVector(std::vector<int>& vector)
{
	mergeSort(vector);
}

void	Pmerge::sortDeque(std::deque<int>& deque)
{
	mergeSort(deque);
}

