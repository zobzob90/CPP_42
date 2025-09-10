/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:00:00 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/10 10:43:51 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}                                    // Destructeur virtuel pour polymorphisme
    virtual void learnMateria(AMateria*) = 0;                      // Apprend un nouveau sort (stocke le template)
    virtual AMateria* createMateria(std::string const & type) = 0;  // Crée une copie du sort demandé
};

#endif