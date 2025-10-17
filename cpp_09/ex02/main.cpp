/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:38 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/17 11:24:20 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <set>

bool isNumber(const std::string& str)
{
	if (str.empty())
		return (false);
	if (str[0] == '-')
	{
		std::cerr << "Error : Cannot accept negative number" << std::endl;
		return (false);	
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	printPairs(const std::vector<int>& container)
{
    if (container.size() <= 1)
        return;
        
    std::cout << "\n=== PAIRS (winner, loser) ===" << std::endl;
    
    bool hasOdd = container.size() % 2 == 1;
    size_t pairCount = hasOdd ? container.size() - 1 : container.size();
    
    for (size_t i = 0; i < pairCount; i += 2)
    {
        int winner, loser;
        if (container[i] > container[i + 1])
        {
            winner = container[i];
            loser = container[i + 1];
        }
        else
        {
            winner = container[i + 1];
            loser = container[i];
        }
        
        std::cout << "pairs[" << i/2 << "] = (" << winner << ", " << loser << ")";
        std::cout << "   ← winner=" << winner << ", loser=" << loser << std::endl;
    }
    
    if (hasOdd)
        std::cout << "Odd element: " << container.back() << std::endl;
}

void	printLosers(const std::vector<int>& container)
{
	if (container.size() <= 1)
		return;
        
	std::cout << "\n=== LOSERS ===" << std::endl;
	std::cout << "[ ";
    
	bool hasOdd = container.size() % 2 == 1;
	size_t pairCount = hasOdd ? container.size() - 1 : container.size();
    
	int loserIdx = 0;
	for (size_t i = 0; i < pairCount; i += 2)
	{
		int loser;
		if (container[i] > container[i + 1])
            loser = container[i + 1];
        else
            loser = container[i];
        
        std::cout << "losers[" << loserIdx << "]=" << loser;
        if (i + 2 < pairCount)
            std::cout << ", ";
        loserIdx++;
    }
    
    std::cout << " ]" << std::endl;
}

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "Error : Cannot accept 1 Arguments" << std::endl;
		return (1);
	}

	if (ac - 1 > 3000)
	{
		std::cerr << "Error : Too many elements in your list !" << std::endl;
		return (1);
	}
	std::vector<int>	vector;
	std::deque<int>		deque;
	std::set<int>		seen;
	for (int i = 1; i < ac; i++)
	{
		if (!isNumber(av[i]) || atoi(av[i]) < 0)
		{
			std::cerr << "Error: invalid argument : " << av[i] << std::endl;
			return (1);
		}
		if (!seen.insert(atoi(av[i])).second) // gere les doublons
		{
			std::cerr << "Error: duplicate number : " << av[i] << std::endl;
			return (1);
		}
		vector.push_back(atoi(av[i]));
		deque.push_back(atoi(av[i]));
	}
	Pmerge p;

	std::cout << "Before : ";
	for (size_t i = 0; i < vector.size(); ++i)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	
	printPairs(vector);
	printLosers(vector);

	std::cout << std::endl;
	
	// Afficher la séquence de Jacobsthal
	p.printJacobsthalSequence(vector.size());
	p.printJacobsthalWithValues(vector);

	std::cout << std::endl;

	// trie avec Vector;
	p.resetComparisons();
	clock_t start = clock();
	p.sortVector(vector);
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	size_t vectorComparisons = p.getComparisons();

	// trie avec Deque
	p.resetComparisons();
	start = clock();
	p.sortDeque(deque);
	end = clock();
	double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	size_t dequeComparisons = p.getComparisons();

	// Afficher les sequences apres trie
	std::cout << "After : ";
	for (size_t i = 0; i < vector.size(); ++i)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	
	std::cout << std::endl;
	
	// Afficher le temps
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << vectorTime << " us " << vectorComparisons << " comparisons" << std::endl;
	std::cout << "Time to process a range of " << vector.size() << " elements with std::deque : " << dequeTime << " us " << dequeComparisons << " comparisons" << std::endl;

	// return (0);
}