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

int main(void)
{
	std::cout << "---------- Test 1 ----------" << std::endl;
	try
	{
		Bureaucrat joe("Joe", 6);
		std::cout << joe << std::endl;
		Form ptptn("PTPTN", 67, 67);
		std::cout << ptptn << std::endl;
		joe.signForm(ptptn);
		std::cout << ptptn << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
