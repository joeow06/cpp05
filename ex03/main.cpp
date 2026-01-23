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
#include "Intern.hpp"
#include <exception>

int main(void)
{
	// AForm* test;
	// Intern joe;

	// test = joe.makeForm("PresidentialPardonForm", "LMAO");
	// (void) test;
	try
	{
		Intern internJoe;
		AForm* form1;
		AForm* form2;
		AForm* form3;
		AForm* badform;

		form1 = internJoe.makeForm("ShrubberyCreationForm", "ONE");
		form2 = internJoe.makeForm("RobotomyRequestForm", "TWO");
		form3 = internJoe.makeForm("PresidentialPardonForm", "THREE");
		badform = internJoe.makeForm("Sh", "lol");
		std::cout << std::endl;

		Bureaucrat joe("Joe", 1);

		joe.signForm(*form1);
		joe.executeForm(*form1);
		std::cout << std::endl;

		joe.signForm(*form2);
		joe.executeForm(*form2);
		std::cout << std::endl;

		joe.signForm(*form3);
		joe.executeForm(*form3);

		delete form1;
		delete form2;
		delete form3;
		delete badform;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
}

// joe.signForm(*badform) will cause segfault because you cant dereference a null pointer
