/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:10:04 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/19 13:13:15 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base() {};
} ;

Base 	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

class A : public Base {};
class B : public Base {};
class C : public Base {};


#endif