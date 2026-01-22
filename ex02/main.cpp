/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:35:13 by jow               #+#    #+#             */
/*   Updated: 2025/10/28 17:35:14 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>

int main(void)
{
	// Test 1
	try
	{
		Bureaucrat joe("Joe", 1);

		AForm* form = new ShrubberyCreationForm("Joe's home");
		joe.signForm(*form);
		joe.executeForm(*form);
		std::cout << std::endl;


		AForm* form2 = new RobotomyRequestForm("Robot");
		joe.signForm(*form2);
		joe.executeForm(*form2);
		std::cout << std::endl;

		AForm* form3 = new PresidentialPardonForm("President");
		joe.signForm(*form3);
		joe.executeForm(*form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	// Test 2
	std::cout << "---------------------" << std::endl;
	try
	{
		Bureaucrat randy("Randy", 150);

		AForm* form4 = new ShrubberyCreationForm("Randy's home");
		randy.signForm(*form4);
		randy.executeForm(*form4);
		std::cout << std::endl;


		AForm* form5 = new RobotomyRequestForm("Robot");
		randy.signForm(*form5);
		randy.executeForm(*form5);
		std::cout << std::endl;

		AForm* form6 = new PresidentialPardonForm("President");
		randy.signForm(*form6);
		randy.executeForm(*form6);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	// Test 3
	std::cout << "---------------------" << std::endl;
	try
	{
		Bureaucrat james("James", 70);

		AForm* form7 = new ShrubberyCreationForm("James's home");
		james.signForm(*form7);
		james.executeForm(*form7);
		std::cout << std::endl;


		AForm* form8 = new RobotomyRequestForm("Robot");
		james.signForm(*form8);
		james.executeForm(*form8);
		std::cout << std::endl;

		AForm* form9 = new PresidentialPardonForm("President");
		james.signForm(*form9);
		james.executeForm(*form9);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
}
