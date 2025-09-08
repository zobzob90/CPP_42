/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prison.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:33:31 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 14:34:26 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRISON_HPP
#define PRISON_HPP

#include <iostream>
#include "AMateria.hpp"

class Prison : public AMateria
{
	public:
		Prison();
		Prison(const Prison& src);
		Prison &operator=(const Prison& src);
		virtual ~Prison();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
} ;

#endif