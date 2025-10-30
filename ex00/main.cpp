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

int main(void)
{
	std::cout << "---------- Valid tests ----------" << std::endl;
	std::cout << "---------- Constructors ----------" << std::endl;
	try
	{
		Bureaucrat joe("Joe", 1);
		std::cout << joe << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat jim("Jim", 150);
		std::cout << jim << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Copy Constructor ----------" << std::endl;
	try
	{
		Bureaucrat copy1("Copy1", 42);
		Bureaucrat copy2(copy1);
		std::cout << copy1 << std::endl;
		std::cout << copy2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Assignment Operator ----------" << std::endl;
	try
	{
		Bureaucrat copy1("Copy1", 42);
		Bureaucrat copy2;
		copy2 = copy1;
		std::cout << copy1 << std::endl;
		std::cout << copy2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat copy1("Copy1", 42);
		Bureaucrat copy2("Copy2", 1);
		std::cout << "Before: " << copy1 << std::endl;
		std::cout << "Before: " << copy2 << std::endl;
		copy2 = copy1;
		std::cout << "After: " << copy1 << std::endl;
		std::cout << "After: " << copy2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------- Invalid tests ----------" << std::endl;
	try
	{
		std::cout << "grade 0:" << std::endl;
		Bureaucrat wrong("wrong", 0);
		std::cout << wrong << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "grade 151:" << std::endl;
		Bureaucrat wrong2("wrong2", 151);
		std::cout << wrong2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "grade -42:" << std::endl;
		Bureaucrat wrong3("wrong3", -42);
		std::cout << wrong3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "grade 4200:" << std::endl;
		Bureaucrat wrong2("wrong2", 4200);
		std::cout << wrong2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Increment/Decrement test" << std::endl;
	try
	{
		Bureaucrat inc("Inc", 42);
		std::cout << "Before increment: " << inc << std::endl;
		inc.incrementGrade();
		std::cout << "After increment: " << inc << std::endl;
		std::cout << "Before decrement: " << inc << std::endl;
		inc.decrementGrade();
		std::cout << "After decrement: " << inc << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
