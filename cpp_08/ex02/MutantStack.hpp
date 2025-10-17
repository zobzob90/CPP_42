/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:13:14 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/16 15:24:50 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack> // contient le "container" stack 
#include <deque> // "double-ended queue" est une file doublement chainee sert de container interne pour stocker les elements
#include <iostream>
#include <string>
// Mutant herite de std::stack
// std::stack utilise un container interne  std::deque pour iterer sur sa stack
// donc pile normale mais iterable


template<typename T, typename container = std::deque<T> > // T pour le type d'elements, et l'autre pour stocker physiquement en utilisant deque
class MutantStack : public std::stack<T, container>
{
	public :
		MutantStack() : std::stack<T, container> () {}
		MutantStack(const MutantStack &src) : std::stack<T, container>(src) {}
		MutantStack& operator=(const MutantStack& src)
		{
			std::stack<T, container>::operator=(src);
			return *this;
		} 
		~MutantStack() {}

		// je defini un typename pour dire au compilateur que celle ci est un type non une variabe 
		typedef typename container::iterator iterator;
		typedef typename container::const_iterator const_iterator;

		// Iterateur inverses
		typedef typename container::reverse_iterator reverse_iterator;
		typedef typename container::const_reverse_iterator const_reverse_iterator;

		//this->c.begin ou end donne un pointeur vers le premier element que je veux modifier ou lire (const_iterator)
		iterator begin() {return (this->c.begin());} // c vient de la class stack
		iterator end() {return (this->c.end());}
		const_iterator begin() const {return (this->c.begin());}
		const_iterator end() const {return (this->c.end());}

		reverse_iterator rbegin() {return (this->c.rbegin());}
		reverse_iterator rend() {return (this->c.rend());}
		const_reverse_iterator rbegin() const {return (this->c.rbegin());}
		const_reverse_iterator rend() const {return (this->c.rend());}
} ;

#endif