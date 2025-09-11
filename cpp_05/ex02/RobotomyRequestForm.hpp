/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:56:09 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/11 21:34:59 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Robotomy : public AForm
{
	private :
		std::string _target;
	protected :
		virtual void executeAction() const;
	public :
		Robotomy();
		Robotomy(const std::string& target);
		Robotomy(const Robotomy& src);
		Robotomy& operator=(const Robotomy& src);
		virtual ~Robotomy();

		const std::string& getTarget() const;
		
} ;

#endif