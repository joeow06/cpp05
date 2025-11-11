/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:02:56 by jow               #+#    #+#             */
/*   Updated: 2025/10/31 00:02:57 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _signGrade(150), _exeGrade(150) {}

Form::~Form() {}

Form::Form(const Form &other) : _name(other.getName()), _signed(other.getSigned()),
	_signGrade(other.getSignGrade()), _exeGrade(other.getSignGrade()) {}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

Form::Form(std::string name, int signGrade, int exeGrade) : _name(name),
	_signGrade(signGrade), _exeGrade(exeGrade)
{
	if (_signGrade < 1 || _exeGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _exeGrade > 150)
		throw GradeTooLowException();
}

const std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExeGrade() const
{
	return (_exeGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->setSigned(true);
	else
		throw GradeTooHighException();
}

void Form::setSigned(bool value)
{
	_signed = value;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low");
}

std::ostream& operator<<(std::ostream &out, Form const &a)
{
	std::string status;

	status = "Not signed";
	if (a.getSigned())
		status = "Signed";
	out << "Name: " << a.getName() << " | Status: " << status <<
			" | Sign Grade: " << a.getSignGrade() <<
			" | Execute Grade: " << a.getExeGrade() << std::endl;
	return out;
}
