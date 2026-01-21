/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:14:57 by jow               #+#    #+#             */
/*   Updated: 2025/11/13 21:14:58 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonFormform", 25, 5), _target("Default") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : _target(other._target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("RobotomyRequestForm", 25, 5), _target(target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
	{
		std::cout << "Form is not signed" << std::endl;
		return;
	}
	if (executor.getGrade() > this->getExeGrade())
		throw GradeTooHighException();
	std::cout << "This form is executed by " << executor.getName() << std::endl;
}
