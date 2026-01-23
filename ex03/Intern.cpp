/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:19:24 by jow               #+#    #+#             */
/*   Updated: 2026/01/23 14:19:25 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	(void) other;
}

Intern& Intern::operator=(const Intern &other)
{
	(void) other;
    return (*this);
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	int i;
	AForm *form;
	std::string forms_list[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	i = 0;
	form = NULL;
	while (i < 3 && name != forms_list[i])
		i++;
	switch(i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			break;
	}
	if (form)
		std::cout << "Intern creates " << forms_list[i] << std::endl;
	else
		std::cerr << "Form name [" << name << "] doesn't exist" << std::endl;
	return (form);
}
