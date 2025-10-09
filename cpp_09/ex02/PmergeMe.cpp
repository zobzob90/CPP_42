/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:40 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/09 14:13:29 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<size_t> Pmerge::generateJacobsthalSequence(size_t n) const
{
	std::vector<size_t> jacob;
	
	if (n == 0)
		return (jacob);
	
	std::vector<size_t> jacobNum;
	jacobNum.push_back(0);
	jacobNum.push_back(1);

	while (jacobNum.back() < n)
	{
		size_t next = jacobNum[jacobNum.size() - 1] + 2 * jacobNum[jacobNum.size() - 2];
		jacobNum.push_back(next);
	}
	std::vector<bool> used(n, false);

	for (size_t i = 2; i < jacobNum.size() && jacobNum[i] <= n; i++)
	{
		for (size_t j = jacobNum[i] - 1; j > jacobNum[i - 1] && j < n; --j)
		{
			if (used[i])
			{
				jacob.push_back(j);
				used[j] = true;
			}
			if (j == 0)
				break;
		}
	}
	
	for (size_t i = 0; i < n; i++)
	{
		if (!used[i])
			jacob.push_back(i);
	}
	return jacob;
}

void	Pmerge::sortVector(std::vector<int>& vector)
{
	mergeSort(vector);
}

void	Pmerge::sortDeque(std::deque<int>& deque)
{
	mergeSort(deque);
}

