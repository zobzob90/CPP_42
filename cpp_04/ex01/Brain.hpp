/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:40:32 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/02 15:34:54 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& src);
		Brain& operator=(const Brain& src);
		std::string getIdea(int index) const; //getter
		void setIdea(int index, const std::string& idea); //setter
		~Brain();
};

#endif