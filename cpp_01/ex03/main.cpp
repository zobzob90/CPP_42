/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:33:40 by ertrigna          #+#    #+#             */
/*   Updated: 2025/08/12 12:52:26 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	club = Weapon("kitchen knife 🔪");
		
		HumanA bob("Bob", club);
		bob.Attack();
		club.setType("some other knife\n");
		bob.Attack();
	}
	{
		Weapon	baseball = Weapon("baseball bate");
		
		HumanB jay("Jay");
		jay.setWeapon(baseball);
		jay.attack();
		baseball.setType("some other type of weapon");
		jay.attack();
	}
	{
		HumanB jay_brother("Jay's Brother Bill");
		jay_brother.attack();
	}
	return (0);
}
