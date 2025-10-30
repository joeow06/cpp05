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

Form::Form() : _name("Default"), _signed(false), _signGrade(0), _exeGrade(0) {}

Form::~Form() {}

Form::Form(const Form &other) : _name(other.getName()), _signed(other.getSigned()),
	_signGrade(other.getSignGrade()), _exeGrade(other.getSignGrade()) {}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

const std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

const int Form::getSignGrade() const
{
	return (_signGrade);
}

const int Form::getExeGrade() const
{
	return (_exeGrade);
}

void Form::beSigned(Bureaucrat &value)
{
	if (value.getGrade() <= this->getSignGrade())
		this->setSigned(true);
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
