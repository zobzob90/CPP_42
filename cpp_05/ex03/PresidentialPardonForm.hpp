/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:56:03 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/12 13:59:08 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PresidentialPardonForm : public AForm
{
	private: 
		std::string _target;
	protected:
		virtual void	executeAction() const;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		virtual ~PresidentialPardonForm();

		const std::string& getTarget() const;
} ;

#endif
