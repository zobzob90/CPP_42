/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:40 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/07 17:39:11 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	Pmerge::sortVector(std::vector<int>& vector)
{
	mergeSort(vector);
}

void	Pmerge::sortDeque(std::deque<int>& deque)
{
	mergeSort(deque);
}

