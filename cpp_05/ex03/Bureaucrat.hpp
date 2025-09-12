/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:30 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/12 13:17:09 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept> // try and catch
#include <iostream>

class AForm; // Forward declaration

class Bureaucrat
{
	private:
		const std::string  _name;
		int	_grade;
	public:
		Bureaucrat(); // Constructeur 
		Bureaucrat(const std::string& name, int grade); // Constructeur Param
		Bureaucrat(const Bureaucrat& src); // Copy
		Bureaucrat &operator=(const Bureaucrat& src); // Operateur d'assign
		~Bureaucrat(); // Destructeur

		// Getters
		const std::string& getName() const; // return _name
		int getGrade() const; // return _grade;

		// Grade modification
		void incrementGrade(); // ++ grade
		void decrementGrade(); // -- grade
		
		// Form signing
		void signForm(AForm& form);
		void executeForm(AForm const& form);

		// Constants
		static const int LOWEST_GRADE = 150;
		static const int HIGHEST_GRADE = 1;

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
};

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif