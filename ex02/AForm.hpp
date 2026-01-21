/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:02:58 by jow               #+#    #+#             */
/*   Updated: 2025/10/31 00:02:59 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _exeGrade;

protected:
	virtual void doExecute(Bureaucrat const & executor) const = 0;

public:
	AForm();
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	AForm(std::string name, int signGrade, int exeGrade);

	void execute(Bureaucrat const & executor) const;

	const std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExeGrade() const;
	void beSigned(Bureaucrat &value);
	void setSigned(bool value);
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &a);

#endif
