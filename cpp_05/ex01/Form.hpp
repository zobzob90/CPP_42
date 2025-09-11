/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:48:47 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/11 15:27:02 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_nameForm;
		bool				_isSigned;
		const int			_gradeToSigned;
		const int			_gradeToExecute;
	
	public:
		Form();
		Form(const std::string& name, int gradeToSigned, int gradeToExecute);
		Form(const Form& src);
		Form &operator=(const Form& src);
		~Form();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSigned() const;
		int					GetGradeToExecute() const;

		void				beSigned(const Bureaucrat& bureaucrat);
		
		// Exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
} ;

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif