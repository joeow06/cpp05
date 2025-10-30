/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:02:58 by jow               #+#    #+#             */
/*   Updated: 2025/10/31 00:02:59 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _exeGrade;
	public:
		Form();
		~Form();
		Form(const Form &other);
		Form& operator=(const Form &other);

		const std::string getName() const;
		bool getSigned() const;
		const int getSignGrade() const;
		const int getExeGrade() const;
		void beSigned(Bureaucrat &value);
		void setSigned(bool value);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		} ;
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		} ;
} ;

#endif
