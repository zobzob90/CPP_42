/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:08:45 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/03 18:24:36 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& src);
		Character &operator=(const Character& src);
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual	void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		
} ;

#endif