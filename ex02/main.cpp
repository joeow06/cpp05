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
	try
	{
		AForm* form = new ShrubberyCreationForm("Randy");
		std::cout << form->getName() << std::endl;
		Bureaucrat joe("Joe", 1);
		joe.signForm(*form);
		joe.executeForm(*form);

		AForm* form2 = new RobotomyRequestForm();
		joe.signForm(*form2);
		joe.executeForm(*form2);

		AForm* form3 = new PresidentialPardonForm();
		joe.signForm(*form3);
		joe.executeForm(*form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
}
