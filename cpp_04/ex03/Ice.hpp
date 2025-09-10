/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:38:16 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/10 10:44:04 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& src);
		Ice &operator=(const Ice& src);
		virtual ~Ice();

		virtual AMateria* clone() const;        // Crée une nouvelle instance d'Ice
		virtual void use(ICharacter& target);   // Lance un projectile de glace sur la cible
} ;

#endif