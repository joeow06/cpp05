/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 02:29:26 by jow               #+#    #+#             */
/*   Updated: 2025/10/30 02:29:27 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
       ~Bureaucrat();
       Bureaucrat(const Bureaucrat &other);
       Bureaucrat& operator=(const Bureaucrat &other);

       Bureaucrat(std::string name, int grade);
       const std::string getName() const;
       int getGrade() const;
       void incrementGrade();
       void decrementGrade();
       void signForm(AForm &form);

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

std::ostream& operator<<(std::ostream &out, Bureaucrat const &a);

#endif
