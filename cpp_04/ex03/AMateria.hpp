/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:08:52 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/04 13:22:26 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		//constructeur et destructeur
		AMateria(const std::string& type);
		AMateria(const AMateria& src);
		AMateria& operator=(const AMateria& src);
		virtual ~AMateria();

		// Getter
		std::string const& getType() const;

		// Methode Virtuel
		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);
} ;

#endif