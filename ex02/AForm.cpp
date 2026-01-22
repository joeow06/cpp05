/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:02:56 by jow               #+#    #+#             */
/*   Updated: 2025/10/31 00:02:57 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _signGrade(150), _exeGrade(150) {}

AForm::~AForm()
{
	// std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other.getName()), _signed(other.getSigned()),
								   _signGrade(other.getSignGrade()), _exeGrade(other.getExeGrade()) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

AForm::AForm(std::string name, int signGrade, int exeGrade) : _name(name),
															  _signGrade(signGrade), _exeGrade(exeGrade)
{
	if (_signGrade < 1 || _exeGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _exeGrade > 150)
		throw GradeTooLowException();
}

const std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExeGrade() const
{
	return (_exeGrade);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->setSigned(true);
	else
		throw GradeTooLowException();
}

void AForm::setSigned(bool value)
{
	_signed = value;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("form is not signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &a)
{
	std::string status;

	status = "Not signed";
	if (a.getSigned())
		status = "Signed";
	out << "Name: " << a.getName() << " | Status: " << status << " | Sign Grade: " << a.getSignGrade() << " | Execute Grade: " << a.getExeGrade() << std::endl;
	return out;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExeGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw FormNotSigned();
	this->doExecute();
}
