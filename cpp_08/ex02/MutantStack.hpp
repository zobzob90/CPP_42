/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:13:14 by ertrigna          #+#    #+#             */
/*   Updated: 2025/10/02 16:25:00 by ertrigna         ###   ########.fr       */
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


template<typename T, typename container = std::deque<T> >
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
		
		// On utilise un using pour dire au compilateur qu'on utilise ce typename pour iterer sur la stack
		typedef typename container::iterator iterator;
		typedef typename container::const_iterator const_iterator;
		
		//this->c.begin ou end donne un pointeur vers le premier element que je veux modifier ou lire (const_iterator)
		iterator begin() {return (this->c.begin());}
		iterator end() {return (this->c.end());}
		const_iterator begin() const {return (this->c.begin());}
		const_iterator end() const {return (this->c.end());}
} ;

#endif