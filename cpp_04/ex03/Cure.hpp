/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:13:40 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/10 10:44:04 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& src);
		Cure &operator=(const Cure& src);
		virtual ~Cure();

		virtual AMateria* clone() const;        // Crée une nouvelle instance de Cure
		virtual void use(ICharacter& target);   // Soigne les blessures de la cible
} ;

#endif