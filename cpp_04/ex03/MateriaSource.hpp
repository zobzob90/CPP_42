/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:37:54 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/08 13:38:36 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _templates[4]; //stock les templates de materia
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource &operator=(const MateriaSource& src);
		virtual ~MateriaSource();
		
		virtual void learnMateria(AMateria *m);
		virtual AMateria*	createMateria(std::string const &type);
} ;

#endif