/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:55:42 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/11 17:50:58 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_nameAForm;
		bool				_isSigned;
		const int			_gradeToSigned;
		const int			_gradeToExecute;
	
	public:
		AForm();
		AForm(const std::string& name, int gradeToSigned, int gradeToExecute);
		AForm(const AForm& src);
		AForm &operator=(const AForm& src);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSigned() const;
		int					GetGradeToExecute() const;

		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const& executor);
	
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
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif