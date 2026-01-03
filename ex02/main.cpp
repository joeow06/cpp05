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
		AForm* form = new ShrubberyCreationForm();
		std::cout << form->getName() << std::endl;
		Bureaucrat joe("Joe", 149);
		joe.signForm(*form);
		std::cout << form->getSigned() << std::endl;
		joe.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
}
