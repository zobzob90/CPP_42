/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:01:29 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 14:02:16 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
#define FIRE_HPP

#include <iostream>
#include "AMateria.hpp"

class Fire : public AMateria
{
	public:
		Fire();
		Fire(const Fire& src);
		Fire &operator=(const Fire& src);
		virtual ~Fire();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
} ;

#endif