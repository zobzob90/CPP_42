/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:33 by ertrigna          #+#    #+#             */
/*   Updated: 2025/09/23 10:03:59 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void printTestHeader(const std::string& testName, int testNumber)
{
	std::cout << "\n========== TEST " << testNumber << ": " << testName << " ==========" << std::endl;
}

void printResult(bool passed, const std::string& testName)
{
	if (passed)
        std::cout << "✅ " << testName << " PASSED" << std::endl;
	else
        std::cout << "❌ " << testName << " FAILED" << std::endl;
}

void testValidBureaucrat()
{
    printTestHeader("Valid Bureaucrat Creation", 1);
    
    try {
        Bureaucrat norbert("Norbert", 100);
        std::cout << "Created: " << norbert << std::endl;
        
        bool nameTest = (norbert.getName() == "Norbert");
        bool gradeTest = (norbert.getGrade() == 100);
        
        printResult(nameTest && gradeTest, "Valid bureaucrat creation");
        
    } catch (const std::exception& e) {
        std::cout << "❌ Unexpected exception: " << e.what() << std::endl;
    }
}

void testInvalidGradeTooHigh()
{
    printTestHeader("Invalid Grade Too High (0)", 2);
    
    try {
        Bureaucrat gerard("Gerard", 0);
        std::cout << "❌ Exception should have been thrown!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✅ Exception caught correctly: " << e.what() << std::endl;
    }
}

void testInvalidGradeTooLow()
{
    printTestHeader("Invalid Grade Too Low (151)", 3);
    
    try {
        Bureaucrat geraldine("Geraldine", 151);
        std::cout << "❌ Exception should have been thrown!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✅ Exception caught correctly: " << e.what() << std::endl;
    }
}

void testGradeModification()
{
    printTestHeader("Grade Increment/Decrement", 4);
    
    try {
        Bureaucrat gustave("Gustave", 50);
        std::cout << "Initial: " << gustave << std::endl;
        
        // Test increment
        gustave.incrementGrade();
        std::cout << "After increment: " << gustave << std::endl;
        printResult(gustave.getGrade() == 49, "Grade increment (50 → 49)");
        
        // Test decrement
        gustave.decrementGrade();
        std::cout << "After decrement: " << gustave << std::endl;
        printResult(gustave.getGrade() == 50, "Grade decrement (49 → 50)");
        
    } catch (const std::exception& e) {
        std::cout << "❌ Unexpected exception: " << e.what() << std::endl;
    }
}

void testExtremeGradeModification()
{
    printTestHeader("Extreme Grade Modifications", 5);
    
    // Test increment at highest grade
    try {
        Bureaucrat topBureaucrat("President", 1);
        std::cout << "Testing increment at grade 1: " << topBureaucrat << std::endl;
        topBureaucrat.incrementGrade();
        std::cout << "❌ Exception should have been thrown!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✅ Increment exception: " << e.what() << std::endl;
    }
    
    // Test decrement at lowest grade
    try {
        Bureaucrat lowBureaucrat("Intern", 150);
        std::cout << "Testing decrement at grade 150: " << lowBureaucrat << std::endl;
        lowBureaucrat.decrementGrade();
        std::cout << "❌ Exception should have been thrown!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✅ Decrement exception: " << e.what() << std::endl;
    }
}

void testCopyConstructorAndAssignment()
{
    printTestHeader("Copy Constructor & Assignment", 6);
    
    try {
        Bureaucrat original("Original", 75);
        std::cout << "Original: " << original << std::endl;
        
        // Test copy constructor
        Bureaucrat copy(original);
        std::cout << "Copy: " << copy << std::endl;
        printResult(copy.getName() == original.getName() && 
                    copy.getGrade() == original.getGrade(), 
                    "Copy constructor");
        
        // Test assignment operator
        Bureaucrat assigned("TempName", 1);
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
        printResult(assigned.getName() == original.getName() && 
                    assigned.getGrade() == original.getGrade(), 
                    "Assignment operator");
        
    } catch (const std::exception& e) {
        std::cout << "❌ Unexpected exception: " << e.what() << std::endl;
    }
}

int main(void)
{
    std::cout << "🏛️  BUREAUCRAT TESTING SUITE 🏛️" << std::endl;
    std::cout << "=================================" << std::endl;
    
    testValidBureaucrat();
    testInvalidGradeTooHigh();
    testInvalidGradeTooLow();
    testGradeModification();
    testExtremeGradeModification();
    testCopyConstructorAndAssignment();
    
    std::cout << "\n🎉 ALL TESTS COMPLETED! 🎉" << std::endl;
    std::cout << "=========================" << std::endl;
    
    return 0;
}
