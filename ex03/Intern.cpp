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

static AForm* createShrubbery(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

static AForm* createRobotomy(const std::string& target) {
    return (new RobotomyRequestForm(target));
}

static AForm* createPresidential(const std::string& target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	int i;
	AForm *form;
	std::string forms_list[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	//function pointer array
	typedef AForm* (*createForms) (const std::string&);
	createForms createList [3] = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	i = 0;
	form = NULL;
	while (i < 3 && name != forms_list[i])
		i++;
	if (i < 3)
	{
		form = createList[i](target);
		std::cout << "Intern creates " << forms_list[i] << std::endl;
	}
	else
		std::cerr << "Form name [" << name << "] doesn't exist" << std::endl;
	return (form);
}
