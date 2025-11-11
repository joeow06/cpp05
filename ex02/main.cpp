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
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << "---------- Test 1 ----------" << std::endl;
	try
	{
		Bureaucrat joe("Joe", 6);
		std::cout << joe << std::endl;
		Form ptptn("PTPTN", 60, 60);
		std::cout << ptptn << std::endl;
		joe.signForm(ptptn);
		std::cout << ptptn << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------- Test 2 ----------" << std::endl;
	try
	{
		Bureaucrat ali("Ali", 61);
		std::cout << ali << std::endl;
		Form mortgage("Mortgage", 60, 60);
		std::cout << mortgage << std::endl;
		ali.signForm(mortgage);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Test 3 ----------" << std::endl;
	try
	{
		Form random1("Random1", 0, 60);
		std::cout << random1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Test 4 ----------" << std::endl;
	try
	{
		Form random2("Random2", 60, -42);
		std::cout << random2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Test 5 ----------" << std::endl;
	try
	{
		Form random3("Random3", 1000, 60);
		std::cout << random3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Test 6 ----------" << std::endl;
	try
	{
		Form random4("Random4", 60, 1000);
		std::cout << random4 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Test 7 ----------" << std::endl;
	try
	{
		Form original("Original", 10, 60);
		std::cout << original << std::endl;
		Form copy(original);
		std::cout << copy << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Test 8 ----------" << std::endl;
	try
	{
		Form good("Good", 42, 42);
		std::cout << good << std::endl;
		Form bad("Bad", 11, 11);
		std::cout << bad << std::endl;

		bad = good;
		std::cout << bad << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Test 9 ----------" << std::endl;
	try
	{
		Form defaultForm;
		std::cout << defaultForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}
