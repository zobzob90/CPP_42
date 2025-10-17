/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:47:43 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/17 10:59:47 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template<typename T>
void Pmerge::binaryInsert(T& mainChain, typename T::value_type value)
{
    // Compter les comparaisons dans la recherche binaire
	size_t left = 0, right = mainChain.size();
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		comparisons++;
		if (mainChain[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	mainChain.insert(mainChain.begin() + left, value);
}

template<typename T>
void Pmerge::binaryInsertMaxPos(T& mainChain, typename T::value_type value, size_t maxPos)
{
    // Recherche binaire limitée jusqu'à maxPos (position du winner correspondant)
    size_t left = 0, right = maxPos;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        comparisons++;
        if (mainChain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    mainChain.insert(mainChain.begin() + left, value);
}

template<typename T>
void	Pmerge::mergeSort(T& container)
{
	if (container.size() <= 1) // deja trie
		return;
			
	//1. Diviser le container en deux partie

	// creer un vector avec std::pair qui comprend deux valeurs qu'on appelle ensuite pairs
	std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;
	bool hasOdd = container.size() % 2 == 1;
	typename T::value_type oddElement;

	if (hasOdd)
		oddElement = container.back();
		
	size_t pairCount;
	if (hasOdd)
		pairCount = container.size() - 1;
	else
		pairCount = container.size();

	// Ici je cree les pairs pour le trie gagnant / perdant 
	for (size_t i = 0; i < pairCount; i+= 2)
	{
		comparisons++;
		if (container[i] > container[i + 1])
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
		else
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
	}
	
	//2. Appeler mergeSort sur les gagnants
	T winners;
	
	for(size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].first);
	mergeSort(winners); //  appel recursif de merge Sort sur les gagnants
	
	//3. Fusionner les deux sous-parties tries
	container.clear();
	for (size_t i = 0; i < winners.size(); ++i)
		container.push_back(winners[i]);
	
	std::vector<typename T::value_type> losers;
	for (size_t i = 0; i < pairs.size(); ++i)
		losers.push_back(pairs[i].second);
	
	//4. Appel de JacobSthal pour avoir l'ordre d'insertion optimal 
	// Pour chaque loser, on utilise la position de son winner comme limite
	std::vector<size_t> jacob = generateJacobsthalSequence(losers.size());
	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t loserIdx = jacob[i];
		// Trouver la position du winner correspondant dans le container
		size_t winnerPos = 0;
		for (size_t j = 0; j < container.size(); ++j)
		{
			if (container[j] == pairs[loserIdx].first)
			{
				winnerPos = j + 1; // Position après le winner
				break;
			}
		}
		binaryInsertMaxPos(container, losers[loserIdx], winnerPos);
	}
	//5. Si la liste est une liste impair j'utilise la dichotomie pour inserer le dernier dans le bon ordre
	if (hasOdd)
		binaryInsert(container, oddElement);
}

#endif