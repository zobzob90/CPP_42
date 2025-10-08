/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:47:43 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/08 16:59:29 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

template<typename T>
void	binaryInsert(T& mainChain, typename T::value_type value)
{
	typename T::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(pos, value);
}

template<typename T>
void	mergeSort(T& container)
{
	if (container.size() <= 1) // deja trie
		return;
			
	//1. Diviser le container en deux partie

	// creer un vector avec std::pair qui comprend deux valeurs qu'on appelle ensuite pairs
	std::vector<std::pair<typename T::value_type, typename T::value_type>> pairs;
	bool hasOdd = container.size() % 2 == 1;
	typename T::value_type oddElement;

	if (hasOdd)
		oddElement = container.back();
		
	size_t pairCount; // pour eviter des ternaires dans le if
	if (hasOdd)
		pairCount = container.size() - 1;
	else
		pairCount = container.size();

	// Ici je cree les pairs pour le trie gagnant / perdant 
	for (size_t i = 0; i < pairCount; i+= 2)
	{
		if (container[i] > container[i + 1])
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
		else
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
	}
	
	//2. Appeler mergeSort sur chaque sous-partie
	
	//3. Fusionner les deux sous-parties tries
		
}

#endif