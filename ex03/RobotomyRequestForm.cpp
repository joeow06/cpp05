/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:14:55 by jow               #+#    #+#             */
/*   Updated: 2025/11/13 21:14:56 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestform", 72, 45), _target("Default") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : _target(other._target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

void RobotomyRequestForm::doExecute() const
{
	int num;

	srand(time(NULL));
	num = rand() % 2;
	std::cout << "Zzzzzzzzt.....Zzzzzzzzt" << std::endl;
	if (num == 1)
		std::cout << this->_target << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed..." << std::endl;
}
