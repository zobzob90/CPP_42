/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:56:17 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/12 18:05:52 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void TestBasic()
{
	std::cout << "\n ====== BASIC TEST ====== " << std::endl;
	try
	{
		Bureaucrat John("John", 1);
		
		ShrubberyCreationForm Tree("ShrubberyForm");
		Robotomy Robot("RobotomyForm");
		PresidentialPardonForm Presidential("PresidentialForm");
		
		std::cout << std::endl;
		
		std::cout << "=== SIGNING FORM PART ===" << std::endl;
		John.signForm(Tree);
		John.signForm(Robot);
		John.signForm(Presidential);
		
		std::cout << std::endl;

		std::cout << "=== EXECUTING FORM ===" << std::endl;
		John.executeForm(Tree);
		std::cout << std::endl;
		John.executeForm(Robot);
		std::cout << std::endl;
		John.executeForm(Presidential);
		std::cout << std::endl;
		
		std::cout << "All Good !" << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception :" << e.what() << '\n';
	}
}

void	testGradeRestriction()
{
	std::cout << "\n ====== GRADE RESTRICTION ====== " << std::endl;

	try
	{
		Bureaucrat Gerard ("Gerard", 150);
		Bureaucrat Robert ("Robert", 50);
		Bureaucrat Norbert ("Norbert", 20);

		ShrubberyCreationForm Tree ("ShrubberyForm");
		Robotomy Robot ("RobotomyRequestForm");
		PresidentialPardonForm President ("PresidentialPardonForm");

		std::cout << std::endl;
		
		std::cout << "=== SIGNING FORM PART ===" << std::endl;
		std::cout << std::endl;
		std::cout << "GERARD SIGNING PART" << std::endl;
		Gerard.signForm(Tree);
		Gerard.signForm(Robot);
		Gerard.signForm(President);
		std::cout << std::endl;
		std::cout << "ROBERT SIGNING PART" << std::endl;
		Robert.signForm(Tree);
		Robert.signForm(Robot);
		Robert.signForm(President);
		std::cout << std::endl;
		std::cout << "NORBERT SIGNING PART" << std::endl;
		Norbert.signForm(Tree);
		Norbert.signForm(Robot);
		Norbert.signForm(President);

		std::cout << std::endl;

		std::cout << "=== EXECUTING FORM ===" << std::endl;
		std::cout << std::endl;
		
		std::cout << "GERARD EXECUTE PART" << std::endl;
		Gerard.executeForm(Tree);
		Gerard.executeForm(Robot);
		Gerard.executeForm(President);
		std::cout << std::endl;
		std::cout << "ROBERT EXECUTE PART" << std::endl;
		Robert.executeForm(Tree);
		Robert.executeForm(Robot);
		Robert.executeForm(President);
		std::cout << std::endl;
		std::cout << "NORBERT EXECUTE PART" << std::endl;
		Norbert.executeForm(Tree);
		Norbert.executeForm(Robot);
		Norbert.executeForm(President);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception :" << e.what() << '\n';
	}
}


void testInternBasic()
{
    std::cout << "\n========== INTERN BASIC TESTS ==========" << std::endl;
    
    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        
        std::cout << "\n--- Creating forms via Intern ---" << std::endl;
        
        // Test création de chaque type de formulaire
        AForm* shrub = intern.makeForm("shrubbery creation", "garden");
        AForm* robot = intern.makeForm("robotomy request", "Bender");
        AForm* pardon = intern.makeForm("presidential pardon", "Ford");
        
        std::cout << "\n--- Testing created forms ---" << std::endl;
        if (shrub) {
            std::cout << *shrub << std::endl;
            boss.signForm(*shrub);
            boss.executeForm(*shrub);
            delete shrub;
        }
        
        if (robot) {
            std::cout << *robot << std::endl;
            boss.signForm(*robot);
            boss.executeForm(*robot);
            delete robot;
        }
        
        if (pardon) {
            std::cout << *pardon << std::endl;
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
            delete pardon;
        }
        
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int	main(void)
{

	// TestBasic();
	// testGradeRestriction();
	testInternBasic();
	return (0);
}
