/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:40 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/17 11:23:55 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<size_t> Pmerge::generateJacobsthalSequence(size_t n) const
{
	std::vector<size_t> jacob;
	
	if (n == 0)
		return (jacob);
	
	// Générer les nombres de Jacobsthal: 0, 1, 1, 3, 5, 11, 21, 43, 85...
	std::vector<size_t> jacobNum;
	jacobNum.push_back(0); // J(0)
	jacobNum.push_back(1); // J(1)

	while (jacobNum.back() < n * 2) 
	{
		size_t next = jacobNum[jacobNum.size() - 1] + 2 * jacobNum[jacobNum.size() - 2];
		jacobNum.push_back(next);
	}
	
	std::vector<bool> used(n, false);

	// Insérer le premier élément (index 0)
	jacob.push_back(0);
	used[0] = true;
	
	// Insérer l'élément à l'index 1 (J₁)
	if (n > 1)
	{
		jacob.push_back(1);
		used[1] = true;
	}
	
	// Générer l'ordre d'insertion optimal Ford-Johnson
	// Pour chaque J(k) >= 3: insérer de J(k) vers J(k-1)+1 en décroissant
	for (size_t i = 3; i < jacobNum.size(); i++)
	{
		size_t currentJacob = jacobNum[i];
		size_t prevJacob = jacobNum[i - 1];
		
		// Insérer de min(currentJacob, n-1) vers prevJacob+1 en décroissant
		size_t start = (currentJacob < n) ? currentJacob : n - 1;
		
		for (size_t j = start; j > prevJacob && j < n; --j)
		{
			if (!used[j])
			{
				jacob.push_back(j);
				used[j] = true;
			}
		}
	}
	
	// Ajouter les éléments restants
	for (size_t i = 0; i < n; i++)
	{
		if (!used[i])
			jacob.push_back(i);
	}
	
	return (jacob);
}

void	Pmerge::sortVector(std::vector<int>& vector)
{
	mergeSort(vector);
}

void	Pmerge::sortDeque(std::deque<int>& deque)
{
	mergeSort(deque);
}

void	Pmerge::printJacobsthalSequence(size_t n) const
{
	std::vector<size_t> jacob = generateJacobsthalSequence(n);
	
	std::cout << "Jacobsthal insertion order for " << n << " elements:" << std::endl;
	std::cout << "[ ";
	for (size_t i = 0; i < jacob.size(); i++)
	{
		std::cout << jacob[i];
		if (i < jacob.size() - 1)
			std::cout << ", ";
	}
	std::cout << " ]" << std::endl;
}

void Pmerge::printJacobsthalWithValues(const std::vector<int>& container) const
{
    if (container.size() <= 1)
        return;

    bool hasOdd = container.size() % 2 == 1;
    size_t pairCount = hasOdd ? container.size() - 1 : container.size();

    std::vector<int> losers;
    for (size_t i = 0; i < pairCount; i += 2)
    {
        if (container[i] > container[i + 1])
            losers.push_back(container[i + 1]);
        else
            losers.push_back(container[i]);
    }

    std::vector<size_t> jacob = generateJacobsthalSequence(losers.size());
    
    std::cout << "\n=== JACOBSTHAL INSERTION ORDER (with losers) ===" << std::endl;
    std::cout << "Total losers: " << losers.size() << std::endl;
    std::cout << "\nInsertion order:" << std::endl;
    
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t loserIdx = jacob[i];
        std::cout << "  Step " << (i+1) << ": "
                  << "insert losers[" << loserIdx << "] = " 
                  << losers[loserIdx] << std::endl;
    }
    
    if (hasOdd)
        std::cout << "  Final step: insert odd element = " << container.back() << std::endl;
    
    std::cout << std::endl;
}